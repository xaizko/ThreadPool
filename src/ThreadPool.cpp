#include "ThreadPool.hpp"
#include <functional>
#include <mutex>

ThreadPool::ThreadPool(size_t numThreads) {
	for (int i = 0; i < numThreads; i++) {
		workers.push_back(
					std::thread([this]() {
						while(true) {
							std::function<void()> task;

							{
								std::unique_lock<std::mutex> lock(queueMutex);

								cv.wait(lock, [this]{
											return stopPool || !tasks.empty();
										});

								if (stopPool && tasks.empty()) {
									return;
								}

								task = std::move(tasks.front());
								tasks.pop();
							}

							task();
						}
					})
				);
	}
}

ThreadPool::~ThreadPool() {
	{
		std::unique_lock<std::mutex> lock(queueMutex);
		stopPool = true;
	}
	cv.notify_all();

	for (std::thread &worker : workers) {
		if (worker.joinable()) {
			worker.join();
		}
	}
}

void ThreadPool::enqueue(std::function<void()> task) {
	{
		std::unique_lock<std::mutex> lock(queueMutex);
		tasks.push(task);
	}
	cv.notify_one();
}

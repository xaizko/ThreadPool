#include "ThreadPool.hpp"
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

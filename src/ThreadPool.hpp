#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
	public:
		// Create pool with fixed number of threads
		ThreadPool(size_t numThreads);

		void enqueue(std::function<void()> task);

		~ThreadPool();

	private:
		std::vector<std::thread> workers;

		std::queue<std::function<void()>> tasks;

		std::mutex queueMutex;
		std::condition_variable cv;
		bool stopPool = false;
};

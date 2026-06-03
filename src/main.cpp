#include "ThreadPool.hpp"
#include <iostream>
#include <chrono>

int main() {
	ThreadPool pool(4);
	std::cout << "Thread Pool initialized with 4 threads.\n";

	for (int i = 0; i < 10; ++i) {
		pool.enqueue([i]() {
					std::cout << "Task " << i << " starting on thread: " << std::this_thread::get_id() << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));

					std::cout << "Task " << i << " completed!\n";
				});
	}

	std::cout << "Tasks completed successfully\n";

	return 0;
}

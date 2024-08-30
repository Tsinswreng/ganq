// #include <iostream>
// #include <vector>
// #include <thread>
// #include <queue>
// #include <functional>
// #include <condition_variable>
// #include <future>
// #include <atomic>

// class ThreadPool {
// public:
// 	ThreadPool(size_t numThreads);
// 	~ThreadPool();

// 	template<class F>
// 	auto enqueue(F&& f) -> std::future<typename std::result_of<F()>::type>;

// private:
// 	std::vector<std::thread> workers;
// 	std::queue<std::function<void()>> tasks;

// 	std::mutex queueMutex;
// 	std::condition_variable condition;
// 	std::atomic<bool> stop;
// };

// ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
// 	for (size_t i = 0; i < numThreads; ++i) {
// 		workers.emplace_back([this] {
// 			for (;;) {
// 				std::function<void()> task;

// 				{
// 					std::unique_lock<std::mutex> lock(this->queueMutex);
// 					this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
// 					if (this->stop && this->tasks.empty()) {
// 						return;
// 					}
// 					task = std::move(this->tasks.front());
// 					this->tasks.pop();
// 				}

// 				task();
// 			}
// 		});
// 	}
// }

// ThreadPool::~ThreadPool() {
// 	{
// 		std::unique_lock<std::mutex> lock(queueMutex);
// 		stop = true;
// 	}
// 	condition.notify_all();
// 	for (std::thread &worker : workers) {
// 		worker.join();
// 	}
// }

// template<class F>
// auto ThreadPool::enqueue(F&& f) -> std::future<typename std::result_of<F()>::type> {
// 	using return_type = typename std::result_of<F()>::type;

// 	auto task = std::make_shared<std::packaged_task<return_type()>>(std::forward<F>(f));
// 	std::future<return_type> res = task->get_future();

// 	{
// 		std::unique_lock<std::mutex> lock(queueMutex);
// 		if (stop) {
// 			throw std::runtime_error("enqueue on stopped ThreadPool");
// 		}
// 		tasks.emplace([task]() { (*task)(); });
// 	}

// 	condition.notify_one();
// 	return res;
// }

// int main() {
// 	ThreadPool pool(4); // 创建一个包含 4 个线程的线程池

// 	// 提交任务到线程池
// 	auto result1 = pool.enqueue([] {
// 		std::this_thread::sleep_for(std::chrono::seconds(1));
// 		return 1;
// 	});

// 	auto result2 = pool.enqueue([] {
// 		std::this_thread::sleep_for(std::chrono::seconds(2));
// 		return 2;
// 	});

// 	std::cout << "Result 1: " << result1.get() << std::endl; // 获取结果
// 	std::cout << "Result 2: " << result2.get() << std::endl; // 获取结果

// 	return 0;
// }

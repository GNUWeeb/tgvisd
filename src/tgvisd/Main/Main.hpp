// SPDX-License-Identifier: GPL-2.0
/*
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license GPL-2.0
 * @package tgvisd::Main
 *
 * Copyright (C) 2021 Ammar Faizi <ammarfaizi2@gmail.com>
 */

#ifndef TGVISD__MAIN__MAIN_HPP
#define TGVISD__MAIN__MAIN_HPP

#include <stack>
#include <tgvisd/Td/Td.hpp>

namespace tgvisd::Main {

class Worker;

class Main {

public:
	Worker *threads = nullptr;

	Main(uint32_t api_id, const char *api_hash, const char *data_path);
	~Main(void);
	void run(void);
	int64_t freeThreadIndex(uint32_t idx);
	int64_t getFreeThreadIndex(void);
	Worker *getFreeWorker(void);
	void addFreeWorker(Worker *thread);


	inline tgvisd::Td::Td *getTd(void)
	{
		return &td_;
	}
private:
	constexpr static size_t max_thread_num = 128;

	tgvisd::Td::Td td_;

	/* Mutex to lock the stack below. */
	std::mutex workerStackMutex_;

	/* It saves the free thread indexes. */
	std::stack<uint32_t> workerStack_;

	void spawnThreads(void);
};

} /* namespace tgvisd::Main */

#endif /* #ifndef TGVISD__MAIN__MAIN_HPP */

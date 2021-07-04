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
	Main(uint32_t api_id, const char *api_hash, const char *data_path);
	~Main(void);
	void run(void);

	Worker *getPrimaryWorker(void);
	void putPrimaryWorker(Worker *worker);

	Worker *getExtraWorker(void);
	void putExtraWorker(Worker *worker);


	inline tgvisd::Td::Td *getTd(void)
	{
		return &td_;
	}

	inline bool stopUpdate(void)
	{
		return stopUpdate_;
	}

private:
	tgvisd::Td::Td td_;
	uint32_t maxWorkerNum_;
	uint32_t hardwareConcurrency_;
	Worker *threads_ = nullptr;

	bool stopUpdate_ = false;

	std::mutex primaryWorkerStackMutex;
	std::stack<uint32_t> primaryWorkerStack;

	std::mutex extraWorkerStackMutex;
	std::stack<uint32_t> extraWorkerStack;

	void spawnThreads(void);
};

} /* namespace tgvisd::Main */

#endif /* #ifndef TGVISD__MAIN__MAIN_HPP */
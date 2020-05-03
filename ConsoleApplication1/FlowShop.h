#pragma once
#include "stdafx.h"
#include "Job.h"
#include <queue>
#include "ComparePicking.h"
#include "CompareBufer.h"
#include "ComparePacking.h"
#include <string>
#include <iostream>

template<typename T, typename Container = std::vector<T>, class Pr = less<typename Container::value_type> >
class iterable_queue : public std::priority_queue<T, Container, Pr>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

class FlowShop
{
private:
	std::queue<Job> input;
	iterable_queue<Job, std::vector<Job>, ComparePicking> picking;
	iterable_queue<Job, std::vector<Job>, CompareBufer> bufer;
	iterable_queue<Job, std::vector<Job>, ComparePacking> packing;
	std::queue<Job> output;
	int pickingSize = 3;
	int buferSize = 3;
	int time = 0;
	int packingSize = 3;
	int count = 200;
public:
	FlowShop();
	void pushPicking(Job j);
	void toString();
	void popPicking();
	const Job& topPicking() const;
	bool emptyPicking();
	int sizePicking();
	int getTime();
	int getPickingSize();
	void setTime(int t);
	void setPickingCompleted(int t);
	void setPackingCompleted(int t);
	void insertNewJobPicking();
	void pushInput(Job j);
	void replaceJobToBuffer();
	void replaceJobToPacking();
	void replaceJobToOutput();
	void setMinimumTime();
	void run();
	void setCount(int cou);
	~FlowShop();
};


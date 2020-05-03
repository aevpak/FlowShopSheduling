#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;
class Job {
private:
	string name;
	int timeForPick;
	int timeForPack;
	bool blocked;
	int timeComeToPick;
	int timeComeToPack;
	int timeComeToBuf;
	int timeComeFromPick;
	int timeComeFromPack;
	int timeComeFromBuf;
	bool pickingCompleted;
	bool packingCompleted;
public:
	Job();
	Job(string name1, int timeForPick1, int timeForPack1);
	int getTimeForPick();
	int getTimeForPack();
	string getName();
	bool getBlocked();
	int getTimeComeToPick();
	int getTimeComeToPack();
	int getTimeComeToBuf();
	int getTimeComeFromPick();
	int getTimeComeFromPack();
	int getTimeComeFromBuf();
	void setName(string name1);
	void setTimeForPick(int time);
	void setTimeForPack(int time);
	void setBlocked(bool isBlocked);
	void setTimeComeToPick(int time);
	void setTimeComeToPack(int time);
	void setTimeComeToBuf(int time);
	void setTimeComeFromPick(int time);
	void setTimeComeFromPack(int time);
	void setTimeComeFromBuf(int time);
	void setPickingCompleted(bool isCompleted);
	bool getPickingCompleted() const;
	void setPackingCompleted(bool isCompleted);
	bool getPackingCompleted() const;
	Job(const Job &orig);
	Job& operator=(Job &orig);
	void toString() const;
	~Job();
};
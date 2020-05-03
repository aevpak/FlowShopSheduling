#include <iostream>
#include "stdafx.h"
#include <string>
using namespace std;
#include "Job.h"
	Job::Job() {
		timeForPick = 0;
		timeForPack = 0;
		blocked = false;
		timeComeToPick = 0;
		timeComeToPack = 0;
		timeComeToBuf = 0;
		timeComeFromPick = 0;
		timeComeFromPack = 0;
		timeComeFromBuf = 0;
		pickingCompleted = false;
		packingCompleted = false;
	}
	Job::Job(string name1, int timeForPick1, int timeForPack1) {
		name = name1;
		timeForPick = timeForPick1;
		timeForPack = timeForPack1;
		blocked = false;
		timeComeToPick = 0;
		timeComeToPack = 0;
		timeComeToBuf = 0;
		timeComeFromPick = 0;
		timeComeFromPack = 0;
		timeComeFromBuf = 0;
		pickingCompleted = false;
		packingCompleted = false;
	}
	int Job::getTimeForPick() {
		return this->timeForPick;
	}
	int Job::getTimeForPack() {
		return this->timeForPack;
	}
	string Job::getName() {
		return this->name;
	}
	void Job::setTimeForPick(int time) {
		this->timeForPick = time;
	}
	bool Job::getBlocked() {
		return this->blocked;
	}
	int Job::getTimeComeToPick() {
		return this->timeComeToPick;
	}
	int Job::getTimeComeToPack() {
		return this->timeComeToPack;
	}
	int Job::getTimeComeToBuf() {
		return this->timeComeToBuf;
	}
	int Job::getTimeComeFromPick() {
		return this->timeComeFromPick;
	}
	int Job::getTimeComeFromPack() {
		return this->timeComeFromPack;
	}
	int Job::getTimeComeFromBuf() {
		return this->timeComeFromBuf;
	}
	void Job::setName(string name1) {
		this->name = name1;
	}
	void Job::setTimeForPack(int time) {
		this->timeForPack = time;
	}
	void Job::setBlocked(bool isBlocked) {
		this->blocked = isBlocked;
	}
	void Job::setTimeComeToPick(int time) {
		this->timeComeToPick = time;
	}
	void Job::setTimeComeToPack(int time) {
		this->timeComeToPack = time;
	}
	void Job::setTimeComeToBuf(int time) {
		this->timeComeToBuf = time;
	}
	void Job::setTimeComeFromPick(int time) {
		this->timeComeFromPick = time;
	}
	void Job::setTimeComeFromPack(int time) {
		this->timeComeFromPack = time;
	}
	void Job::setTimeComeFromBuf(int time) {
		this->timeComeFromBuf = time;
	}
	Job::Job(const Job &orig) {
		name = orig.name;
		timeForPick = orig.timeForPick;
		timeForPack = orig.timeForPack;
		blocked = orig.blocked;
		timeComeToPick = orig.timeComeToPick;
		timeComeToPack = orig.timeComeToPack;
		timeComeToBuf = orig.timeComeToBuf;
		timeComeFromPick = orig.timeComeFromPick;
		timeComeFromPack = orig.timeComeFromPack;
		timeComeFromBuf = orig.timeComeFromBuf;
		pickingCompleted = orig.pickingCompleted;
		packingCompleted = orig.packingCompleted;
	}
	Job& Job::operator=(Job &orig) {
		if (this == &orig) {
			return *this;
		}
		name = orig.name;
		timeForPick = orig.timeForPick;
		timeForPack = orig.timeForPack;
		blocked = orig.blocked;
		timeComeToPick = orig.timeComeToPick;
		timeComeToPack = orig.timeComeToPack;
		timeComeToBuf = orig.timeComeToBuf;
		timeComeFromPick = orig.timeComeFromPick;
		timeComeFromPack = orig.timeComeFromPack;
		timeComeFromBuf = orig.timeComeFromBuf;
		pickingCompleted = orig.pickingCompleted;
		packingCompleted = orig.packingCompleted;
		return *this;
	}
	void Job::toString() const {
		cout 
			<< "name "<< name << endl
			<< "timeForPick "<< timeForPick << endl
			<< "timeForPack "<< timeForPack << endl
			<< "blocked "<< blocked << endl
			<< "timeComeToPick "<< timeComeToPick << endl
			<< "timeComeToPack "<< timeComeToPack << endl
			<< "timeComeToBuf "<< timeComeToBuf << endl
			<< "timeComeFromPick "<< timeComeFromPick << endl
			<< "timeComeFromPack "<< timeComeFromPack << endl
			<< "timeComeFromBuf "<< timeComeFromBuf << endl
			<< "pickingCompleted " << pickingCompleted << endl
			<< "packingCompleted "<< packingCompleted << endl << endl;
	}
	void Job::setPickingCompleted(bool isCompleted) {
		this->pickingCompleted = isCompleted;
	}
	bool Job::getPickingCompleted() const {
		return pickingCompleted;
	}
	void Job::setPackingCompleted(bool isCompleted) {
		this->packingCompleted = isCompleted;
	}
	bool Job::getPackingCompleted() const {
		return packingCompleted;
	}
	Job::~Job() {
	}

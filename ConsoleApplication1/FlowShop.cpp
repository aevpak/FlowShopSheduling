#include "stdafx.h"
#include "FlowShop.h"
#include <string>
#include <iostream>

FlowShop::FlowShop()
{
}

void FlowShop::pushPicking(Job j) {
	picking.push(j);
}
void FlowShop::toString() {
	std::cout << "Input: " << endl;
	if (!input.empty()) {
		std::queue<Job> copy = input;
		while (!copy.empty()) {
			copy.front().toString();
			copy.pop();
		}
	}
	std::cout << "Picking: " << endl;
	if (!picking.empty()) {
		for (auto it = picking.begin(); it != picking.end(); ++it)
			it->toString();
	}
	std::cout << "Bufer: " << endl;
	if (!bufer.empty()) {
		for (auto it = bufer.begin(); it != bufer.end(); ++it)
			it->toString();
	}
	std::cout << "Packing: " << endl;
	if (!packing.empty()) {
		for (auto it = packing.begin(); it != packing.end(); ++it)
			it->toString();
	}
	std::cout << "Output: " << endl;
	if (!output.empty()) {
		std::queue<Job> copy = output;
		while (!copy.empty()) {
			copy.front().toString();
			copy.pop();
		}
	}
	std::cout << endl;

}
void FlowShop::popPicking() {
	picking.pop();
}
const Job& FlowShop::topPicking() const {
	return picking.top();
}
bool FlowShop::emptyPicking() {
	return picking.empty();
}
int FlowShop::sizePicking() {
	return picking.size();
}
int FlowShop::getTime() {
	return time;
}
int FlowShop::getPickingSize() {
	return pickingSize;
}
void FlowShop::setTime(int t) {
	this->time = t;
}
void FlowShop::setPickingCompleted(int t) {
	/*for (auto it = picking.begin(); it != picking.end(); ++it)
		if(t >= it->getTimeComeToPick() + it->getTimeForPick()) it->setPickingCompleted(true);*/
	iterable_queue<Job, std::vector<Job>, ComparePicking> copy;
	while (!picking.empty()) {
		Job j = picking.top();
		if (t >= j.getTimeComeToPick() + j.getTimeForPick()) {
			j.setPickingCompleted(true);
		}
		copy.push(j);
		picking.pop();
	}
	picking = copy;
}
void FlowShop::setPackingCompleted(int t) {
	/*for (auto it = packing.begin(); it != packing.end(); ++it)
		if (t >= it->getTimeComeToPack() + it->getTimeForPack()) it->setPackingCompleted(true);*/
	iterable_queue<Job, std::vector<Job>, ComparePacking> copy;
	while (!packing.empty()) {
		Job j = packing.top();
		if (t >= j.getTimeComeToPack() + j.getTimeForPack()) {
			j.setPackingCompleted(true);
		}
		copy.push(j);
		packing.pop();
	}
	packing = copy;
}
void FlowShop::insertNewJobPicking() {
	while (!input.empty() && (picking.size() < pickingSize)) {
		Job j = input.front();
		j.setTimeComeToPick(time);
		picking.push(j);
		input.pop();
	}
}
void FlowShop::pushInput(Job j) {
	input.push(j);
}
void FlowShop::replaceJobToBuffer() {
	for (auto it = picking.begin(); it != picking.end(); ++it)
		it->setBlocked(false);
	while(!picking.empty() && picking.top().getPickingCompleted() && (bufer.size() < buferSize)){
		Job j = picking.top();
		j.setTimeComeFromPick(time);
		j.setTimeComeToBuf(time);
		bufer.push(j);
		picking.pop();
	}
	if (bufer.size() == buferSize && !picking.empty()) {
		for (auto it = picking.begin(); it != picking.end(); ++it)
			if(it->getPickingCompleted()) it->setBlocked(true);
	}

}
void FlowShop::replaceJobToPacking() {
	while (!bufer.empty() && (packing.size() < packingSize)) {
		Job j = bufer.top();
		j.setTimeComeFromBuf(time);
		j.setTimeComeToPack(time);
		packing.push(j);
		bufer.pop();
	}
}
void FlowShop::replaceJobToOutput() {
	while (!packing.empty() && packing.top().getPackingCompleted()) {
		Job j = packing.top();
		j.setTimeComeFromPack(time);
		output.push(j);
		packing.pop();
	}
}
void FlowShop::setMinimumTime() {
	int t1 = -1, t2 = -1;
	if (!picking.empty()) { 
		Job j1 = picking.top();
		if(!j1.getBlocked()) t1 = j1.getTimeComeToPick() + j1.getTimeForPick();
	}
	if (!packing.empty()) {
		Job j1 = packing.top();
		t2 = j1.getTimeComeToPack() + j1.getTimeForPack();
	}
	if (t1 != -1 && t2 != -1) {
		if (t1 < t2 && t1 >= time) time = t1;
		if (t1 >= t2 && t2 >= time) time = t2;
	}
	if (t1 == -1) {
		if (t2 >= time) time = t2;
	}
	if (t2 == -1) {
		if (t1 >= time) time = t1;
	}		
}
void FlowShop::run() {
	while (output.size() != count) {
		setPackingCompleted(time);
		setPickingCompleted(time);
		replaceJobToOutput();
		replaceJobToPacking();
		replaceJobToBuffer();
		replaceJobToPacking();
		if(!input.empty()) insertNewJobPicking();
		setMinimumTime();
		//toString();
	}
	//toString();
}
void FlowShop::setCount(int cou) {
	count = cou;
}
FlowShop::~FlowShop()
{
}

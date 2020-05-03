#include "stdafx.h"
#include "Job.h"
#include "ComparePicking.h"
bool ComparePicking::operator() (Job j1, Job j2)//return least
{
	if (j1.getPickingCompleted() && j2.getPickingCompleted()) {
		return j1.getTimeForPack() > j2.getTimeForPack();
	}
	if (!j1.getPickingCompleted() && !j2.getPickingCompleted()) {
		return j1.getTimeForPick() > j2.getTimeForPick();
	}
	if (j2.getPickingCompleted()) return true; 
	return false;
}
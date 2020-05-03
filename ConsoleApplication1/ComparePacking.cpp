#include "stdafx.h"
#include "ComparePacking.h"
#include "Job.h"

bool ComparePacking::operator() (Job j1, Job j2)//return least
{
	if (j1.getPackingCompleted() && j2.getPackingCompleted()) {
		return j1.getTimeForPack() > j2.getTimeForPack();
	}
	if (!j1.getPackingCompleted() && !j2.getPackingCompleted()) {
		return j1.getTimeForPack() > j2.getTimeForPack();
	}
	if (j2.getPackingCompleted()) return true;
	return false;
}

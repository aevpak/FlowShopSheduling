#include "stdafx.h"
#include "CompareBufer.h"
#include "Job.h"

bool CompareBufer::operator() (Job j1, Job j2)//return least
{
	return j1.getTimeForPack() > j2.getTimeForPack();
}
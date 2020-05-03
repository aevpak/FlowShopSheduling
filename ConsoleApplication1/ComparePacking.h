#pragma once
#include "stdafx.h"
#include "Job.h"
class ComparePacking
{
public:
	bool operator() (Job j1, Job j2);
};


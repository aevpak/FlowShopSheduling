#pragma once
#include "stdafx.h"
#include "Job.h"
class ComparePicking
{
public:
	bool operator() (Job j1, Job j2);
};
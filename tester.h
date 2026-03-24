// tester.h
// testing file

#pragma once
#include <vector>
#include "shared_types.h"

std::vector<LapRecord> buildFakeRecords(int howMany);
bool checkInsertAndSearchWork();
bool checkCollisionCountingWorks();
bool checkBothTablesAgreeOnSearches(const std::vector<LapRecord>& someRealData);
void runAllTests(const std::vector<LapRecord>& someRealData);
// tester.h

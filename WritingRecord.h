/*
 ===================================================
				 WORKSHOP #7 PART 1 and 2
 ===================================================
 NAME   : Maaz Saiyed
 SID    : 113485205
 EMAIL  : mmmsaiyed@myseneca.ca
 SECTION: ZAA
 DATE   : 28  MAR 2022

*/

#pragma once
#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include "GeneratingList.h"
#include "EmpProfile.h"

namespace sdds
{
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}


#endif // SDDS_WRITINGRECORD_H


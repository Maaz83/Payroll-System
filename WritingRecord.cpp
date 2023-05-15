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

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds
{
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal)
	{
		GeneratingList<EmployeeWage> activeEmp;

		for (unsigned int i = 0; i < emp.size(); i++)
		{

			for (unsigned int j = 0; j < sal.size(); j++)
			{

				if (emp[i].id == sal[j].id)
				{
					EmployeeWage* empWage = new EmployeeWage(emp[i].name, sal[j].salary);

					if (!activeEmp.luhnAlgorithm(emp[i].id))
					{
						delete empWage;
						throw std::string("*** This is not a valid sin number!");
					}
					else
					{
						try
						{
							empWage->rangeValidator();
						}
						catch (std::string err)
						{
							delete empWage;
							throw std::string(err);
						}
					}

					activeEmp += empWage;
					delete empWage;
				}
			}
		}


		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal)
	{
		GeneratingList<EmployeeWage> activeEmp;

		for (unsigned int i = 0; i < emp.size(); i++)
		{

			for (unsigned int j = 0; j < sal.size(); j++)
			{

				if (emp[i].id == sal[j].id)
				{
					std::unique_ptr<EmployeeWage> empWage = std::make_unique<EmployeeWage>(emp[i].name, sal[j].salary);

					if (!activeEmp.luhnAlgorithm(emp[i].id))
					{
						throw std::string("*** This is not a valid sin number!");
					}
					else
					{
						empWage.get()->rangeValidator();
					}

					activeEmp += empWage;
				}
			}
		}

		return activeEmp;
	}
}
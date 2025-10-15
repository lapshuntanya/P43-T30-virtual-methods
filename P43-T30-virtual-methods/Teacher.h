#pragma once
#include "Employee.h"
class Teacher :   public Employee
{
protected:
	float cost;
	int hours;
public:
	Teacher();
	Teacher(string name, float salary, float cost, int hours);

	void setCost(float cost);
	void setHours(int hours);

	float getCost()const;
	int getHours()const;

	void showInfo() const;
	float calcSalary()const;
};


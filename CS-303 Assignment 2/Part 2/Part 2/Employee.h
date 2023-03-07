#ifndef EMPLOYEE_H
#define EMPLOYEE_H

/*
* Has a default constructor and a virtual destructor,
* as well as three pure virtual functions.
* Means it is an abstract class and cannot be instantiated.
*/
class Employee {
public:
	Employee();
	virtual ~Employee();
	virtual double calculateWeeklySalary() const = 0;
	virtual double calculateHealthCareContributions() const = 0;
	virtual int calculateVacationDays() const = 0;

protected:
	double m_hourlyRate;
	double m_healthCarePercentage;
	int m_vacationDays;
};

/*
* Derived from the Employee class.
* Has a constructor that takes an hourly rate and
* vacation days as arguments.
* Overrides the three pure virtual functions from the base class
* with its own implementations.
*/
class Professional : public Employee {
public:
	Professional(double hourlyRate, int vacationDays);
	virtual ~Professional();
	virtual double calculateWeeklySalary() const override;
	virtual double calculateHealthCareContributions() const override;
	virtual int calculateVacationDays() const override;
};

/*
* Derived from the Employee class and has a constructor
* that takes an hourly rate and vacation hours as arguments.
* Overrides the three pure virtual functions from the base class
* with its own implementations.
*/
class Nonprofessional : public Employee {
public:
	Nonprofessional(double hourlyRate, int vacationHours);
	virtual ~Nonprofessional();
	virtual double calculateWeeklySalary() const override;
	virtual double calculateHealthCareContributions() const override;
	virtual int calculateVacationDays() const override;

private:
	int m_vacationHours;
};

#endif 

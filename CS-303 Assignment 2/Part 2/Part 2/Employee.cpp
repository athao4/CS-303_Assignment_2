#include "Employee.h"

Employee::Employee()
	: m_hourlyRate(0.0), m_healthCarePercentage(0.0), m_vacationDays(0)
{}

Employee::~Employee() {}

Professional::Professional(double hourlyRate, int vacationDays)
	: Employee()
{
	m_hourlyRate = hourlyRate;
	m_vacationDays = vacationDays;
	// initialize health care percentage in the Employee class
	m_healthCarePercentage = 0.1;
}

Professional::~Professional()
{}

double Professional::calculateWeeklySalary() const
{
	// assuming 40 hours/week and 4 weeks/month
	return m_hourlyRate * 40 * 4;
}

double Professional::calculateHealthCareContributions() const
{
	return calculateWeeklySalary() * m_healthCarePercentage;
}

int Professional::calculateVacationDays() const
{
	return m_vacationDays;
}

Nonprofessional::Nonprofessional(double hourlyRate, int vacationHours)
	: m_vacationHours(vacationHours)
{
	m_hourlyRate = hourlyRate;
	m_healthCarePercentage = 0.05; // 5% contribution for healthcare
	m_vacationDays = vacationHours / 8; // assuming 8 hours/day
}

Nonprofessional::~Nonprofessional()
{}

double Nonprofessional::calculateWeeklySalary() const
{
	return m_hourlyRate * 40; // assuming 40 hours/week
}

double Nonprofessional::calculateHealthCareContributions() const
{
	return calculateWeeklySalary() * m_healthCarePercentage;
}

int Nonprofessional::calculateVacationDays() const
{
	return m_vacationDays;
}

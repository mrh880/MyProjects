#pragma once

#include "Structures.h"
#include "Enums.h"

#include <string>
#include <vector>

bool isYearLeap(short Year);

short NumberOfDaysInYear(short Year);

short NumberOfHoursInYear(short Year);

int NumberOfMinutesInYear(short Year);

int NumberOfSecondsInYear(short Year);

short NumberOfDaysInMonth(short Month, short Year);

short NumberOfHoursInMonth(short Month, short Year);

int NumberofMinutesInMonth(short Month, short Year);

int NumberofSecondsInMonth(short Month, short Year);

void PrintDate(short Day, short Month, short Year);

void PrintDate(stDate &Date);

void PrintDate(stDate &Date, char Delemiter);

void PrintDateAndDay(stDateAndDay DateAndDAym, char Delemiter);

stDateAndDay GetCurrentDateAndCurrentDayInText();

short CalculateDayOrder(short Year, short Month, short Day);

short CalculateDayOrder(stDate Date);

short CalculateDayOrder(stDateAndDay Date);

std::string DayOrderName(short DayOrder);

std::string ConvertMonthIntoText(short NumberOfMonth);

void PrintMonthCalender(short Month, short Year);

void PrintYearCalender(short Year);

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year);

stDate GetDateFromNumberOfDays(short NumberOfDays, short Year);

void ReadDate(stDate &Date);

bool isDate1LessThanDate2(stDate &Date1, stDate &Date2);

bool isDate1EqualsToDate2(stDate &Date1, stDate &Date2);

bool isLastDayInMonth(stDate &Date);

bool isLastMonthInYear(short Month);

stDate IncreaseDateByOneDay(stDate &Date);

void SwappingTwoDates(stDate &Date1, stDate &Date2);

int GetDifferentBetweenTwoDates(stDate Date1, stDate Date2, bool isEndDayIncluded = false);

stDate GetSystemDate();

int AgeInNumberOfDays(stDate PersonDate);

stDate IncreaseDateByXDayes(stDate Date, int NumberOfDays);

stDate IncreaseDateByOneWeek(stDate Date);

stDate IncreaseDateByXWeeks(stDate Date, int NumberOfWeeks);

stDate IncreaseDateByOneMonth(stDate Date);

stDate IncreaseDateByXMonths(stDate Date, int NumberOfMonths);

stDate IncreaseDateByOneYear(stDate Date);

stDate IncreaseDateByXYears(stDate Date, int NumberOfYears);

stDate IncreaseDateByXYearsFaster(stDate Date, int NumberOfYears);

stDate IncreaseDateByOneDecade(stDate Date);

stDate IncreaseDateByXDecades(stDate Date, int NumberOfDecades);

stDate IncreaseDateByXDecadesFaster(stDate Date, int NumberOfDecades);

stDate IncreaseDateByOneCentury(stDate Date);

stDate IncreaseDateByOneMillennium(stDate Date);

bool isFirstDayInMonth(short Day);

bool isFirstMonthInYear(short Month);

stDate DecreaseDateByOneDay(stDate Date);

stDate DecreaseDateByXDays(stDate Date, int NumberOfDays);

stDate DecreaseDateByOneWeek(stDate Date);

stDate DecreaseDateByXWeeks(stDate Date, int NumberOfWeeks);

stDate DecreaseDateByOneMonth(stDate Date);

stDate DecreaseDateByXMonths(stDate Date, int NumberOfMonth);

stDate DecreaseDateByOneYear(stDate Date);

stDate DecreaseDateByXYears(stDate Date, int NumberOfYears);

stDate DecreaseDateByXYearsFaster(stDate Date, int NumberOfYears);

stDate DecreaseDateByOneDecade(stDate Date);

stDate DecreaseDateByXDecades(stDate Date, int NumberOfDecades);

stDate DecreaseDateByXDecadesFaster(stDate Date, int NumberOfDecades);

stDate DecreaseDateByOneCentury(stDate Date);

stDate DecreaseDateByOneMillennium(stDate Date);

bool isEndOfWeek(stDate Date);

bool isWeekEnd(stDate Date);

bool isBusinessDay(stDate Date);

short DaysUntilTheEndOfTheWeek(stDate Date);

short DaysUntilTheEndOfTheWeek(stDateAndDay Date);

short DaysUntilTheEndOfTheMonth(stDate Date, bool isEndDayIncluded = false);

short DaysUntilTheEndOfTheMonth(stDateAndDay Date, bool isEndDayIncluded = false);

short DaysUntilTheEndOfTheYear(stDate Date);

short DaysUntilTheEndOfTheYear(stDateAndDay Date);

void PrintIfIsEndOfTheWeek();

void PrintIfWeekEnd();

void PrintIfItIsBusinessDay();

short CalculateVacationDays(stDate DateFrom, stDate DateTo);

stDate CalculateVacationReturnDate(stDate DateFrom, short NumberOfDays);

bool isDate1AfterDate2(stDate Date1, stDate Date2);

enDateCompareDates CompreTwoDates(stDate Date1, stDate Date2);

void ReadPeriod(stPeriod &Period);

bool isOverLapPeriods(stPeriod Period1, stPeriod Period2);

int PeriodLengthInDays(stPeriod Period, bool isEndDayIncluded = false);

bool isDateInPeriod(stPeriod Period, stDate Date);

int CountOverlapDays(stPeriod Period1, stPeriod Period2);

bool isMonthValid(short Month);

bool isDayInMonthValid(stDate &Date);

bool isDateValid(stDate &Date);

std::string ReadDateInstring(std::string DateFormat = "");

void FillDateIntoStructure(std::vector<std::string> &DateString, stDate &Date);    

stDate ConvertDateFromStringToStructure(std::string StringDate, std::string Delemiter);

std::string FormatDate(stDate Date, std::string DateFormat = "dd/mm/yyyy", const std::string Delemiter = "/");


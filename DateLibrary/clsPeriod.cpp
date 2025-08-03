#include "clsPeriod.h"

#include "clsDate.h"
#include "PrintingOutputsLibrary/PrintingOutputs.h"

#include <iostream>
#include <string>

using namespace std;

// Set Method
// -------------------------------------------------------------------------------------------
void clsPeriod::SetPeriod(const clsDate &Period1, const clsDate &Period2)
{
    _StartDate = Period1;
    _EndDate = Period2;
}
// -------------------------------------------------------------------------------------------

// Get Method
// -------------------------------------------------------------------------------------------

 clsDate clsPeriod::StartDate() 
{
    return _StartDate;
}

 clsDate clsPeriod::EndDate() 
{
    return _EndDate;
}
// -------------------------------------------------------------------------------------------

// Static Method
// -------------------------------------------------------------------------------------------

void clsPeriod::ReadPeriod(clsPeriod &Period, short Number)
{
    string MessageForStartDate = "Reading the start date for period " + to_string(Number);
    string MessageForEndDate = "Reading the end date for period " + to_string(Number);

    clsDate::ReadDate(Period._StartDate, MessageForStartDate);
    clsDate::ReadDate(Period._EndDate, MessageForEndDate);
}

bool clsPeriod::isOverLapPeriods(clsPeriod Period1, clsPeriod Period2)
{
    if (
        clsDate::CompreTwoDates(Period2.EndDate(), Period1.StartDate()) == enDateCompareDates::Before ||
        clsDate::CompreTwoDates(Period2.StartDate(), Period1.EndDate()) == enDateCompareDates::After)
    {
        return false;
    }
    return true;
}

int clsPeriod::PeriodLengthInDays(clsPeriod &Period, bool isEndDayIncluded)
{
    return clsDate::GetDifferentBetweenTwoDates(Period.StartDate(), Period.EndDate(), isEndDayIncluded);
}

bool clsPeriod::isDateInPeriod(clsPeriod &Period, clsDate &Date)
{
    //     return
    //    ( CompreTwoDates(Date, Period.StartDate) == enDateCompareDates::After
    //     ||
    //     CompreTwoDates(Date, Period.StartDate) == enDateCompareDates::Equal)
    //     &&
    //     ( CompreTwoDates(Date, Period.EndDate) == enDateCompareDates::Before
    //     ||
    //     CompreTwoDates(Date, Period.EndDate) == enDateCompareDates::Equal);
    return !(
        clsDate::CompreTwoDates(Date, Period.StartDate()) == Before ||
        clsDate::CompreTwoDates(Date, Period.EndDate()) == After);
}

int clsPeriod::CountOverlapDays(clsPeriod &Period1, clsPeriod &Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (!isOverLapPeriods(Period1, Period2))
    {
        return 0;
    }

    if (Period1Length < Period2Length)
    {
        while (clsDate::isDate1LessThanDate2(Period1._StartDate, Period1._EndDate))
        {
            if (isDateInPeriod(Period2, Period1._StartDate))
            {
                OverlapDays++;
            }
            Period1._StartDate = clsDate::IncreaseDateByOneDay(Period1._StartDate);
        }
    }

    else
    {
        while (clsDate::isDate1LessThanDate2(Period2._StartDate, Period2._EndDate))
        {
            if (isDateInPeriod(Period1, Period2._StartDate))
            {
                OverlapDays++;
            }
            Period2._StartDate = clsDate::IncreaseDateByOneDay(Period2._StartDate);
        }
    }

    return OverlapDays;
}
// -------------------------------------------------------------------------------------------

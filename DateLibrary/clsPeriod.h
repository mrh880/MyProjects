#pragma once

#include "clsDate.h"

class clsPeriod
{
private:
    clsDate _StartDate;
    clsDate _EndDate;

public:
    // Set Property
    // ---------------------------------------------------
    void SetPeriod(const clsDate &Period1, const clsDate &Period2);
    // ---------------------------------------------------

    // Get Property 
    // ---------------------------------------------------
     clsDate StartDate() ;

     clsDate EndDate() ;
    // ---------------------------------------------------



    // Static Method
    // --------------------------------------------------------------------------------------
    static void ReadPeriod(clsPeriod &Period, short Number);

    static bool isOverLapPeriods(clsPeriod Period1, clsPeriod Period2);

    static int PeriodLengthInDays(clsPeriod &Period, bool isEndDayIncluded = false);

    static bool isDateInPeriod(clsPeriod &Period, clsDate &Date);

    static int CountOverlapDays(clsPeriod &Period1, clsPeriod &Period2);
    // // --------------------------------------------------------------------------------------


    
};
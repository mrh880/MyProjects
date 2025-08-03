#pragma once

#include "EnumsLibrary/Enums.h"

#include <string>
#include <vector>

class clsDate
{

private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

    std::string _DayName = "";


public:

    clsDate();

    clsDate(const std::string &Date);

    clsDate(short Day, short Month, short Year);

    clsDate(short DayOrderInYear, short Year);

    
    // Set Property
    // ---------------------------------------------------
    void SetDay(short Day);

    void SetMonth(short Month);

    void SetYear(short Year);

    void SetDayName(const std::string &DayName);
    
    // ---------------------------------------------------

    // Get Property
    // ---------------------------------------------------
    short Day();

    short Month();

    short Year();

    std::string DayName();
        // ---------------------------------------------------

    // Static Method
    // ---------------------------------------------------------------------------------------------------------------------------------------------
    static bool isYearLeap(short Year);

    static short NumberOfDaysInYear(short Year);

    static short NumberOfHoursInYear(short Year);

    static int NumberOfMinutesInYear(short Year);

    static int NumberOfSecondsInYear(short Year);

    static short NumberOfDaysInMonth(short Month, short Year);

    static short NumberOfHoursInMonth(short Month, short Year);

    static int NumberofMinutesInMonth(short Month, short Year);

    static int NumberofSecondsInMonth(short Month, short Year);

    static void PrintDate(short Day, short Month, short Year);

    static void PrintDate(clsDate &Date);

    static void PrintDate(clsDate &Date, std::string Delemiter);

    static void PrintDateAndDay(clsDate &Date, std::string Delemiter);

    static void PrintDateAndDay();

    static clsDate GetSystemDate();
    
    static clsDate GetCurrentDateAndCurrentDayName();

    static short CalculateDayOrder(short Day, short Month, short Year);

    static short CalculateDayOrder(clsDate &Date);

    static std::string GetDayNameFromDayOrder(short DayOrder);

    static std::string ConvertMonthIntoText(short NumberOfMonth);

    static void PrintMonthCalender(short Month, short Year);

    static void PrintYearCalender(short Year);

    static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year);

    static short NumberOfDaysFromTheBeginingOfTheYear(clsDate &Date);

    static clsDate GetDateFromNumberOfDays(short NumberOfDays, short Year);

    static void ReadDate(clsDate &Date, const std::string &Message = "");

    static bool isDate1LessThanDate2(clsDate &Date1, clsDate &Date2);

    static bool isDate1EqualsToDate2(clsDate &Date1, clsDate &Date2);

    static bool isDate1AfterDate2(clsDate &Date1, clsDate &Date2);

    static bool isLastDayInMonth(clsDate &Date);

    static bool isLastMonthInYear(short Month);

    static clsDate IncreaseDateByOneDay(clsDate Date);

    static clsDate IncreaseDateByXDayes(clsDate Date, int NumberOfDays);

    static clsDate IncreaseDateByOneWeek(clsDate Date);

    static clsDate IncreaseDateByXWeeks(clsDate Date, int NumberOfWeeks);

    static clsDate IncreaseDateByOneMonth(clsDate Date);

    static clsDate IncreaseDateByXMonths(clsDate Date, int NumberOfMonths);

    static clsDate IncreaseDateByOneYear(clsDate Date);

    static clsDate IncreaseDateByXYears(clsDate Date, int NumberOfYears);

    static clsDate IncreaseDateByXYearsFaster(clsDate Date, int NumberOfYears);

    static clsDate IncreaseDateByOneDecade(clsDate Date);

    static clsDate IncreaseDateByXDecades(clsDate Date, int NumberOfDecades);

    static clsDate IncreaseDateByXDecadesFaster(clsDate Date, int NumberOfDecades);

    static clsDate IncreaseDateByOneCentury(clsDate Date);

    static clsDate IncreaseDateByOneMillennium(clsDate Date);

    static bool isFirstDayInMonth(short Day);

    static bool isFirstMonthInYear(short Month);

    static clsDate DecreaseDateByOneDay(clsDate Date);

    static clsDate DecreaseDateByXDays(clsDate Date, int NumberOfDays);

    static clsDate DecreaseDateByOneWeek(clsDate Date);

    static clsDate DecreaseDateByXWeeks(clsDate Date, int NumberOfWeeks);

    static clsDate DecreaseDateByOneMonth(clsDate Date);

    static clsDate DecreaseDateByXMonths(clsDate Date, int NumberOfMonth);

    static clsDate DecreaseDateByOneYear(clsDate Date);

    static clsDate DecreaseDateByXYears(clsDate Date, int NumberOfYears);

    static clsDate DecreaseDateByXYearsFaster(clsDate Date, int NumberOfYears);

    static clsDate DecreaseDateByOneDecade(clsDate Date);

    static clsDate DecreaseDateByXDecades(clsDate Date, int NumberOfDecades);

    static clsDate DecreaseDateByXDecadesFaster(clsDate Date, int NumberOfDecades);

    static clsDate DecreaseDateByOneCentury(clsDate Date);

    static clsDate DecreaseDateByOneMillennium(clsDate Date);

    static void SwappingTwoDates(clsDate &Date1, clsDate &Date2);

    static int GetDifferentBetweenTwoDates(clsDate Date1, clsDate Date2, bool isEndDayIncluded = false);

    static int GetAgeInNumberOfDays(clsDate PersonDate);

    static bool isEndOfWeek(clsDate Date);

    static bool isWeekEnd(clsDate Date);

    static bool isBusinessDay(clsDate Date);

    static short DaysUntilTheEndOfTheWeek(clsDate Date);

    static short DaysUntilTheEndOfTheMonth(clsDate Date, bool isEndDayIncluded = false);

    static short DaysUntilTheEndOfTheYear(clsDate Date);

    static void PrintIfIsEndOfTheWeek();

    static void PrintIfWeekEnd();

    static void PrintIfItIsBusinessDay();

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo);

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short NumberOfDays);

    static enDateCompareDates CompreTwoDates(clsDate Date1, clsDate Date2);

    static bool isDayInMonthValid(clsDate Date);

    static bool isMonthValid(short Month);

    static bool isDateValid(clsDate Date);

    static std::string ReadDateInstring(std::string DateFormat = "");

    static void FillDateIntoStructure(std::vector<std::string> &DateString, clsDate &Date);

    static clsDate ConvertDateFromStringToStructure(std::string StringDate, std::string Delemiter);

    static std::string FormatDate(clsDate Date, std::string DateFormat = "dd/mm/yyyy", const std::string Delemiter = "/");
    // ---------------------------------------------------------------------------------------------------------------------------------------------

    // Non Static Method
    // ---------------------------------------------------------------------------------------------------------------------------------------------

     bool isYearLeap();

     short NumberOfDaysInYear();

     short NumberOfHoursInYear();

     int NumberOfMinutesInYear();

     int NumberOfSecondsInYear();

     short NumberOfDaysInMonth();

     short NumberOfHoursInMonth();

     int NumberofMinutesInMonth();

     int NumberofSecondsInMonth();

     void PrintDate();

     void PrintDateWithDelemiter(const std::string &Delemiter);

     void PrintDateAndDay(const std::string &Delemiter);

     short CalculateDayOrder();

     std::string GetDayNameFromDayOrder();

     std::string ConvertMonthIntoText();

     void PrintMonthCalender();

     void PrintYearCalender();

     short NumberOfDaysFromTheBeginingOfTheYear();

     clsDate GetDateFromNumberOfDays();

     void ReadDate(const std::string &Message = "");

     bool isDateLessThanDate2(clsDate &Date2);

     bool isDateEqualsToDate2(clsDate &Date2);

     bool isDateAfterDate2(clsDate &Date2);

     bool isLastDayInMonth();

     bool isLastMonthInYear();

     void IncreaseDateByOneDay();

     void IncreaseDateByXDayes(int NumberOfDays);

     void IncreaseDateByOneWeek();

     void IncreaseDateByXWeeks(int NumberOfWeeks);

     void IncreaseDateByOneMonth();

     void IncreaseDateByXMonths(int NumberOfMonths);

     void IncreaseDateByOneYear();

     void IncreaseDateByXYears(int NumberOfYears);

     void IncreaseDateByXYearsFaster(int NumberOfYears);

     void IncreaseDateByOneDecade();

     void IncreaseDateByXDecades(int NumberOfDecades);

     void IncreaseDateByXDecadesFaster(int NumberOfDecades);

     void IncreaseDateByOneCentury();

     void IncreaseDateByOneMillennium();

     bool isFirstDayInMonth();

     bool isFirstMonthInYear();

     void DecreaseDateByOneDay();

     void DecreaseDateByXDays(int NumberOfDays);

     void DecreaseDateByOneWeek();

     void DecreaseDateByXWeeks(int NumberOfWeeks);

     void DecreaseDateByOneMonth();

     void DecreaseDateByXMonths(int NumberOfMonth);

     void DecreaseDateByOneYear();

     void DecreaseDateByXYears(int NumberOfYears);

     void DecreaseDateByXYearsFaster(int NumberOfYears);

     void DecreaseDateByOneDecade();

     void DecreaseDateByXDecades(int NumberOfDecades);

     void DecreaseDateByXDecadesFaster(int NumberOfDecades);

     void DecreaseDateByOneCentury();

     void DecreaseDateByOneMillennium();

     void SwappingTwoDates(clsDate &Date2);

     int GetDifferentBetweenTwoDates(clsDate Date2, bool isEndDayIncluded = false);

     int GetAgeInNumberOfDays();

     bool isEndOfWeek();

     bool isWeekEnd();

     bool isBusinessDay();

     short DaysUntilTheEndOfTheWeek();

     short DaysUntilTheEndOfTheMonth(bool isEndDayIncluded = false);

     short DaysUntilTheEndOfTheYear();

    //  void PrintIfIsEndOfTheWeek();

    //  void PrintIfWeekEnd();

    //  void PrintIfItIsBusinessDay();

    //  short CalculateVacationDays(clsDate DateFrom, clsDate DateTo);

    //  clsDate CalculateVacationReturnDate(clsDate DateFrom, short NumberOfDays);

    //  enDateCompareDates CompreTwoDates(clsDate Date1, clsDate Date2);

     bool isDayInMonthValid();

     bool isMonthValid();

     bool isDateValid();

     void ReadDateString(std::string DateFormat = "", std::string Delemiter = " ");

     void FillDateIntoStructure(std::vector<std::string> &DateString);

    //  clsDate ConvertDateFromStringToStructure(std::string StringDate, std::string Delemiter);

     std::string FormatDate(std::string DateFormat = "dd/mm/yyyy", const std::string Delemiter = "/");
    // ---------------------------------------------------------------------------------------------------------------------------------------------
};

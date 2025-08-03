    #include "DateAndTime.h"

#include "PrintingOutputs.h"
#include "ReadingInputs.h"
#include "DealingWithStrings.h"

#include "Structures.h"

#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

bool isYearLeap(short Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInYear(short Year)
{
    return isYearLeap(Year) ? 366 : 365; // 366
}

short NumberOfHoursInYear(short Year)
{
    return (NumberOfDaysInYear(Year) * 24); // 8784
}

int NumberOfMinutesInYear(short Year)
{
    return (NumberOfHoursInYear(Year) * 60); // 527040
}

int NumberOfSecondsInYear(short Year)
{
    return (NumberOfMinutesInYear(Year) * 60); // 31622400
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? isYearLeap(Year) ? 29 : 28 : NumberOfDays[Month - 1]);
}

short NumberOfHoursInMonth(short Month, short Year)
{
    return (NumberOfDaysInMonth(Month, Year) * 24);
}

int NumberofMinutesInMonth(short Month, short Year)
{
    return (NumberOfHoursInMonth(Month, Year) * 60);
}

int NumberofSecondsInMonth(short Month, short Year)
{
    return (NumberofMinutesInMonth(Month, Year) * 60);
}

void PrintDate(short Day, short Month, short Year)
{
    PrintNumbers::printShortNumber(Day);
    PrintingText::PrintCharacters('/');
    PrintNumbers::printShortNumber(Month);
    PrintingText::PrintCharacters('/');
    PrintNumbers::printShortNumber(Year);
}

void PrintDate(stDate &Date)
{
    PrintNumbers::printShortNumber(Date.Day);
    PrintingText::PrintCharacters('/');
    PrintNumbers::printShortNumber(Date.Month);
    PrintingText::PrintCharacters('/');
    PrintNumbers::printShortNumber(Date.Year);
}

void PrintDate(stDate &Date, char Delemiter)
{
    PrintNumbers::printShortNumber(Date.Day);
    PrintingText::PrintCharacters(Delemiter);
    PrintNumbers::printShortNumber(Date.Month);
    PrintingText::PrintCharacters(Delemiter);
    PrintNumbers::printShortNumber(Date.Year);
}

void PrintDateAndDay(stDateAndDay DateAndDAy, char Delemiter)
{
    PrintingText::PrintSequenceOfCharacters('*', 50);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(1);
    PrintingText::PrintTextOnScreen("Today is ");
    PrintingText::PrintTextOnScreen(DateAndDAy.CurrentDayInText);
    PrintingText::PrintTextOnScreen(" , ");

    PrintNumbers::printShortNumber(DateAndDAy.Day);
    PrintingText::PrintCharacters(Delemiter);

    PrintNumbers::printShortNumber(DateAndDAy.Month);
    PrintingText::PrintCharacters(Delemiter);

    PrintNumbers::printShortNumber(DateAndDAy.Year);

    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 50);

    PrintingText::PrintLines();
}

stDateAndDay GetCurrentDateAndCurrentDayInText()
{
    stDateAndDay DateAndDay;

    stDate SystemDate = GetSystemDate();

    DateAndDay.Day = SystemDate.Day;
    DateAndDay.Month = SystemDate.Month;
    DateAndDay.Year = SystemDate.Year;
    DateAndDay.CurrentDayInText = DayOrderName(CalculateDayOrder(SystemDate));

    return DateAndDay;
}

short CalculateDayOrder(short Day, short Month, short Year)
{
    short A = 0;
    short Y = 0;
    short M = 0;

    A = (14 - Month) / (12);
    Y = Year - A;
    M = Month + (12 * A) - 2;

    short D = 0;
    D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

    return D;
}

short CalculateDayOrder(stDate Date)
{
    short A = 0;
    short Y = 0;
    short M = 0;

    A = (14 - Date.Month) / (12);
    Y = Date.Year - A;
    M = Date.Month + (12 * A) - 2;

    short D = 0;
    D = (Date.Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

    return D;
}

short CalculateDayOrder(stDateAndDay Date)
{
    short A = 0;
    short Y = 0;
    short M = 0;

    A = (14 - Date.Month) / (12);
    Y = Date.Year - A;
    M = Date.Month + (12 * A) - 2;

    short D = 0;
    D = (Date.Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

    return D;
}

string DayOrderName(short DayOrder)
{
    string DaysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return DaysOfWeek[DayOrder];
}

string ConvertMonthIntoText(short NumberOfMonth)
{
    string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return Months[NumberOfMonth - 1];
}

void PrintMonthCalender(short Month, short Year)
{
    // Here we see if the month is valid
    // -------------------------------------------------------
    if (Month < 1 || Month > 12)
    {
        PrintingText::PrintTextOnScreen("Invalid month");
        return;
    }
    // -------------------------------------------------------

    // Here we Store the Name of Month into text
    // -----------------------------------------------------
    string NameOfMonth = ConvertMonthIntoText(Month);
    // -----------------------------------------------------

    // Here we calculate the number of days in the current month
    // ---------------------------------------------------------------
    short NumberOfDays = NumberOfDaysInMonth(Month, Year);
    // ---------------------------------------------------------------

    // Here we Calclate the number number of the day, the month starts with
    // ---------------------------------------------------------------------------------
    short TheDayTheMonthStartsWith = CalculateDayOrder(1, Month, Year);
    // ---------------------------------------------------------------------------------

    // Here we print the name of the month in short way, we print the name of the month in 3 characters
    // ---------------------------------------------------------------------------------------------------------
    PrintingText::PrintSequenceOfCharacters('*', 10);
    PrintingText::PrintTextOnScreen(NameOfMonth);
    PrintingText::PrintSequenceOfCharacters('*', 15);
    PrintingText::PrintLines();
    // ---------------------------------------------------------------------------------------------------------

    // Here we print the header of the calender
    // --------------------------------------------------------------------------
    PrintingText::PrintTextOnScreen("Sun Mon Tue Wed Thu Fri Sat");
    PrintingText::PrintLines();
    // --------------------------------------------------------------------------

    /*
        Here we print spaces according the number of the day the month starts with
        and we multiply the number by 4 cuz each word of the day is from 3 characters and we have the space after the word
    */
    // -----------------------------------------------------------------------------------------------------------------------------
    PrintingText::PrintSpaces(4 * TheDayTheMonthStartsWith);
    // -----------------------------------------------------------------------------------------------------------------------------

    // Here we set the counter to the number the month the starts with
    // --------------------------------------------------------------------------
    short Counter = TheDayTheMonthStartsWith;
    // --------------------------------------------------------------------------

    // Here we make the loop according to the number of days in the month
    // --------------------------------------------------------------------------
    short PrinttedDays = TheDayTheMonthStartsWith + 1;

    for (short Days = 1; Days <= NumberOfDays; Days++)
    {

        // if(PrinttedDays == 7)
        // {
        //     PrintingText::PrintLines();
        // }

        // PrinttedDays++;

        if (Days < 10)
        {
            PrintingText::PrintSpaces(1);
            PrintNumbers::printShortNumber(Days);
            PrintingText::PrintSpaces(2);
        }

        else
        {
            PrintingText::PrintSpaces(1);
            PrintNumbers::printShortNumber(Days);
            PrintingText::PrintSpaces(1);
        }

        Counter++;

        if (Counter % 7 == 0)
        {
            PrintingText::PrintLines();
        }
    }
    // --------------------------------------------------------------------------

    /*
        Here we print a new line if the the number of days in the month is not (%) 7 == 28
        because some time according to days of the month the last line does not print a new
        lien
    */
    // ------------------------------------------------------------------------------------------------------
    if (NumberOfDays % 7 != 0)
    {
        PrintingText::PrintLines();
    }
    PrintingText::PrintSequenceOfCharacters('*', 28);
    // ------------------------------------------------------------------------------------------------------
}

void PrintYearCalender(short Year)
{
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();
    PrintingText::PrintTabs(1);
    PrintingText::PrintTextOnScreen("Calender - ");
    PrintNumbers::printShortNumber(Year);
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    for (short loop = 1; loop <= 12; loop++)
    {
        PrintMonthCalender(loop, Year);
        PrintingText::PrintLines(2);
    }
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short loop = 1; loop < Month; loop++)
    {
        TotalDays += NumberOfDaysInMonth(loop, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

stDate GetDateFromNumberOfDays(short NumberOfDays, short Year)
{
    stDate Date;

    Date.Year = Year;

    for (short Months = 1; Months <= 12; Months++)
    {
        short MonthDays = NumberOfDaysInMonth(Months, Year);

        if (NumberOfDays > MonthDays)
        {
            NumberOfDays -= MonthDays;
        }
        else
        {
            Date.Month = Months;
            Date.Day = NumberOfDays;
            break;
        }
    }
    return Date;
}

void ReadDate(stDate &Date)
{
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! READING DATE !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Date.Day = ReadNumbers::ReadingShortNumber("Enter a day: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Date.Month = ReadNumbers::ReadingShortNumber("Enter a month: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Date.Year = ReadNumbers::ReadingShortNumber("Enter a year: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
}

bool isDate1LessThanDate2(stDate &Date1, stDate &Date2)
{
    if (Date1.Year < Date2.Year)
    {
        return true;
    }
    else if (Date1.Year == Date2.Year)
    {
        if (Date1.Month < Date2.Month)
        {
            return true;
        }
        else if (Date1.Month == Date2.Month)
        {
            return (Date1.Day < Date2.Day);
        }
    }
    // return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false);
    return false;
}

bool isDate1EqualsToDate2(stDate &Date1, stDate &Date2)
{
    if (Date1.Year == Date2.Year)
    {
        if (Date1.Month == Date2.Month)
        {
            if (Date1.Day == Date2.Day)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool isLastDayInMonth(stDate &Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool isLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate &Date)
{
    if (isLastDayInMonth(Date))
    {
        if (isLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

void SwappingTwoDates(stDate &Date1, stDate &Date2)
{
    stDate TempDate;

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;
}

int GetDifferentBetweenTwoDates(stDate Date1, stDate Date2, bool isEndDayIncluded)
{

    int SwapFlagValue = 1;

    if (!isDate1LessThanDate2(Date1, Date2))
    {
        SwappingTwoDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    int NumberOfDaysBetweenTwoDate = 0;

    while (isDate1LessThanDate2(Date1, Date2))
    {
        NumberOfDaysBetweenTwoDate++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (isEndDayIncluded ? ++NumberOfDaysBetweenTwoDate * SwapFlagValue : NumberOfDaysBetweenTwoDate * SwapFlagValue);
}

stDate GetSystemDate()
{
    stDate SystemDate;

    time_t t = time(0);
    tm *now = localtime(&t);

    SystemDate.Day = now->tm_mday;
    SystemDate.Month = now->tm_mon + 1;
    SystemDate.Year = now->tm_year + 1900;

    return SystemDate;
}

int AgeInNumberOfDays(stDate PersonDate)
{
    stDate SystemDate = GetSystemDate();
    return GetDifferentBetweenTwoDates(PersonDate, SystemDate);
}

stDate IncreaseDateByXDayes(stDate Date, int NumberOfDays)
{
    for (int loop = 1; loop <= NumberOfDays; loop++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    short Week = 7;
    Date = IncreaseDateByXDayes(Date, Week);
    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, int NumberOfWeeks)
{
    for (int loop = 1; loop <= NumberOfWeeks; loop++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (isLastMonthInYear(Date.Month))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int NumberOfMonths)
{
    for (int loop = 1; loop <= NumberOfMonths; loop++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, int NumberOfYears)
{
    for (int loop = 1; loop <= NumberOfYears; loop++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, int NumberOfYears)
{
    Date.Year += NumberOfYears;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, int NumberOfDecades)
{
    for (int loop = 1; loop <= NumberOfDecades; loop++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, int NumberOfDecades)
{
    // Date = IncreaseDateByXYearsFaster(Date, NumberOfDecades * 10);
    Date.Year += NumberOfDecades * 10;
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;
}

bool isFirstDayInMonth(short Day)
{
    return (Day == 1);
}

bool isFirstMonthInYear(short Month)
{
    return (Month == 1);
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (isFirstDayInMonth(Date.Day))
    {
        if (isFirstMonthInYear(Date.Month))
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate DecreaseDateByXDays(stDate Date, int NumberOfDays)
{
    for (short loop = 1; loop <= NumberOfDays; loop++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    short Week = 7;
    Date = DecreaseDateByXDays(Date, Week);
    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, int NumberOfWeeks)
{
    for (int loop = 1; loop <= NumberOfWeeks; loop++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (isFirstMonthInYear(Date.Month))
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, int NumberOfMonth)
{
    for (int loop = 1; loop <= NumberOfMonth; loop++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, int NumberOfYears)
{
    for (int loop = 1; loop <= NumberOfYears; loop++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, int NumberOfYears)
{

    Date.Year -= NumberOfYears;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, int NumberOfDecades)
{
    for (int loop = 1; loop <= NumberOfDecades; loop++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, int NumberOfDecades)
{
    Date.Year -= NumberOfDecades * 10;
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

bool isEndOfWeek(stDate Date)
{
    return (CalculateDayOrder(Date) == 6);
}

bool isWeekEnd(stDate Date)
{
    short Day = CalculateDayOrder(Date);
    return (Day == 5 || Day == 6);
}

bool isBusinessDay(stDate Date)
{
    return (!isWeekEnd(Date));
}

short DaysUntilTheEndOfTheWeek(stDate Date)
{
    return (6 - CalculateDayOrder(Date));
}

short DaysUntilTheEndOfTheWeek(stDateAndDay Date)
{
    return (6 - CalculateDayOrder(Date));
}

short DaysUntilTheEndOfTheMonth(stDate Date, bool isEndDayIncluded)
{
    short NumberOfDays = 0;

    if (isEndDayIncluded)
    {
        NumberOfDays = (NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day + 1);
    }
    else
    {
        NumberOfDays = (NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day);
    }
    return NumberOfDays;
}

short DaysUntilTheEndOfTheMonth(stDateAndDay Date, bool isEndDayIncluded)
{
    short NumberOfDays = 0;

    if (isEndDayIncluded)
    {
        NumberOfDays = (NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day + 1);
    }
    else
    {
        NumberOfDays = (NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day);
    }
    return NumberOfDays;
}

short DaysUntilTheEndOfTheYear(stDate Date)
{
    stDate DateOfEndYear;
    DateOfEndYear.Day = Date.Day;
    DateOfEndYear.Month = Date.Month;
    DateOfEndYear.Year = Date.Year;

    return (GetDifferentBetweenTwoDates(Date, DateOfEndYear, true));
}

short DaysUntilTheEndOfTheYear(stDateAndDay Date)
{
    stDate DateOfEndYear;
    DateOfEndYear.Day = 31;
    DateOfEndYear.Month = 12;
    DateOfEndYear.Year = Date.Year;

    stDate CurrentDate;
    CurrentDate.Day = Date.Day;
    CurrentDate.Month = Date.Month;
    CurrentDate.Year = Date.Year;

    return (GetDifferentBetweenTwoDates(CurrentDate, DateOfEndYear, true));
}

void PrintIfIsEndOfTheWeek()
{

    stDate Date = GetSystemDate();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    if (isEndOfWeek(Date))
    {
        PrintingText::PrintTextOnScreen("Yes it is end of the week");
    }
    else
    {
        PrintingText::PrintTextOnScreen("No it is not end of the week");
    }

    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 30);

    PrintingText::PrintLines();
}

void PrintIfWeekEnd()
{
    stDate Date = GetSystemDate();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    if (isWeekEnd(Date))
    {
        PrintingText::PrintTextOnScreen("Yes it is weekend");
    }
    else
    {
        PrintingText::PrintTextOnScreen("No it is not end weekend");
    }

    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 30);

    PrintingText::PrintLines();
}

void PrintIfItIsBusinessDay()
{
    stDate Date = GetSystemDate();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    if (isBusinessDay(Date))
    {
        PrintingText::PrintTextOnScreen("Yes it is business day");
    }
    else
    {
        PrintingText::PrintTextOnScreen("No it is not business day");
    }

    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 30);

    PrintingText::PrintLines();
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short NumberofDays = 0;

    while (isDate1LessThanDate2(DateFrom, DateTo))
    {
        if (isBusinessDay(DateFrom))
        {
            NumberofDays++;
        }
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return NumberofDays;
}

stDate CalculateVacationReturnDate(stDate DateFrom, short NumberOfDays)
{
    stDate ReturnDate;

    for (short loop = 1; loop <= NumberOfDays; loop++)
    {
        if (isWeekEnd(DateFrom))
        {
            NumberOfDays++;
        }
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DateFrom;
}

bool isDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!isDate1LessThanDate2(Date1, Date2) && !isDate1EqualsToDate2(Date1, Date2));
}

enDateCompareDates CompreTwoDates(stDate Date1, stDate Date2)
{
    if (isDate1LessThanDate2(Date1, Date2))
    {
        return enDateCompareDates::Before;
    }
    if (isDate1EqualsToDate2(Date1, Date2))
    {
        return enDateCompareDates::Equal;
    }
    return enDateCompareDates::After;
}

void ReadPeriod(stPeriod &Period)
{
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrinFillDateIntoStructuretLines();
    PrintingText::PrintTextOnScreen("!!!!!! READING DATE !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Period.StartDate.Day = ReadNumbers::ReadingShortNumber("Enter start day: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Period.StartDate.Month = ReadNumbers::ReadingShortNumber("Enter start month: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Period.StartDate.Year = ReadNumbers::ReadingShortNumber("Enter start year: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Period.EndDate.Day = ReadNumbers::ReadingShortNumber("Enter end day: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Period.EndDate.Month = ReadNumbers::ReadingShortNumber("Enter end month: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Period.EndDate.Year = ReadNumbers::ReadingShortNumber("Enter end year: ");
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
}

bool isOverLapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompreTwoDates(Period2.EndDate, Period1.StartDate) == enDateCompareDates::Before ||
        CompreTwoDates(Period2.StartDate, Period1.EndDate) == enDateCompareDates::After)
    {
        return false;
    }
    return true;
}

int PeriodLengthInDays(stPeriod Period, bool isEndDayIncluded)
{
    return GetDifferentBetweenTwoDates(Period.StartDate, Period.EndDate, isEndDayIncluded);
}

bool isDateInPeriod(stPeriod Period, stDate Date)
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
        CompreTwoDates(Date, Period.StartDate) == Before ||
        CompreTwoDates(Date, Period.EndDate) == After);
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
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
        while (isDate1LessThanDate2(Period1.StartDate, Period1.EndDate))
        {
            if (isDateInPeriod(Period2, Period1.StartDate))
            {
                OverlapDays++;
            }
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }

    else
    {
        while (isDate1LessThanDate2(Period2.StartDate, Period2.EndDate))
        {
            if (isDateInPeriod(Period1, Period2.StartDate))
            {
                OverlapDays++;
            }
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapDays;
}

bool isMonthValid(short Month)
{
    return (Month >= 1 && Month <= 12);
}

bool isDayInMonthValid(stDate &Date)
{
    return (Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year) && Date.Day != 0);
}

bool isDateValid(stDate &Date)
{
    // To handle months range
    if (!isMonthValid(Date.Month))
    {
        return false;
    }
    // To handle days range
    else if (!isDayInMonthValid(Date))
    {
        return false;
    }
    return true; // if we reach here that mean that we got an correct date !
}

string ReadDateInstring(string DateFormat)
{
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! READING DATE !!!!!!");
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    string Message = "Enter a date " + DateFormat + ": ";
    string Date = ReadText::ReadTextOnScreen(Message);

    PrintingText::PrintSequenceOfCharacters('*', 40);
    PrintingText::PrintLines();

    PrintingText::PrintLines();

    return Date;
}

void FillDateIntoStructure(vector<std::string> &DateString, stDate &Date)
{
    try
    {
        Date.Day = stoi(DateString[0]);
        Date.Month = stoi(DateString[1]);
        Date.Year = stoi(DateString[2]);
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        cerr << "The stirng date, was empty !\n";
        return;
    }
}

stDate ConvertDateFromStringToStructure(std::string StringDate, string Delemiter)
{
    stDate Date;

    vector<string> TempVector;
    TempVector = SplitWordInSentence(StringDate, Delemiter);
    FillDateIntoStructure(TempVector, Date);

    return Date;
}

string FormatDate(stDate Date, string DateFormat, const string Delemiter)
{
    string FormattedDate = ReplaceFunctionWithSplitFunction(DateFormat, "dd", to_string(Date.Day), Delemiter);
    FormattedDate = ReplaceFunctionWithSplitFunction(FormattedDate, "mm", to_string(Date.Month), Delemiter);
    FormattedDate = ReplaceFunctionWithSplitFunction(FormattedDate, "yyyy", to_string(Date.Year), Delemiter);
    return FormattedDate;
}

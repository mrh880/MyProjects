#include "clsDate.h"

#include "EnumsLibrary/Enums.h"
#include "StringLibrary/clsString.h"
#include "PrintingOutputsLibrary/PrintingOutputs.h"
#include "ReadingInputsLibrary/ReadingInputs.h"
#include "EnumsLibrary/Enums.h"
#include "StringLibrary/clsString.h"

#include <iostream>
#include <string>

using namespace std;

clsDate::clsDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);

    _Day = now->tm_mday;
    _Month = now->tm_mon + 1;
    _Year = now->tm_year + 1900;

    _DayName = GetDayNameFromDayOrder(CalculateDayOrder(*this));
}

clsDate::clsDate(short Day, short Month, short Year)
{
    _Day = Day;
    _Month = Month;
    _Year = Year;
}

clsDate::clsDate(const string &Date)
{
    vector<string> VectorOfDate;
    VectorOfDate = clsString::SplitWordsInSentenceForVector(Date, "/");
    _Day = stoi(VectorOfDate[0]);
    _Month = stoi(VectorOfDate[1]);
    _Year = stoi(VectorOfDate[2]);
}

clsDate::clsDate(short DayOrderINYear, short Year)
{
    clsDate TempDate;
    TempDate = GetDateFromNumberOfDays(DayOrderINYear, Year);

    _Day = TempDate.Day();
    _Month = TempDate.Month();
    _Year = TempDate.Year();
}

// Set Property
// ---------------------------------------------------
void clsDate::SetDay(short Day)
{
    _Day = Day;
}

void clsDate::SetMonth(short Month)
{
    _Month = Month;
}

void clsDate::SetYear(short Year)
{
    _Year = Year;
}

void clsDate::SetDayName(const string &DayName)
{
    _DayName = DayName;
}
// ---------------------------------------------------

// Get Property
// ---------------------------------------------------
short clsDate::Day()
{
    return _Day;
}

short clsDate::Month()
{
    return _Month;
}

short clsDate::Year()
{
    return _Year;
}

string clsDate::DayName()
{
    return _DayName;
}

// ---------------------------------------------------

// Static Method
// ------------------------------------------------------------------------------------------------------------------------------------------------------
bool clsDate::isYearLeap(short Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short clsDate::NumberOfDaysInYear(short Year)
{
    return isYearLeap(Year) ? 366 : 365; // 366
}

short clsDate::NumberOfHoursInYear(short Year)
{
    return (NumberOfDaysInYear(Year) * 24); // 8784
}

int clsDate::NumberOfMinutesInYear(short Year)
{
    return (NumberOfHoursInYear(Year) * 60); // 527040
}

int clsDate::NumberOfSecondsInYear(short Year)
{
    return (NumberOfMinutesInYear(Year) * 60); // 31622400
}

short clsDate::NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? isYearLeap(Year) ? 29 : 28 : NumberOfDays[Month - 1]);
}

short clsDate::NumberOfHoursInMonth(short Month, short Year)
{
    return (NumberOfDaysInMonth(Month, Year) * 24);
}

int clsDate::NumberofMinutesInMonth(short Month, short Year)
{
    return (NumberOfHoursInMonth(Month, Year) * 60);
}

int clsDate::NumberofSecondsInMonth(short Month, short Year)
{
    return (NumberofMinutesInMonth(Month, Year) * 60);
}

void clsDate::PrintDate(short Day, short Month, short Year)
{
    cout << Day << "/" << Month << "/" << Year;
}

void clsDate::PrintDate(clsDate &Date)
{
    cout << Date.Day() << "/" << Date.Month() << "/" << Date.Year();
}

void clsDate::PrintDate(clsDate &Date, string Delemiter)
{
    cout << Date.Day() << Delemiter << Date.Month() << Delemiter << Date.Year() << endl;
}

void clsDate::PrintDateAndDay(clsDate &Date, string Delemiter)
{
    PrintingText::PrintSequenceOfCharacters('*', 50);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(1);
    PrintingText::PrintTextOnScreen("Today is ");
    PrintingText::PrintTextOnScreen(Date.DayName());
    PrintingText::PrintTextOnScreen(" , ");

    PrintNumbers::printShortNumber(Date.Day());
    PrintingText::PrintTextOnScreen(Delemiter);

    PrintNumbers::printShortNumber(Date.Month());
    PrintingText::PrintTextOnScreen(Delemiter);

    PrintNumbers::printShortNumber(Date.Year());

    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 50);

    PrintingText::PrintLines();
}

void clsDate::PrintDateAndDay()
{

    clsDate Date;
    
    PrintingText::PrintSequenceOfCharacters('*', 50);
    PrintingText::PrintLines();

    PrintingText::PrintTabs(1);
    PrintingText::PrintTextOnScreen("Today is ");
    PrintingText::PrintTextOnScreen(Date.DayName());
    PrintingText::PrintTextOnScreen(" , ");

    PrintNumbers::printShortNumber(Date.Day());
    PrintingText::PrintTextOnScreen("/");

    PrintNumbers::printShortNumber(Date.Month());
    PrintingText::PrintTextOnScreen("/");

    PrintNumbers::printShortNumber(Date.Year());

    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 50);

    PrintingText::PrintLines();
}

clsDate clsDate::GetSystemDate()
{

    clsDate SystemDate;

    time_t t = time(0);
    tm *now = localtime(&t);

    SystemDate.SetDay(now->tm_mday);
    SystemDate.SetMonth(now->tm_mon + 1);
    SystemDate.SetYear(now->tm_year + 1900);

    return SystemDate;
}

clsDate clsDate::GetCurrentDateAndCurrentDayName()
{
    clsDate Date;

    clsDate SystemDate = GetSystemDate();

    Date.SetDay(SystemDate.Day());
    Date.SetMonth(SystemDate.Month());
    Date.SetYear(SystemDate.Year());
    Date.SetDayName(GetDayNameFromDayOrder(CalculateDayOrder(Date)));

    return Date;
}

short clsDate::CalculateDayOrder(short Day, short Month, short Year)
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

short clsDate::CalculateDayOrder(clsDate &Date)
{
    return CalculateDayOrder(Date.Day(), Date.Month(), Date.Year());
}

string clsDate::GetDayNameFromDayOrder(short DayOrder)
{
    string DaysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return DaysOfWeek[DayOrder];
}

string clsDate::ConvertMonthIntoText(short NumberOfMonth)
{
    string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return Months[NumberOfMonth - 1];
}

void clsDate::PrintMonthCalender(short Month, short Year)
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
    if (Counter % 7 != 0)
    {
        PrintingText::PrintLines();
    }
    PrintingText::PrintSequenceOfCharacters('*', 28);
    // ------------------------------------------------------------------------------------------------------
}

void clsDate::PrintYearCalender(short Year)
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

short clsDate::NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short loop = 1; loop < Month; loop++)
    {
        TotalDays += NumberOfDaysInMonth(loop, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

short clsDate::NumberOfDaysFromTheBeginingOfTheYear(clsDate &Date)
{
    return NumberOfDaysFromTheBeginingOfTheYear(Date.Day(), Date.Month(), Date.Year());
}

clsDate clsDate::GetDateFromNumberOfDays(short NumberOfDays, short Year)
{
    clsDate Date;

    Date.SetYear(Year);

    for (short Months = 1; Months <= 12; Months++)
    {
        short MonthDays = NumberOfDaysInMonth(Months, Year);

        if (NumberOfDays > MonthDays)
        {
            NumberOfDays -= MonthDays;
        }
        else
        {
            Date.SetMonth(Months);
            Date.SetDay(NumberOfDays);
            break;
        }
    }
    return Date;
}

void clsDate::ReadDate(clsDate &Date, const string &Message)
{

    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();
    PrintingText::PrintTextOnScreen("!!!!!! READING DATE !!!!!!");
    if (!Message.empty())
    {
        PrintingText::PrintLines();
    }
    PrintingText::PrintTextOnScreen(Message);
    PrintingText::PrintLines();
    PrintingText::PrintSequenceOfCharacters('*', 60);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Date.SetDay(ReadNumbers::ReadingShortNumber("Enter a day: "));
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Date.SetMonth(ReadNumbers::ReadingShortNumber("Enter a month: "));
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();

    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines();
    Date.SetYear(ReadNumbers::ReadingShortNumber("Enter a year: "));
    PrintingText::PrintSequenceOfCharacters('*', 30);
    PrintingText::PrintLines(2);
}

bool clsDate::isDate1LessThanDate2(clsDate &Date1, clsDate &Date2)
{

    if (Date1.Year() < Date2.Year())
    {
        return true;
    }
    else if (Date1.Year() == Date2.Year())
    {
        if (Date1.Month() < Date2.Month())
        {
            return true;
        }
        else if (Date1.Month() == Date2.Month())
        {
            return (Date1.Day() < Date2.Day());
        }
    }
    // return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false);
    return false;
}

bool clsDate::isDate1EqualsToDate2(clsDate &Date1, clsDate &Date2)
{
    if (Date1.Year() == Date2.Year())
    {
        if (Date1.Month() == Date2.Month())
        {
            if (Date1.Day() == Date2.Day())
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

bool clsDate::isDate1AfterDate2(clsDate &Date1, clsDate &Date2)
{
    return (!isDate1LessThanDate2(Date1, Date2) && !isDate1EqualsToDate2(Date1, Date2));
}

bool clsDate::isLastDayInMonth(clsDate &Date)
{
    return (Date.Day() == NumberOfDaysInMonth(Date.Month(), Date.Year()));
}

bool clsDate::isLastMonthInYear(short Month)
{
    return (Month == 12);
}

clsDate clsDate::IncreaseDateByOneDay(clsDate Date)
{
    if (isLastDayInMonth(Date))
    {
        if (isLastMonthInYear(Date.Month()))
        {
            Date.SetDay(1);
            Date.SetMonth(1);
            Date.SetYear(Date.Year() + 1);
        }
        else
        {
            Date.SetDay(1);
            Date.SetMonth(Date.Month() + 1);
        }
    }
    else
    {
        Date.SetDay(Date.Day() + 1);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByXDayes(clsDate Date, int NumberOfDays)
{
    for (int loop = 1; loop <= NumberOfDays; loop++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByOneWeek(clsDate Date)
{
    short Week = 7;
    Date = IncreaseDateByXDayes(Date, Week);
    return Date;
}

clsDate clsDate::IncreaseDateByXWeeks(clsDate Date, int NumberOfWeeks)
{
    for (int loop = 1; loop <= NumberOfWeeks; loop++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByOneMonth(clsDate Date)
{
    if (isLastMonthInYear(Date.Month()))
    {
        Date.SetMonth(1);
        Date.SetYear(Date.Year() + 1);
    }
    else
    {
        Date.SetMonth(Date.Month() + 1);
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month(), Date.Year());

    if (Date.Day() > NumberOfDaysInCurrentMonth)
    {
        Date.SetDay(NumberOfDaysInCurrentMonth);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByXMonths(clsDate Date, int NumberOfMonths)
{
    for (int loop = 1; loop <= NumberOfMonths; loop++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByOneYear(clsDate Date)
{
    Date.SetYear(Date.Year() + 1);
    return Date;
}

clsDate clsDate::IncreaseDateByXYears(clsDate Date, int NumberOfYears)
{
    for (int loop = 1; loop <= NumberOfYears; loop++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByXYearsFaster(clsDate Date, int NumberOfYears)
{
    Date.SetYear(Date.Year() + NumberOfYears);
    return Date;
}

clsDate clsDate::IncreaseDateByOneDecade(clsDate Date)
{
    Date.SetYear(Date.Year() + 10);
    return Date;
}

clsDate clsDate::IncreaseDateByXDecades(clsDate Date, int NumberOfDecades)
{
    for (int loop = 1; loop <= NumberOfDecades; loop++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

clsDate clsDate::IncreaseDateByXDecadesFaster(clsDate Date, int NumberOfDecades)
{
    // Date = IncreaseDateByXYearsFaster(Date, NumberOfDecades * 10);
    Date.SetYear(Date.Year() + (NumberOfDecades * 10));
    return Date;
}

clsDate clsDate::IncreaseDateByOneCentury(clsDate Date)
{
    Date.SetYear(Date.Year() + 100);
    return Date;
}

clsDate clsDate::IncreaseDateByOneMillennium(clsDate Date)
{
    Date.SetYear(Date.Year() + 1000);
    return Date;
}

bool clsDate::isFirstDayInMonth(short Day)
{
    return (Day == 1);
}

bool clsDate::isFirstMonthInYear(short Month)
{
    return (Month == 1);
}

clsDate clsDate::DecreaseDateByOneDay(clsDate Date)
{
    if (isFirstDayInMonth(Date.Day()))
    {
        if (isFirstMonthInYear(Date.Month()))
        {
            Date.SetDay(31);
            Date.SetMonth(12);
            Date.SetYear(Date.Year() - 1);
        }
        else
        {
            Date.SetMonth(Date.Month() - 1);
            Date.SetDay(NumberOfDaysInMonth(Date.Month(), Date.Year()));
        }
    }
    else
    {
        Date.SetDay(Date.Day() - 1);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByXDays(clsDate Date, int NumberOfDays)
{
    for (short loop = 1; loop <= NumberOfDays; loop++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByOneWeek(clsDate Date)
{
    short Week = 7;
    Date = DecreaseDateByXDays(Date, Week);
    return Date;
}

clsDate clsDate::DecreaseDateByXWeeks(clsDate Date, int NumberOfWeeks)
{
    for (int loop = 1; loop <= NumberOfWeeks; loop++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByOneMonth(clsDate Date)
{
    if (isFirstMonthInYear(Date.Month()))
    {
        Date.SetMonth(12);
        Date.SetYear(Date.Year() - 1);
    }
    else
    {
        Date.SetMonth(Date.Month() - 1);
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month(), Date.Year());
    if (Date.Day() > NumberOfDaysInCurrentMonth)
    {
        Date.SetDay(NumberOfDaysInCurrentMonth);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByXMonths(clsDate Date, int NumberOfMonth)
{
    for (int loop = 1; loop <= NumberOfMonth; loop++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByOneYear(clsDate Date)
{
    Date.SetYear(Date.Year() - 1);
    return Date;
}

clsDate clsDate::DecreaseDateByXYears(clsDate Date, int NumberOfYears)
{
    for (int loop = 1; loop <= NumberOfYears; loop++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByXYearsFaster(clsDate Date, int NumberOfYears)
{
    Date.SetYear(Date.Year() - NumberOfYears);
    return Date;
}

clsDate clsDate::DecreaseDateByOneDecade(clsDate Date)
{
    Date.SetYear(Date.Year() - 10);
    return Date;
}

clsDate clsDate::DecreaseDateByXDecades(clsDate Date, int NumberOfDecades)
{
    for (int loop = 1; loop <= NumberOfDecades; loop++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

clsDate clsDate::DecreaseDateByXDecadesFaster(clsDate Date, int NumberOfDecades)
{
    Date.SetYear(Date.Year() - (NumberOfDecades * 10));
    return Date;
}

clsDate clsDate::DecreaseDateByOneCentury(clsDate Date)
{
    Date.SetYear(Date.Year() - 100);
    return Date;
}

clsDate clsDate::DecreaseDateByOneMillennium(clsDate Date)
{
    Date.SetYear(Date.Year() - 1000);
    return Date;
}

void clsDate::SwappingTwoDates(clsDate &Date1, clsDate &Date2)
{
    clsDate TempDate;

    TempDate.SetDay(Date1.Day());
    TempDate.SetMonth(Date1.Month());
    TempDate.SetYear(Date1.Year());

    Date1.SetDay(Date2.Day());
    Date1.SetMonth(Date2.Month());
    Date1.SetYear(Date2.Year());

    Date2.SetDay(TempDate.Day());
    Date2.SetMonth(TempDate.Month());
    Date2.SetYear(TempDate.Year());
}

int clsDate::GetDifferentBetweenTwoDates(clsDate Date1, clsDate Date2, bool isEndDayIncluded)
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

int clsDate::GetAgeInNumberOfDays(clsDate PersonDate)
{
    clsDate SystemDate = GetSystemDate();
    return GetDifferentBetweenTwoDates(PersonDate, SystemDate);
}

bool clsDate::isEndOfWeek(clsDate Date)
{
    return (CalculateDayOrder(Date) == 6);
}

bool clsDate::isWeekEnd(clsDate Date)
{
    short Day = CalculateDayOrder(Date);
    return (Day == 5 || Day == 6);
}

bool clsDate::isBusinessDay(clsDate Date)
{
    return (!isWeekEnd(Date));
}

short clsDate::DaysUntilTheEndOfTheWeek(clsDate Date)
{
    return (6 - CalculateDayOrder(Date));
}

short clsDate::DaysUntilTheEndOfTheMonth(clsDate Date, bool isEndDayIncluded)
{
    short NumberOfDays = 0;

    if (isEndDayIncluded)
    {
        NumberOfDays = (NumberOfDaysInMonth(Date.Month(), Date.Year()) - Date.Day() + 1);
    }
    else
    {
        NumberOfDays = (NumberOfDaysInMonth(Date.Month(), Date.Year()) - Date.Day());
    }
    return NumberOfDays;
}

short clsDate::DaysUntilTheEndOfTheYear(clsDate Date)
{
    clsDate DateOfEndYear;
    DateOfEndYear.SetDay(31);
    DateOfEndYear.SetMonth(12);
    DateOfEndYear.SetYear(Date.Year());

    return (GetDifferentBetweenTwoDates(Date, DateOfEndYear, true));
}

void clsDate::PrintIfIsEndOfTheWeek()
{
    clsDate Date = GetSystemDate();

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

void clsDate::PrintIfWeekEnd()
{
    clsDate Date = GetSystemDate();

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

void clsDate::PrintIfItIsBusinessDay()
{
    clsDate Date = GetSystemDate();

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

short clsDate::CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
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

clsDate clsDate::CalculateVacationReturnDate(clsDate DateFrom, short NumberOfDays)
{
    clsDate ReturnDate;

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

enDateCompareDates clsDate::CompreTwoDates(clsDate Date1, clsDate Date2)
{
    if (isDate1LessThanDate2(Date1, Date2))
    {
        return enDateCompareDates::Before;
    }
    else if (isDate1EqualsToDate2(Date1, Date2))
    {
        return enDateCompareDates::Equal;
    }
    else
    {
        return enDateCompareDates::After;
    }
}

bool clsDate::isDayInMonthValid(clsDate Date)
{
    return (Date.Day() <= NumberOfDaysInMonth(Date.Month(), Date.Year()) && Date.Day() != 0);
}

bool clsDate::isMonthValid(short Month)
{
    return (Month >= 1 && Month <= 12);
}

bool clsDate::isDateValid(clsDate Date)
{
    // To handle months range
    if (!isMonthValid(Date.Month()))
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

string clsDate::ReadDateInstring(string DateFormat)
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

void clsDate::FillDateIntoStructure(std::vector<std::string> &DateString, clsDate &Date)
{
    try
    {
        Date.SetDay(stoi(DateString[0]));
        Date.SetMonth(stoi(DateString[1]));
        Date.SetYear(stoi(DateString[2]));
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        cerr << "The stirng date, was empty !\n";
        return;
    }
}

clsDate clsDate::ConvertDateFromStringToStructure(string StringDate, string Delemiter)
{
    clsDate Date;

    vector<string> TempVector;

    TempVector = clsString::SplitWordsInSentenceForVector(StringDate, Delemiter);
    FillDateIntoStructure(TempVector, Date);

    return Date;
}

string clsDate::FormatDate(clsDate Date, string DateFormat, const string Delemiter)
{
    string FormattedDate = clsString::ReplaceFunctionWithSplitFunction(DateFormat, "dd", to_string(Date.Day()), Delemiter);
    FormattedDate = clsString::ReplaceFunctionWithSplitFunction(FormattedDate, "mm", to_string(Date.Month()), Delemiter);
    FormattedDate = clsString::ReplaceFunctionWithSplitFunction(FormattedDate, "yyyy", to_string(Date.Year()), Delemiter);
    return FormattedDate;
}
// ------------------------------------------------------------------------------------------------------------------------------------------------------

// Non Static Method
// ------------------------------------------------------------------------------------------------------------------------------------------------------
bool clsDate::isYearLeap()
{
    return isYearLeap(_Year);
}

short clsDate::NumberOfDaysInYear()
{
    return NumberOfDaysInYear(_Year);
}

short clsDate::NumberOfHoursInYear()
{
    return NumberOfHoursInYear(_Year);
}

int clsDate::NumberOfMinutesInYear()
{
    return NumberOfMinutesInYear(_Year);
}

int clsDate::NumberOfSecondsInYear()
{
    return NumberOfSecondsInYear(_Year);
}

short clsDate::NumberOfDaysInMonth()
{
    return NumberOfDaysInMonth(_Month, _Year);
}

short clsDate::NumberOfHoursInMonth()
{
    return NumberOfHoursInMonth(_Month, _Year);
}

int clsDate::NumberofMinutesInMonth()
{
    return NumberofMinutesInMonth(_Month, _Year);
}

int clsDate::NumberofSecondsInMonth()
{
    return NumberofSecondsInMonth(_Month, _Year);
}

void clsDate::PrintDate()
{
    PrintDate(_Day, _Month, _Year);
}

void clsDate::PrintDateWithDelemiter(const string &Delemiter)
{
    PrintDate(*this, Delemiter);
}

void clsDate::PrintDateAndDay(const string &Delemiter)
{
    PrintDateAndDay(*this, Delemiter);
}

short clsDate::CalculateDayOrder()
{
    return CalculateDayOrder(*this);
}

string clsDate::GetDayNameFromDayOrder()
{
    return GetDayNameFromDayOrder(CalculateDayOrder(*this));
}

string clsDate::ConvertMonthIntoText()
{
    return ConvertMonthIntoText(_Month);
}

void clsDate::PrintMonthCalender()
{
    PrintMonthCalender(_Month, _Year);
}

void clsDate::PrintYearCalender()
{
    PrintYearCalender(_Year);
}

short clsDate::NumberOfDaysFromTheBeginingOfTheYear()
{
    return NumberOfDaysFromTheBeginingOfTheYear(*this);
}

clsDate clsDate::GetDateFromNumberOfDays()
{
    return GetDateFromNumberOfDays(NumberOfDaysFromTheBeginingOfTheYear(*this), _Year);
}

void clsDate::ReadDate(const string &Message)
{
    ReadDate(*this, Message);
}

bool clsDate::isDateLessThanDate2(clsDate &Date2)
{
    return isDate1LessThanDate2(*this, Date2);
}

bool clsDate::isDateEqualsToDate2(clsDate &Date2)
{
    return isDate1EqualsToDate2(*this, Date2);
}

bool clsDate::isDateAfterDate2(clsDate &Date2)
{
    return isDate1AfterDate2(*this, Date2);
}

bool clsDate::isLastDayInMonth()
{
    return isLastDayInMonth(*this);
}

bool clsDate::isLastMonthInYear()
{
    return isLastMonthInYear(_Month);
}

void clsDate::IncreaseDateByOneDay()
{
    *this = IncreaseDateByOneDay(*this);
}

void clsDate::IncreaseDateByXDayes(int NumberOfDays)
{
    *this = IncreaseDateByXDayes(*this, NumberOfDays);
}

void clsDate::IncreaseDateByOneWeek()
{
    *this = IncreaseDateByOneWeek(*this);
}

void clsDate::IncreaseDateByXWeeks(int NumberOfWeeks)
{
    *this = IncreaseDateByXWeeks(*this, NumberOfWeeks);
}
void clsDate::IncreaseDateByOneMonth()
{
    *this = IncreaseDateByOneMonth(*this);
}

void clsDate::IncreaseDateByXMonths(int NumberOfMonths)
{
    *this = IncreaseDateByXMonths(*this, NumberOfMonths);
}

void clsDate::IncreaseDateByOneYear()
{
    *this = IncreaseDateByOneYear(*this);
}

void clsDate::IncreaseDateByXYears(int NumberOfYears)
{
    *this = IncreaseDateByXYears(*this, NumberOfYears);
}

void clsDate::IncreaseDateByXYearsFaster(int NumberOfYears)
{
    *this = IncreaseDateByXYearsFaster(*this, NumberOfYears);
}

void clsDate::IncreaseDateByOneDecade()
{
    *this = IncreaseDateByOneDecade(*this);
}

void clsDate::IncreaseDateByXDecades(int NumberOfDecades)
{
    *this = IncreaseDateByXDecades(*this, NumberOfDecades);
}

void clsDate::IncreaseDateByXDecadesFaster(int NumberOfDecades)
{
    *this = IncreaseDateByXDecadesFaster(*this, NumberOfDecades);
}

void clsDate::IncreaseDateByOneCentury()
{
    *this = IncreaseDateByOneCentury(*this);
}

void clsDate::IncreaseDateByOneMillennium()
{
    *this = IncreaseDateByOneMillennium(*this);
}

bool clsDate::isFirstDayInMonth()
{
    return isFirstDayInMonth(_Day);
}

bool clsDate::isFirstMonthInYear()
{
    return isFirstMonthInYear(_Month);
}

void clsDate::DecreaseDateByOneDay()
{
    *this = DecreaseDateByOneDay(*this);
}

void clsDate::DecreaseDateByXDays(int NumberOfDays)
{
    *this = DecreaseDateByXDays(*this, NumberOfDays);
}

void clsDate::DecreaseDateByOneWeek()
{
    *this = DecreaseDateByOneWeek(*this);
}

void clsDate::DecreaseDateByXWeeks(int NumberOfWeeks)
{
    *this = DecreaseDateByXWeeks(*this, NumberOfWeeks);
}

void clsDate::DecreaseDateByOneMonth()
{
    *this = DecreaseDateByOneMonth(*this);
}

void clsDate::DecreaseDateByXMonths(int NumberOfMonths)
{
    *this = DecreaseDateByXMonths(*this, NumberOfMonths);
}

void clsDate::DecreaseDateByOneYear()
{
    *this = DecreaseDateByOneYear(*this);
}

void clsDate::DecreaseDateByXYears(int NumberOfYears)
{
    *this = DecreaseDateByXYears(*this, NumberOfYears);
}

void clsDate::DecreaseDateByXYearsFaster(int NumberOfYears)
{
    *this = DecreaseDateByXYearsFaster(*this, NumberOfYears);
}

void clsDate::DecreaseDateByOneDecade()
{
    *this = DecreaseDateByOneDecade(*this);
}

void clsDate::DecreaseDateByXDecades(int NumberOfDecades)
{
    *this = DecreaseDateByXDecades(*this, NumberOfDecades);
}

void clsDate::DecreaseDateByXDecadesFaster(int NumberOfDecades)
{
    *this = DecreaseDateByXDecadesFaster(*this, NumberOfDecades);
}

void clsDate::DecreaseDateByOneCentury()
{
    *this = DecreaseDateByOneCentury(*this);
}

void clsDate::DecreaseDateByOneMillennium()
{
    *this = DecreaseDateByOneMillennium(*this);
}

void clsDate::SwappingTwoDates(clsDate &Date2)
{
    SwappingTwoDates(*this, Date2);
}

int clsDate::GetDifferentBetweenTwoDates(clsDate Date2, bool isEndDayIncluded)
{
    return GetDifferentBetweenTwoDates(*this, Date2, isEndDayIncluded);
}

int clsDate::GetAgeInNumberOfDays()
{
    return GetAgeInNumberOfDays(*this);
}

bool clsDate::isEndOfWeek()
{
    return isEndOfWeek(*this);
}

bool clsDate::isWeekEnd()
{
    return isWeekEnd(*this);
}

bool clsDate::isBusinessDay()
{
    return isBusinessDay(*this);
}

short clsDate::DaysUntilTheEndOfTheWeek()
{
    return DaysUntilTheEndOfTheWeek(*this);
}

short clsDate::DaysUntilTheEndOfTheMonth(bool isEndDayIncluded)
{
    return DaysUntilTheEndOfTheMonth(*this, isEndDayIncluded);
}

short clsDate::DaysUntilTheEndOfTheYear()
{
    return DaysUntilTheEndOfTheYear(*this);
}

// void clsDate::PrintIfIsEndOfTheWeek()
// {
//     PrintIfIsEndOfTheWeek();
// }

// void clsDate::PrintIfWeekEnd()
// {
//     PrintIfWeekEnd();
// }

// void clsDate::PrintIfItIsBusinessDay()
// {
//     PrintIfItIsBusinessDay();
// }

// short clsDate::CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
// {
//     return CalculateVacationDays(DateFrom, DateTo);
// }

// enDateCompareDates clsDate::CompreTwoDates(clsDate Date1, clsDate Date2)
// {
//     return CompreTwoDates(Date1, Date2);
// }

bool clsDate::isDayInMonthValid()
{
    return isDayInMonthValid(*this);
}

bool clsDate::isMonthValid()
{
    return isMonthValid(_Month);
}

bool clsDate::isDateValid()
{
    return isDateValid(*this);
}

void clsDate::ReadDateString(string DateFormat, string Delemiter)
{
    string TempString = "";
    TempString = ReadDateInstring(DateFormat); // first we read the date and store it in a string, with the delemiter 

    vector<string> VectorOfDate; // we create this vector to store the date after we split 
    VectorOfDate = clsString::SplitWordsInSentenceForVector(TempString, Delemiter); // here we split the string of date and split each one 

    FillDateIntoStructure(VectorOfDate); // here we fill it to the current object 

    // *this = ConvertDateFromStringToStructure(TempString, Delemiter);
}

void clsDate::FillDateIntoStructure(vector<string> &DateString)
{
    FillDateIntoStructure(DateString, *this);
}

string clsDate::FormatDate(std::string DateFormat, const std::string Delemiter)
{
    return FormatDate(*this, DateFormat, Delemiter);
}
// ------------------------------------------------------------------------------------------------------------------------------------------------------

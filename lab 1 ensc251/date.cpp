#include "date.hpp"
#include <cmath>

//Constructor
Date::Date(int inputMonth, int inputDay) {
    month = inputMonth;
    day = inputDay;
}


//Getters and Setters

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

void Date::setDay(int inputDay) {
    day = inputDay;
}

void Date::setMonth(int inputMonth) {
    month = inputMonth;
}


//Friend Functions
bool equal(const Date& date1, const Date& date2) {
    if (date1.month == date2.month && date1.day == date2.day) {
        return true;
    }

    else {
        return false;
    }
}

//Other Member Functions

bool Date::isValid() {
    
    //Check that the month is within the term
    if (month < 9 || month > 12) {  //September to December
        return false;
    }

    //Check that the given day is within the possible range
    else if (day < 0 || day > 31) {
        return false;
    }

    //Check beginning of term
    else if (month == 9) {  //Term starts Sept 8
        if (day < 8){
            return false;
        }
    }

    //Check end of term
    else if (month == 12) { //Term ends Dec 20
        if (day > 20) { 
            return false;
        }
    }

    //Check that the number of days is correct for the given month
    else if (month != 10) {  //October 31st is the only 31st of the term
        if (day > 31) {
            return false;
        }
    }

    //If all other checks pass:
    return true;
}


//check if date is a weekend
bool Date::isWeekend()
{
    int NewMonth = fmod(month + 10, 12) // Formula only intakes months as follows January = 11, Febuary = 12, ... December = 10 so we shift all months by 10 and limit their range to 12
    int C = 20;                        // Century based off first two numbers e.g. 1990 = 19, 2019 = 20
    int Y = 20;                         // Year is based off last two numbers
    float Weekend = (day + (2.6 * NewMonth - 0.2) - 2 * C + Y + (Y / 4) + (C / 4)); //Alex Lopez-Ortiz's formula of day determination based on an output where 0 is Sunday, and 6 is Saturday
    Weekend = fmod(Weekend, 7)      // Formula must be in mod 7 for the week, 
        if (Weekend = 0 || Weekend = 6) { //If day of week is sunday (0), or saturday (6) then it is a weekend
            return true;
        }
        else return false;
}


bool Date::isHoliday(const Date& holiday1, const Date& holiday2){
    if (equal(*this, holiday1) || equal(*this, holiday2)) {
        return true;
    }
    else {
        return false;
    }
}
//header file date.hpp to declare your class
class Date {

    public:

        //Constructor
        Date(int month, int day);


        //Getters and setters
        int getDay();
        int getMonth();

        void setDay(int inputDay);
        void setMonth(int inputMonth);


        //Friend functions
        friend bool equal(const Date& date1, const Date& date2);

        //Other member functions
        bool isValid();         //Is the input date within the Fall 2020 term
        bool isHoliday(const Date& holiday1, const Date& holiday2); //Is the input date on a holiday
        bool isWeekend();       //Is the input date on Saturday or Sunday

        void output();
        void printFreeTimeSlots();
        void printAppointedTimeSlots();

    private:

        int month;
        int day;

        //stores whether each half-hour of the day is booked or not
        //if appointed[1] == true, there is an appointment booked from 00:30 to 01:00
        bool appointed[48] = {0};
};

#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
    Date();

   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
    Date(unsigned m, unsigned d, unsigned y);

   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
    string name(unsigned m) const;
       

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

  Date::Date() {
    this -> month = 1;
    this -> day = 1;
    this -> year = 2000;
    this -> monthName = "January";
    
}
  Date :: Date(unsigned m, unsigned d, unsigned y) {
    bool monthError = false;
    bool dayError = false;
     if (m == 1){
         this -> month = 1;
        this -> monthName = name(1);
     }
     else if ( m == 2){
         this -> month = 2;
         this -> monthName = name(2);
     }
     else if ( m == 3){
         this -> month = 3;
         this -> monthName = name(3);
     }
     else if ( m == 4){
         this -> month = 4;
         this -> monthName = name(4);
     }
     else if ( m == 5){
         this -> month = 5;
         this -> monthName = name(5);
     }
     else if ( m == 6){
         this -> month = 6;
         this -> monthName = name(2);
     }
     else if ( m == 7){
         this -> month = 7;
         this -> monthName = name(7);
     }
     else if ( m == 8){
         this -> month = 8;
         this -> monthName = name(8);
     }
     else if ( m == 9){
         this -> month = 9;
         this -> monthName = name(9);
     }
     else if ( m == 10){
         this -> month = 10;
         this -> monthName = name(10);
     }
     else if ( m == 11){
         this -> month = 11;
         this -> monthName = name(11);
     }
     else if ( m == 12){
         this -> month = 12;
         this -> monthName = name(12);
     }
     else if ( m > 12){
         this -> month = 12;
         this -> monthName = name(12);
         monthError = true;
     }
      else if ( m < 1){
      this -> month = 1;
      this -> monthName = name(1);
      monthError = true;
     }
   
     this -> year = y;
      
      if( daysPerMonth( this -> month, y ) < d ){
          this -> day = daysPerMonth( this -> month, y);
          dayError = true;
      }
      else if( d < 1){
          this -> day = 1;
          dayError = true;
      }
      else {
          this -> day = d;
      }
       
      if ( dayError == true || monthError == true ){
         cout << "Invalid date values: Date corrected to " << this -> month << "/" << this -> day << "/" << this -> year << "." << endl;
       }
       
       
   }
  string Date::name(unsigned m) const {
      string N;
     if (m == 1){
           N = "January";
      }
     else if ( m == 2){
          N = "February";
      }
     else if ( m == 3){
           N = "March";
          }
     else if ( m == 4){
           N = "April";
          }
     else if ( m == 5){
           N = "May";
          }
     else if ( m == 6){
          N = "June";
          }
     else if ( m == 7){
           N = "July";
          }
     else if ( m == 8){
           N = "August";
          }
     else if ( m == 9){
           N = "September";
          }
     else if ( m == 10){
           N = "October";
          }
     else if ( m == 11){
           N = "November";
          }
     else if ( m == 12){
           N = "December";
          }
          
     return N;
  }
unsigned Date::number(const string &mn) const {
    unsigned num = 0;
    if ( mn == "January"){
        num = 1;
    }
    else if ( mn == "February"){
        num = 2;
    }
    else if ( mn == "March"){
        num = 3;
    }
    else if ( mn == "April"){
        num = 4;
    }
    else if ( mn == "May"){
        num = 5;
    }
    else if ( mn == "June"){
        num = 6;
    }
    else if ( mn == "July"){
        num = 7;
    }
    else if ( mn == "August"){
        num = 8;
    }
    else if ( mn == "September"){
        num = 9;
    }
    else if ( mn == "October"){
        num = 10;
    }
    else if ( mn == "November"){
        num = 11;
    }
    else if ( mn == "December"){
        num = 12;
    }
    return num;
}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
    unsigned maxDays = 0;
    if ( m  == 4 || m == 6 || m == 11 || m == 9  ){
            maxDays = 30;
          }
    else if (  m  == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 ){
            maxDays = 31;
        }
    else if ( m == 2 ){
        if ( isLeap(y) == true){
            maxDays = 29;
            }
        else {
            maxDays = 28;
            }
        }
    return maxDays;
}
void Date::printNumeric() const {
    cout << this -> month << "/" << this -> day << "/" << this -> year;
}
void Date::printAlpha() const {
    cout << this -> monthName << " " << this -> day << ", " << this -> year;
}
bool Date :: isLeap(unsigned y) const {
    if (  ( ( (y % 4 == 0 || y % 400 == 0) && y % 100 !=0 ) ) || ((y % 4 == 0 && y % 400 == 0) && y % 100 ==0  ) ){
       return true;
    }
    else {
        return false;
    }
    
}

Date :: Date(const string &mn, unsigned d, unsigned y){
    bool monthWrong = false;
    if ( mn == "January" || mn == "january" ){
        this -> month = 1;
        this -> monthName = "January";
        this -> year = y;
        this -> day = d;
    }
    else if ( mn == "February" || mn == "february" ){
        this -> month = 2;
        this -> monthName = "February";
        this -> year = y;
        this -> day = d;
       }
    else if ( mn == "March" || mn == "march" ){
        this -> month = 3;
        this -> monthName = "March";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "April" || mn == "april" ){
        this -> month = 4;
        this -> monthName = "April";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "May" || mn == "may" ){
        this -> month = 5;
        this -> monthName = "May";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "June" || mn == "june" ){
        this -> month = 6;
        this -> monthName = "June";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "July" || mn == "july" ){
        this -> month = 7;
        this -> monthName = "July";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "August" || mn == "august" ){
        this -> month = 8;
        this -> monthName = "August";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "September" || mn == "september" ){
        this -> month = 9;
        this -> monthName = "September";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "October" || mn == "october" ){
        this -> month = 10;
        this -> monthName = "October";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "November" || mn == "november" ){
        this -> month = 11;
        this -> monthName = "November";
        this -> year = y;
        this -> day = d;
          }
    else if ( mn == "December" || mn == "december" ){
        this -> month = 12;
        this -> monthName = "December";
        this -> year = y;
        this -> day = d;
          }
    else{
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
        this -> month = 1;
        this -> monthName = "January";
        this -> day = 1;
        this -> year = 2000;
        monthWrong = true;
          
    }
   
    if ( d > daysPerMonth(this -> month, y) && monthWrong == false){
        this -> day = daysPerMonth(this -> month, y);
        cout << "Invalid date values: Date corrected to " << this -> month << "/" << this -> day << "/" << this -> year << "." << endl;
    }
    else if ( d < 1) {
        this -> day = 1;
        cout << "Invalid date values: Date corrected to " << this -> month << "/" << this -> day << "/" << this -> year << "." << endl;
    }




}







// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}

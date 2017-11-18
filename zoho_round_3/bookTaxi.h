#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define TaxiNum 5

/* To store the status of the Taxi.. Free or Allocated...
*/
enum status{freed,allocated}; 

/* To store the details of the Taxi */
struct taxi
{
 int taxiId;
 int freeTime;
 enum status freeStatus;
 char station;
 int totalEarned;
}t[TaxiNum];
typedef struct taxi Taxi;

typedef struct customer
{
 int customer_id;
 char station_allocated;
}Customer;

struct TravelTbl
{
 struct travel **list;
}*tTbl;
typedef struct TravelTbl TravelTbl;


typedef struct travel
{
 int bookID;
 int customerID;
 char from;
 char to;
 int pick;
 int drop;
 int amount;
 int taxiNo;
 struct travel *next;
}Travel;

Travel travel[100];

int bookID;
void bookTaxi(int custid, char pickStation[], char dropStation[], int pickTime);
void loadTaxiDetails(Taxi[]);
void updateTaxiDetails(int);
int nearestTaxi(char);
void init(TravelTbl*);


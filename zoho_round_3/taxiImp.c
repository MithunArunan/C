#include"bookTaxi.h"

// To display the user Menu
void displayOptions()
{
  printf("\n1. Book Taxi 2. View Taxi Travel History 3. EXIT\n\n"); 
  printf("Enter a option to proceed ");
}

void init(TravelTbl *tTbl)
{
 int index = 0;
 tTbl =(TravelTbl*) malloc(sizeof(tTbl));
 tTbl->list =(Travel**) malloc(sizeof(Travel*)*TaxiNum);
 for(index=0 ; index <TaxiNum ; index++)
 {
  tTbl->list[index]  = (Travel*) malloc(sizeof(Travel));
 }
}

// To load the details of the Taxi from the database
void loadTaxiDetails(Taxi t[])
{
 int index;
 FILE *fp;
 fp = fopen("taxiDetails.dat","rb");
 for(index=0;index<TaxiNum;index++)
 {
  fread(&t[index],sizeof(t[index]),1,fp);
  printf("\nTaxi ID %d , freeStatus %d Station : %c ",t[index].taxiId+1,t[index].freeStatus, t[index].station);
 }
 fclose(fp);
}

// To book a taxi
void bookTaxi(int custid, char pickStation[], char dropStation[], int pickTime)
{
 int dropTime, x;
 updateTaxiDetails(pickTime);
 int near_taxi_id = nearestTaxi(pickStation[0]);
 if(near_taxi_id != -1)
 {
  printf("\nBooking ID: %d",bookID);
  printf("\nAllocated Taxi : Taxi%d \n",near_taxi_id+1);
  int tmp = abs(dropStation[0] - pickStation[0]);
  dropTime = tmp + pickTime;
 // printf("Drop Time will be %d ",dropTime); 
  printf("\n");
  t[near_taxi_id].freeStatus = allocated;
  x = abs(t[near_taxi_id].station - pickStation[0] )*15;
  t[near_taxi_id].station = dropStation[0];
  t[near_taxi_id].freeTime = dropTime;
  int y = findAmount(tmp);
  t[near_taxi_id].totalEarned =t[near_taxi_id].totalEarned + y -(5*x) ;   
  travel[bookID].taxiNo = near_taxi_id ;
  travel[bookID].bookID = bookID;
  travel[bookID].customerID = custid;
  travel[bookID].from = pickStation[0];
  travel[bookID].to = dropStation[0];
  travel[bookID].pick = pickTime;
  travel[bookID].drop = dropTime;
  travel[bookID].amount = y-x;
  bookID++;
 }
 else
 {
  printf("\nTaxi Booking rejected\n");
 }
}

int findAmount(int tmp)
{
  float amount = 100;
  tmp *= 15;
  tmp -= 5;
  amount += (tmp*10);
  return amount;
}

void updateTaxiDetails(int pickTime)
{
 int index;
 for(index=0;index<TaxiNum;index++)
 {
  if(t[index].freeStatus) // if taxi not free
  if(t[index].freeTime <= pickTime)
   t[index].freeStatus = freed;
 }
}


// Find the nearest Free taxi
int nearestTaxi(char pickStation)
{
 int index, nearID = -1, diff, min = INT_MAX;
 int loc;
 int minArr[10], ind, earn;
 for(index=0;index<TaxiNum;index++)
  {
   if(!t[index].freeStatus)
   {
    diff = abs(pickStation - t[index].station);
    if(min == diff)
    {
      if(t[index].totalEarned < earn)
      {
       min  = diff;
       earn = t[index].totalEarned;
       nearID = t[index].taxiId;
      }
    }
    if(min > diff )
    {
     min = diff;
     nearID = t[index].taxiId;
     earn = t[index].totalEarned;
    }
  }
 }
 return nearID;
}

// Current Status of all the taxi
void printTaxiDetails(Taxi t[])
{
 int index;
 for(index=0;index<TaxiNum;index++)
 {
  printf("\nTaxi ID %d , freeStatus %d Station : %c Earned %d ",t[index].taxiId+1,t[index].freeStatus, t[index].station, t[index].totalEarned);
 }
}


void displayHistory()
{
 int index, index2;
/* for(index=0; index < bookID - 1; index++)
  for(index2=index+1; index2 < bookID ; index2++)
    if(travel[index2].taxiNo < travel[index2].taxiNo)
     {
     travel[bookID] = taxiNo;
     travel[bookID].bookID = bookID;
     travel[bookID].customerID = custid;
     travel[bookID].from = pickStation[0];
     travel[bookID].to = dropStation[0];
     travel[bookID].pick = pickTime;
     travel[bookID].drop = dropTime;
     travel[bookID].amount = t[near_taxi_id].totalEarned;
     } */
 printf("\nBooking ID  Customer ID   From   To   Pick up time   Drop Time  Amount ");
 for(index =0; index < bookID ; index++)
 {
  printf("\n%d\t%d     \t%c    \t%c    \t%d   \t%d    \t%d",travel[index].bookID,travel[index].customerID,travel[index].from,travel[index].to, travel[index].pick,travel[index].drop,travel[index].amount );
 }
}

#include"bookTaxi.h"

// Driver program to test the taxi booking system
main()
{
 int iChoice=0, cust_id, pickTime;
 char  pickStation[1], dropStation[1];
 /* Load the information of taxi's from the database */
 loadTaxiDetails(t);
 init(tTbl); // Initialise the hash table
 while(iChoice != 3)
 {
  displayOptions();
  scanf("%d",&iChoice); // To select the option
  printTaxiDetails(t);
  switch(iChoice)
  {
   case 1: // To book a taxi          
           printf("\nCustomer ID: ");
           scanf("%d",&cust_id);
           printf("\nPick Up Station: ");
           scanf("%s",pickStation);
           printf("\nDrop Station : ");
           scanf("%s",dropStation);
           printf("\nPick Up Time: ");
           scanf("%d",&pickTime);
           bookTaxi(cust_id,pickStation,dropStation,pickTime);
           break;
   case 2:  displayHistory();
            printf("\nTravel History\n");
            break;
   case 3: 
            break;
   default: printf("Enter a valid case\n");
  }
 }
}

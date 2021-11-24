#include <stdio.h>   //including relevant header files

#include <stdlib.h>

#include<string.h>



struct trainDetails   //structure implementation of trains details.

{

    int trainNo; //stores train number

    char source[20]; //stores source

    char destination[20]; //stores destination

    int seatsLeft; //stores seats left in a train

    int fare; //stores fare of that train
};



struct trainDetails train[10]=  //initializing structure array trains of type trainDetails. This array stores information of 10 trains

{

    {1,"DEL","BOM",3,700}, //train Delhi to Mumbai:- train no.1, seats left=3, fare=700



    {2,"DEL","BLR",10,800}, //train Delhi to Bengaluru:- train no.2, seats left=10, fare=800



    {3,"DEL","CCU",5,650}, //train Delhi to Kolkata:- train no.3, seats left=5, fare=650



    {4,"DEL","AMD",7,500}, //train Delhi to Ahmedabad:- train no.4, seats left=7, fare=500



    {5,"DEL","PNQ",4,500}, //train Delhi to Pune:- train no.5, seats left=4, fare=500



    {6,"DEL","HYD",6,800}, //train Delhi to Hyderabad:- train no.6, seats left=6, fare=800



    {7,"DEL","LKO",8,500}, //train Delhi to Lucknow:- train no.7, seats left=8, fare=500



    {8,"DEL","JAI",9,400}, //train Delhi to Jaipur:- train no.8, seats left=9, fare=400



    {9,"DEL","NAG",1,600}, //train Delhi to Nagpur:- train no.9, seats left=1, fare=600



    {10,"DEL","BHO",6,450} //train Delhi to Bhopal:- train no.10, seats left=6, fare=450

};



struct passengerDetails  //structure implementation of ticket details/passenger details

{
    char passengerName[20]; //array to store passenger name

    int pTrainNo; //to store passenger train no

    char psource[20]; //to store passenger source

    char pdestination[20]; //to store passenger destination

    int pfare; //to store passenger fare

    int usefulVariable; //This variable is used later. access_SeatsLeft variable is stored here for each passenger.
                       // access_SeatsLeft is used to access structure train to decrement and increment seats during booking and cancelling

    int pnr; //to store passenger PNR

}passenger[60]={[0]={"empty",0,"empty","empty",0,0}}; //PNR (a global variable) is used as index to access this array.

                                                    //passenger[0] is initialized. This is not read in the program as PNR=0 does not exist


//Below functions for styling and formatting (coloring and blinking) are written


void yellow ()

{

 printf("\033[0;33m"); //Escape code text for color yellow

}



void  red()

{

 printf("\033[0;41m"); //Escape code text for color red

}

void cyan ()

{

 printf("\033[0;36m"); //Escape code text for color light blue (cyan)

}
void  green ()

{

 printf("\033[0;32m"); //Escape code text for color green

}

void  white ()

{

 printf("\033[0;37m"); //Escape code text for color white


}

void  bold_red ()

{

 printf("\033[1;31m"); //Escape code text for color bold red


}

void reset ()

{

 printf("\033[m"); //Escape code to change back to default (reset)

}

void blink ()

{

printf("\033[5;31m"); //Escape code text style for blinking text

}

//declaring functions

void welcome(); //welcome page



void menu(); //prints MAIN MENU



void enquiry(); // enquiry function



void storeInTextTrains();  //stores train details from structure to text file



void readTrainDetailsFromTxt(); //reads train details from text file to the console



void bookingFunction(); //Books ticket of passenger after asking relevant details



void cancelellation(); //Cancels passenger ticket by entering their pnr

//global variables are declared below which are used in multiple functions

int cancelled_PNR[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // This array stores canceled PNRs


int cancelling_counter=0,PNR=1; //cancelling_counter is used to iterate cancelled_PNR array
                                //initializing PNR to 1


int main() //implementation of all funcitons is done here

 {
   welcome(); //welcome page

   storeInTextTrains(); //stores train details from structure to text file

   menu(); //prints MAIN MENU

   return 0;
 }

void storeInTextTrains()//This function is used to extract data from structure and stores it to file 'details of trains.txt'
    {
        FILE *fpointer; //declaring a file pointer

        fpointer=fopen("details of trains.txt","w+"); //opening the text file in reading and writing mode

        fprintf(fpointer,"%s","Train No\t\tSource\t\tDestination\t\tSeats Left\t\tFare"); //printing heading in the text file

        fclose(fpointer); //closing the file pointer

        fpointer=fopen("details of trains.txt","a+"); //opening the above file in appending mode

        for(int k=0;k<10;k++) //used to iterate through train structure-array 10 times and prints its details in the file

        {

            fprintf(fpointer,"\n%i\t\t\t%s\t\t   %s\t\t\t   %i\t\t\t%i",train[k].trainNo,train[k].source,train[k].destination,train[k].seatsLeft,train[k].fare);

        }


        fclose(fpointer); //closing file pointer

    }



void readTrainDetailsFromTxt() //this function is used to read data from file 'details of trains.txt' to the system
    {

        system("clear"); //clear previous screen

        FILE *filePointer; //declaring a file pointer

        char buffer[50]; // a buffer array to store the details from the file

        filePointer=fopen("details of trains.txt","r");

        if(filePointer==NULL) //if the file pointer is unable to find the file then program will terminate

        {

            printf("File not found");
            exit(-1);

        }


        while(!feof(filePointer)) //this loop iterates till end of file

        {

        fgets(buffer,50,filePointer); //reads lines from file and stores in buffer

        printf("%s",buffer); //printing the lines on console

        }

        printf("\n");

        fclose(filePointer); //closing file pointer

        bold_red(); // bold red color for the below line

        printf("Press ENTER to go back to MAIN MENU\n");

        reset();

        getchar(); //takes input from user

        getchar();

        system("clear"); //clears the screen

        menu(); //prints MAIN MENU



    }

void enquiry() //function for enquiry
        {

        system("clear");

        char sor[30],dest[20]; //character array used to store name,source and destination of passenger temporarily for the function

        cyan(); //blue text till reset

        printf("Enter your source\n");

        reset();

        scanf("%s",sor);

        if(!strcmp(sor,"DEL")) //if condition checks if input is "DEL"

        strcpy(sor,"DEL"); //copying the string to sor

        else //for invalid source

        {

           blink(); //blinking text till reset

           printf("No trains from this source\n");

           reset();

           bold_red(); //bold red till reset

           printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

           reset();

           system("clear");

           menu(); //returns to MAIN MENU

         }

          cyan(); //cyan till reset

          printf("Enter your destination\n");

          reset();

          scanf("%s",dest); //scans destination entered by user

          int access_SeatsLeft=0; //variable access_SeatsLeft is used which gives train no of the passenger. This is used to access seats left

    //checking if destination is correct

         for( access_SeatsLeft=0;access_SeatsLeft<10;access_SeatsLeft++)//iterating through 10 trains.
                                                                           //Count is stored in access_SeatsLeft variable which is used later

             if (!(strcmp(dest,train[access_SeatsLeft].destination))) //comparing by if condition if destination is valid

                {
                goto label; //for valid destination skips below code
                }

        blink(); //blink till reset

        printf("No trains for this destination\n"); //prompt invalid destination

        reset();

        bold_red(); //bold red till reset.

        printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

        reset();

        system("clear"); menu();

        label:

        //checking if seats are left for that train

       if(train[access_SeatsLeft].seatsLeft<=0) //variable access_SeatsLeft is used which gives train no of the passenger. This is used to access seats left
                                                 //executed if seats are not left

        {

           blink();
           printf("No seats left\n");
           reset();
           bold_red();
           printf("Press ENTER to go back to MAIN MENU\n");
           getchar(); getchar();
           system("clear"); menu();
           reset();

        }


          else //if seats are left

            white();

            printf("Seats left are %d\n",(train[access_SeatsLeft].seatsLeft)); //shows no of seats left
             reset();
             bold_red();
             printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();
             reset();
             system("clear"); menu();
        }


void bookingFunction() //used to book passenger tickets
    {

        system("clear");

        char name[30],sor[30],dest[20]; //character array used to store name,source and destination of passenger temporarily for the function

        cyan(); //blue text till reset

        printf("Enter your name:-");

        scanf(" "); //escape whitespace error

        scanf("%[^\n]%*c", name); //used to input lines with space

        printf("Enter your source:-");

        scanf("%s",sor);

        if(!strcmp(sor,"DEL")) //if condition checks if input is "DEL"

      {

            strcpy(sor,"DEL"); //copying the string to sor

            reset();

      }

       else //for invalid source

       {

             blink(); //blinking text till reset

             printf("Enter a valid source\n");

             reset();

             bold_red(); //bold red till reset

             printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

             reset();

             system("clear");

             menu(); //returns to MAIN MENU

       }


          cyan(); //cyan till reset

          printf("Enter your destination:-");

          scanf("%s",dest); //scans destination entered by user

          reset();


        //checking if destination is correct

        //variable access_SeatsLeft is used which gives train no of the passenger. This is used to access seats left
        int access_SeatsLeft=0;
        for(access_SeatsLeft=0;access_SeatsLeft<10;access_SeatsLeft++) //iterating through 10 trains.
                                                                           // This is stored in access_SeatsLeft variable which is used later
               if (!(strcmp(dest,train[access_SeatsLeft].destination))) //comparing by if condition if is destination is valid
                {goto label;} //for valid destination skips below code

                blink(); //blink till reset

                printf("Please enter a valid destination\n"); //prompt invalid destination

                reset();

                bold_red(); //bold red till reset.

                printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

                reset();

                system("clear"); menu();



                label:

            //checking if seats are left for that train

        if(train[access_SeatsLeft].seatsLeft<=0) //above variable is used which gives train no of the passenger. This is used to access seats left
                                                 //executed if seats are not left
        {

           blink();

           printf("No seats left\n");

           reset();

           bold_red();

           printf("Press ENTER to go back to MAIN MENU\n");

           getchar();getchar();system("clear"); menu();

           reset();



        }



           else //if seats are left



            {


                           (train[access_SeatsLeft].seatsLeft)--; //decrement seats from struct train

                           printf("\n*************************************");

                           bold_red();

                           printf("\nPlease confirm below details:-\n");

                           reset();

                           cyan(); //printing details of passenger

                           printf("\nName-%s\n\nSource-%s\n\nDestination-%s\n\nTrain No-%d\n\nPNR NO-%d\n\nFare-%d\n\n",name,sor,dest,train[access_SeatsLeft].trainNo,PNR,train[access_SeatsLeft].fare);

                           reset();

                           white();

                           printf("Do you want to confirm the ticket?\n[Y or y (TO CONFIRM)/ N or n (TO NOT CONFIRM)]\n");

                           reset();

                           scanf(" ");

                           char temp;

                           scanf("%c",&temp); //getting user's character

                           if(temp=='Y'||temp=='y')
                            {
                                storeInTextTrains(); //update the file 'details of trains.txt'

                                white();

                                printf("Thank you for booking!\n");

                                reset();

                                //assigning values to structure passenger[]. This array is accessed by variable PNR

                                strcpy(passenger[PNR].passengerName,name);

                                strcpy(passenger[PNR].pdestination,dest);

                                strcpy(passenger[PNR].psource,sor);

                                passenger[PNR].pTrainNo=train[access_SeatsLeft].trainNo;

                                passenger[PNR].pfare=train[access_SeatsLeft].fare;

                                passenger[PNR].usefulVariable=access_SeatsLeft; //used to increment seats left

                                passenger[PNR].pnr=PNR;

                                FILE *fpointer2;//storing passenger details in a file

                                fpointer2=fopen("Passenger Details.txt","w+"); //this is used to erase a previous file with same name

                                fclose(fpointer2);

                                fpointer2=fopen("Passenger Details.txt","a+"); //opening file in append mode

                                fprintf(fpointer2,"%s","Passenger-Name\t\t Train No\t Source\t    Destination\t   Fare\t\tPNR\n\n");
                                                                        //printing heading in the file
                               for(int k=1;k<=PNR;k++) //printing all the tickets

                                {

                                for(int d=0;d<=cancelling_counter;d++) //if the PNR is canceled-PNR then this will skip it

                                {if(k==cancelled_PNR[d])

                                goto label3;} //skipping the printing of canceled PNR tickets

                                fprintf(fpointer2," %s\t\t     %d\t\t    %s\t\t%s\t    %d\t\t %d\n",passenger[k].passengerName,passenger[k].pTrainNo,passenger[k].psource,passenger[k].pdestination,passenger[k].pfare,passenger[k].pnr);
                                                                //to print valid PNR tickets
                                label3:;

                                }


                                fclose(fpointer2);

                                PNR++; // incrementing PNR for next passenger after successful booking

                                bold_red();

                                printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

                                reset();

                                system("clear"); menu();

                            }

                            else if(temp=='N'||temp=='n')

                            //this case handles when user does not confirm booking

                            {

                              (train[access_SeatsLeft].seatsLeft)++; //increment seats left as booking is canceled

                               printf("Ticket booking unsuccessful\n");

                               bold_red();

                               printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

                               system("clear"); menu();

                               reset();

                             }


                            else // case when invalid characters are entered

                             {

                                 blink();

                                 printf("Please enter a valid character\n");

                                 reset();

                                 bold_red();

                                 printf("Press ENTER to go back to MAIN MENU\n"); getchar();getchar();

                                 reset();

                                 system("clear"); menu();

                             }

            }



    }


void cancelellation() //Funciton to cancel the ticket
{

       system("clear");

       cyan();

       printf("Please enter your PNR\n");

       int m;

       scanf("%d",&m); //m contains the PNR of the ticket to be deleted

        if(m>=PNR) //if an invalid PNR is inputted, this condition will return to MAIN MENU
        {

          blink();

          printf("Please enter a valid PNR\n");

          reset();

          bold_red();

          printf("Press any key to go back to main menu\n"); getchar();getchar();

          reset();

          system("clear"); menu();

         }

        cancelled_PNR[cancelling_counter]=m; //storing canceled PNR inside cancelled_PNR array

        int k=passenger[m].usefulVariable; //usefulVariable is used to take access_SeatsLeft
                                           // access_SeatsLeft will be used to increment seats left in train structure
        train[k].seatsLeft++; //used to increment seats left in train structure, when ticket is canceled

        storeInTextTrains(); //updates the file 'details of trains.txt' to increment the seats

        printf("Here are your details\n%s\nSource-%s\nDestination-%s\nTrain No-%d\nPNR NO-%d\n",passenger[m].passengerName,passenger[m].psource, passenger[m].pdestination,passenger[m].pTrainNo,m);
//printing the details of passenger whose PNR is entered
        float flt=(passenger[m].pfare)/2;

        printf("your refund amount %.2f\n",flt); //showing the refund amount which is 50% of the fare

        FILE *fpointer3;

        remove("Passenger Details.txt"); //removing previous file to update new information

        fpointer3=fopen("Passenger Details.txt","w+"); //opening file in read and write mode

        fprintf(fpointer3,"%s","Passenger-Name\t\t Train No\t Source\t    Destination\t   Fare\t\tPNR\n\n");
             //printing heading in the file
        for(int k=1;k<PNR;k++) //printing all the tickets
        {

            for(int d=0;d<=cancelling_counter;d++) //if the PNR is canceled-PNR then this will skip it

            {if(k==cancelled_PNR[d])

            goto label4; //skipping the printing of canceled PNR tickets

        }

        fprintf(fpointer3," %s\t\t     %d\t\t    %s\t\t%s\t    %d\t\t %d\n",passenger[k].passengerName,passenger[k].pTrainNo,passenger[k].psource,passenger[k].pdestination,passenger[k].pfare,passenger[k].pnr);
                    //to print valid PNR tickets
            label4:;

        }

        fclose(fpointer3);

        printf("Ticket successfully canceled\n");

        cancelling_counter++; //incrementing cancelling_counter so that next element of  cancelled_PNR can be accessed

        bold_red();

        printf("Press any key to go back to main menu\n"); getchar();getchar();

        system("clear"); menu();

        reset();

}



void menu()  //to print the MAIN MENU

{

        yellow();

        printf("                                                                         MAIN MENU\n\n\n");

        cyan();

        printf("ENTER 1  FOR DETAILS OF TRAINS\n\n");

        printf("ENTER 2 FOR ENQUIRY\n\n");

        printf("ENTER 3 FOR TICKET BOOKING\n\n");

        printf("ENTER 4 FOR TICKET CANCELLATION\n\n");

        printf("ENTER 5 FOR EXIT\n");

        reset();

        int x;

        scanf("%d",&x);

        switch(x) //switch statements to run the required function when user enters that number

         {

            case 1: {storeInTextTrains();readTrainDetailsFromTxt();}

                break;

            case 2: enquiry();

                break;

            case 3: bookingFunction();

                break;

            case 4: cancelellation();

                break;

            case 5: exit(0);//welcome();

               break;

            default:

                {

                    blink();

                    printf("Please enter a valid number\n");

                    reset();

                    getchar();getchar();

                    menu();

                break;

                }



         }

}


void welcome()
{

        system("clear");

        white();

        printf("\t\t\t\t**************************************************************************************************\n");

        printf("\t\t\t\t**************************************************************************************************\n");

        printf("\t\t\t\t**************************************************************************************************\n");

        reset();

        yellow();

        printf("\t\t\t\t                                              WELCOME\n\n\n\n");

        reset();

        green();

        printf("\t\t\t\t                                     RAILWAYS RESERVATION SYSTEM \n\n\n");

        printf("\t\t\t\t                                          MIGRANT LABOURERS   \n\n\n");

        reset();

        white();

        printf("\t\t\t\t**************************************************************************************************\n");

        printf("\t\t\t\t**************************************************************************************************\n");

        printf("\t\t\t\t**************************************************************************************************\n");

        reset();

        bold_red();

        printf("\n\n\nPress Enter to continue.........\n");

        reset();

        getchar();

        system("clear");

        }




//Name: Jehad Hamayel
//ID: 1200348
#include <stdio.h>
void CostAndTime (float *,float  ,float*);//function prototype.
float round_money (float);//function prototype.
int main()
{
    float  customer,hoursVolume,avgCost,Cost;//Putting variables.
    int status ,month,year;
    FILE *in,*out;//Define the files.
    in = fopen("usage.txt","r");//Determine the input file name and file type(reading).
    out = fopen("charges.txt","w");//Determine the input file name and file type(Writing).
    status =fscanf(in,"%d%d",&month,&year);//Read the month and year from the file and put them in their own variables.
    fprintf(out,"Charges for %d/%d\n",month,year);//Print the month and year in the file.
    status = fscanf(in,"%f%f",&customer,&hoursVolume);//Read the user number and internet usage hours from the file.
        {
    while(status!=EOF)//Check the completion of reading from the file.
   {
    if(customer > 99999 || customer < 10000 )//Checking whether the customer number is from 5 digits or not.
        fprintf(out,"%.0f This value is not acceptable\n",customer);//Print the value as unacceptable.
    else{
        fprintf(out,"%.0f %.1f ",customer,hoursVolume);//Print the user number and the hours of internet use in the file.
        CostAndTime(&Cost,hoursVolume,&avgCost);//call function.
        fprintf(out,"%.2f %.2f\n",Cost,avgCost);//Print cost and the average cost per hour of the time used.
        }
    status = fscanf(in,"%f%f\n",&customer,&hoursVolume);//Read the user number and internet usage hours from the file.
    }
        }
    fclose(in);//Close the file.
    fclose(out);//Close the file.
    return 0;//Exit program.
}
void CostAndTime (float *Cost,float hoursVolume,float *avgCost)//function definition.
{                                                         //Check the cost of use and the average cost per hour of the time used.
    float cost=*Cost,valH=hoursVolume,avg;//Putting variables.
    cost = 0;
    if(hoursVolume<=10)//Cost check, if the number of hours consumed is less or equal to 10.
        cost = cost + (7.99);
    if(hoursVolume>10)//Cost check, if the number of hours consumed is greater than 10.
        {
        hoursVolume = hoursVolume-10;
        cost = cost +(7.99) + (hoursVolume*1.99);
        }
    hoursVolume=cost/(valH);//Find the average cost per hour of the time used.
    avg=hoursVolume;
    *avgCost =round_money(avg);//call function.
    *Cost= round_money (cost);//call function.
}
float round_money (float x)//function definition.
{                         //Round a number to the nearest two places after the comma.
    int a,b,n;//Putting variables.
    float c;
    n = x*1000;
    a = n +5;
    b= a /10;
    c = b / 100.0;
    return c;//Returns the rounded number
}

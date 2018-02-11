/*   This program prompts the user for an integer from the keyboard one at 
     a time. The program keeps track of the numbers of integers inputed so far, 
     the sum of the integers, the largest integer, the smallest integer, 
     the count of integers greater then 20, and the count of integers 
     between 10 and 90 inclusive. The program repeats until 99999 is entered.
	     Name: Joshua Johnston
	     Date: 10/18/2014
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define EndLoop 99999  // to exit loop

//   Function Declarations 

void getNumber(int* number);

void current_largest(int number, int* largestNum);

void current_smallest(int number, int* smallestNum);

void counter_20(int number, int* count_greater_20);

void between_counter(int number, int* count_between);

void print_results(int number_count, int smallestNum, int largestNum, 
	           int count_greater_20, int count_between, int numbers_sum, 
		   float numbers_average, float square_root);

int main(void)
{
// Local Declarations
   int number = 0;             //initialize number to 0
   int number_count = 0;       //initialize number_count to 0
   int number_count_test = 0;  //initialize test to 0
   int numbers_sum = 0;        //initialize sum to 0
   int largestNum = INT_MIN;   //initialize largest number to the lowest value of integer
   int smallestNum = INT_MAX;  //initialize the smallest number to the highest value of integer
   int count_greater_20 = 0;   //initialize count_greater_20 to 0
   int count_between = 0;      //initialize count_between to 0
   
   float numbers_average;      //holds the value of the average of the sum of numbers
   float square_root;          //holds the value of the square root of the sum of numbers
     
// statements
  
   while(number < EndLoop)     //loops until 99999 is inputted
	{
	   getNumber(&number); 
           number_count_test++;       //count each loop cycle for test
	     
	   if ( number == EndLoop && number_count_test <= 1) //end of loop test
	      {	
                   printf("No input was provided.\n");
		   return 1;
	      }
	    else
          	if (number == EndLoop && number_count_test > 1) //end of loop test
	           {
	              break;
	           }
		 else
			 
	           number_count++; 	 
	           current_smallest(number, &smallestNum); 
	           current_largest(number, &largestNum);   
	           counter_20(number, &count_greater_20);
	           between_counter(number, &count_between);	 
	           numbers_sum+= number;
	 
          } //end while   

// calculations
   numbers_average = ((float)numbers_sum / (float)number_count);
   square_root = sqrt((float)numbers_sum);

// print final output
   print_results( number_count, smallestNum, largestNum, 
	                count_greater_20, count_between, numbers_sum, 
	                numbers_average, square_root);  
  

   return 0;
} //main


/* ===================getNumber===================
   This function prompts the user for an integer.
   Pre: nothing
   Post: Data read and placed in the calling function
*/

void getNumber(int* number)
{    
    printf("Enter next integer: ");
    scanf("%d", number);	
    
    return;
} // getNumber

/* ===============current_largest==================
   This function keeps track of the largest integer
   that has been inputted. 
   Pre: number contains a integer value
   Post: largestNum is placed in the calling function
*/

void current_largest(int number, int* largestNum)
{
    
  if ( number > *largestNum )
        *largestNum = number;
   
  return;
} //current_largest

/* ==============current_smallest==================
   This function keeps track of the smallest integer
   that has been inputted.
   Pre: number contains a integer value
   Post: smallestNum is placed in the calling function
*/

void current_smallest(int number, int* smallestNum)
{ 
   if (number < *smallestNum)
       *smallestNum = number;
	
   return;

} //current_smallest

/* ================counter_20======================
   This function keeps track of how many integers 
   greater then 20.
   Pre: number contains a integer value
   Post: count_greater_20 is placed into the calling function
*/

void counter_20(int number, int* count_greater_20)
{
    
   if (number > 20)

       *count_greater_20 = *count_greater_20 + 1;
  
   return;
 } //counter_20

 
/* ======================between_counter=============================
   This function keeps track of integers between 10 and 90 inclusive.
   Pre: number contains a integer value
   Post: count_between is placed into the calling function
*/

void between_counter(int number, int* count_between)
{ 
   if ( number >= 10 && number <= 90 )	   
	    
        *count_between = *count_between + 1;
	
    else
		

   return;
} //between_counter

/* 
=============================print_results=================================
   This function prints all the results.
   Pre: number_count, smallestNum, largestNum, count_greater_20, 
        count_between, and numbers_sum contains an integer value. 
        numbers_average, and square_root contains real value
   Post: Prints
*/

void print_results(int number_count, int smallestNum, int largestNum, 
	           int count_greater_20, int count_between, int numbers_sum, 
	           float numbers_average, float square_root)
{
	printf("Number of integers:\t\t%6d\n", number_count);
	printf("Smallest: \t\t        %6d\n", smallestNum);
	printf("Largest: \t\t        %6d\n", largestNum);
	printf("Numbers greater then 20:        %6d\n", count_greater_20);
	printf("Numbers between 10 and 90:\t%6d\n", count_between);
	printf("Sum: \t\t\t        %6d\n", numbers_sum);
	printf("Average: \t\t\t  %6.2f\n", numbers_average);
	printf("Square root of the sum: \t  %6.2f\n", square_root);

	return;

} //print_results

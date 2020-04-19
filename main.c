#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000
int numrecords = 0;

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){
   
   Record records[MAX_RECORDS];
   for(int i = 0; i < MAX_RECORDS; i++){
     records[i].valid = -1;
   }

  //  FILE * fp = fopen("records1.txt", "wt");
  //   if(!fp){
  //   printf("Error creating a text file");
  //   return 0;
  //   }
  //   fprintf(fp, "========== test ==========");
   
   char user_input[64] = "";
   while(strcmp(user_input, "99") != 0){
      display_menu();
      printf("\nSelect a menu> ");
      fgets(user_input, 64, stdin);
      user_input[strlen(user_input)-1] = '\0';
      input_handler(user_input, records);
   }

   return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

   // TODO: Modify this function as you need

   if(!strcmp(input, "1")){
      add_a_record(records);
      while ((getchar()) != '\n');
      }
   else if(!strcmp(input, "2"))
      print_all_records(records);   
   else if(!strcmp(input, "3")){
      print_n_records(records);
      while ((getchar()) != '\n');
   }
   else if(!strcmp(input, "4"))
      save_to_txtfile(records);   
   else if(!strcmp(input, "5")){
      delete_record(records);
      while ((getchar()) != '\n');
   }
   else if(!strcmp(input, "6")){
     update_record(records);
     while ((getchar()) != '\n');
   }
   else if(!strcmp(input, "7")){
     defragment(records, numrecords);
   }
   else if(!strcmp(input, "99"))
      printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
   else
      printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

   // TODO: Modify this function as you need

   printf("******************************\n");
   printf(" Membership management system \n");
   printf("******************************\n");
   printf(" 1. Add a new member\n");
   printf(" 2. Print all members\n");
   printf(" 3. Print n number of records\n");
   printf(" 4. Save records to text file\n");
   printf(" 5. Delete an account\n");
   printf(" 6. Update Information\n");
   printf(" 7. Defragmentation\n");
   printf(" 99. Quit\n");
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 11
#define STACKSIZE 1000

/*
I used queue data structure with arrays. I implemented 3 queues arrays for different age groups.
I defined variables for each queue and arrays globally. I used a very basic queue structure with
one rear and one front. These are used for pointing the queue's beginning and ending.
Since queues are functioning as 'First in First Out', it has to have two pointer variable.
I used a array-based stack with size 40. This array used for storing each served customers information.
I used this structure, because served customers' informations has to be written in reversed order to the file.
Since stacks are functioning as 'Last In First Out'.
*/

char age_group_A[10][10];
char age_group_E[10][10];
char age_group_C[10][10];

int front_a = -1;
int rear_a = -1;

int front_c = -1;
int rear_c = -1;

int front_e = -1;
int rear_e = -1;


char stack[STACKSIZE][STACKSIZE];

int top = -1;



void NewCustomer(int flag,char data[10]) {
	if(flag==0){ // Elder
		if (rear_e == MAX - 1)
	    	printf("\0");
	  	else {
		    if (front_e == -1)
		    	front_e = 0;
		    rear_e++;
		    int i;
		    for(i=0;data[i] != '\0'; ++i){
		    	age_group_E[rear_e][i] = data[i];
			}
  		}
	}
	if(flag==1){ // Adult
		if (rear_a == MAX - 1)
	    	printf("\0");
	  	else {
		    if (front_a == -1)
		    	front_a = 0;
		    rear_a++;
		    int i;
		    for(i=0;data[i] != '\0'; ++i){
		    	age_group_A[rear_a][i] = data[i];
			}
  		}
	}
	if(flag==2){ // Child
		if (rear_c == MAX - 1)
	    	printf("\0");
	  	else {
		    if (front_c == -1)
		    	front_c = 0;
		    rear_c++;
		    int i;
		    for(i=0;data[i] != '\0'; ++i){
		    	age_group_C[rear_c][i] = data[i];
			}
  		}
	}
}
void ServeCustomers(int flag,int number) {

	while(number>0){
		if(flag ==0){ //Elder
			if (front_e == -1){
		    	char s1 [40] = "E\t*****";
				push_to_stack(s1);
		    }
		  	else {
			    char s1[40] = "E\t";
				add_s2_to_s1(s1,age_group_E[front_e]);
			    push_to_stack(s1);
			    front_e++;
			    if (front_e > rear_e)
			    	front_e = rear_e = -1;
		  	}
		  	number--;
		}

		if(flag ==1){//Adult
			if (front_a == -1){
		    	char s1[40] = "A\t*****";
		    	push_to_stack(s1);
		    }
		  	else {
			    char s1[40] = "A\t";
				add_s2_to_s1(s1,age_group_A[front_a]);
			    push_to_stack(s1);
			    front_a++;
			    if (front_a > rear_a)
			    	front_a = rear_a = -1;
		  	}
		  	number--;
		}

		if(flag ==2){ // Child
			if (front_c == -1){
		    	char s1[40] = "C\t*****" ;
		    	push_to_stack(s1);
		    }
		  	else {
				char s1[40] = "C\t";
				add_s2_to_s1(s1,age_group_C[front_c]);
			    push_to_stack(s1);
			    front_c++;
			    if (front_c > rear_c)
			    	front_c = rear_c = -1;
		  	}
		  	number--;
		}
	}
}

int compare_strings(char s1[],char s2[]){
	int flag = 1;
	int i;
    for (i = 0; s1[i] != '\0'; ++i) {
        if(s2[i] == s1[i])
        	flag=1;
        else
        	flag =0;
    }
    return flag;
}

void add_s2_to_s1(char p[], char q[]) {
   int length;
   int i;
   length = 0;
   while (p[length] != '\0') {
      length++;
   }
   i = 0;
   while (q[i] != '\0') {
      p[length] = q[i];
      i++;
      length++;
   }
   p[length] = '\0';
}


void push_to_stack(char string_push[]){
	if(top == -1){
		int i;
		for(i=0;string_push[i] != '\0'; ++i){
				stack[STACKSIZE - 1][i] = string_push[i];
		}
		top = STACKSIZE - 1;
	}
	else if(top == 0){

	}
	else{
		int i;
		for(i=0;string_push[i] != '\0'; ++i){
			stack[(top) - 1][i] = string_push[i];
		}
		top--;
	}
}
void pop_from_stack(FILE* file2){
	if(top == -1){

	}
	else{

		fprintf(file2,"%s\n", stack[top]);  //writes the output to the 'output.txt'
		if(top == STACKSIZE - 1){
	    	top = -1;
	  	}
	  	else{
	    	top++;
	  	}
	}
}

int main() {
	FILE* file = fopen("input1.txt", "r");
	FILE* file2 = fopen("output1.txt", "w");
	int umber_of_customers;
	char commands[1000];
	char customer_age_group[2];
	char customer_name[10];
	char E[1];
	char A[1];
	char C[1];
	E[0] = 'E';
	A[0] = 'A';
	C[0] = 'C';
	char ServeCustomersText [15] = "ServeCustomers";
	char NewCustomerText [15] = "NewCustomer";

	while(!feof(file) && fscanf(file, "%s",commands) != EOF){

		if(compare_strings(commands,ServeCustomersText)){
			fscanf(file, "%s %d[^\n]",customer_age_group,&umber_of_customers);
			if(compare_strings(customer_age_group,E))
				ServeCustomers(0,umber_of_customers);
			if(compare_strings(customer_age_group,A))
				ServeCustomers(1,umber_of_customers);
			if(compare_strings(customer_age_group,C))
				ServeCustomers(2,umber_of_customers);
		}
		else if(compare_strings(commands,NewCustomerText)){
			fscanf(file, "%s %s[^\n]",customer_age_group,customer_name);
			if(compare_strings(customer_age_group,E))
				NewCustomer(0,customer_name);
			if(compare_strings(customer_age_group,A))
				NewCustomer(1,customer_name);
			if(compare_strings(customer_age_group,C))
				NewCustomer(2,customer_name);
		}
	}

	while (top>0){
		pop_from_stack(file2);
	}

	fclose(file);
	fclose(file2);

}



#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include <time.h>

/* 
Muhammed Sefa Aydoðan
150150124
*/

using namespace std;

struct Sale
{
	string Country;
	string ItemType;
	string orderId;
	int UnitSold;
	double TotalProfit;	
	
	struct Sale *next;  
};

void add_to_linked_list(struct Sale** head_ref, string Country, string ItemType, string orderId, int UnitSold, double TotalProfit) 
{	//This function is a simple linkedlist add function. it adds variables to a new node and changed the head to this new node.
    
    struct Sale* new_sale = new Sale; // allocate a Sale
  
    // This block puts the data to the object
    new_sale->Country = Country; 
  	new_sale->ItemType = ItemType; 
  	new_sale->orderId = orderId; 
  	new_sale->UnitSold = UnitSold; 
  	new_sale->TotalProfit = TotalProfit; 	
  	/// ---- ///
   
    new_sale->next = (*head_ref);  // new_sale next pointer is set to the current list first object.
   
    (*head_ref) = new_sale;  // new head now is the new added object which is new_sale
}

struct Sale *getLastElement(struct Sale *currentNode) // this function is travels through the list to the end get returns the last element of that list.
{ 
    while (currentNode != NULL && currentNode->next != NULL) 
        currentNode = currentNode->next; 
    return currentNode; 
}
  
// This function takes the last element as the pivot,
//  
struct Sale *partition(struct Sale *head, struct Sale *end, struct Sale **new_head, struct Sale **new_end) 
{ 
    struct Sale *pivot = end; 
    struct Sale *prev = NULL;
	struct Sale *current = head;
	struct Sale *lastPoint = pivot; 
  
    //Because both the head and end of the list can change during partition, new_head and new_end has to be adjust properly.
    while (current != pivot) 
    { 
        if (current->Country > pivot->Country) // if the current nodes country is alphabeticly bigger than the pivot,
        { 	 								   // current point is moved to the next of the last node and lastnode is updated as current node. 
            if (prev) 
                prev->next = current->next; 
            struct Sale *temp = current->next; 
            current->next = NULL; 
            lastPoint->next = current; 
            lastPoint = current; 
            current = temp;           
        }
        
		else if(current->Country == pivot->Country) // if the countrys are matched,
		{
			if (current->TotalProfit > pivot->TotalProfit) // we checked the total profit of them,
        	{  												// if current is bigger than pivot, nothing is changed.prev node assigned to current.
	            if ((*new_head) == NULL) // If the first node has a value less than the pivot, it becomes the new head.
	                (*new_head) = current;	  
	            prev = current;  
	            current = current->next; 
	        }
	        else // if total profit of the current node is smaller than the pivot, 
        	{	// current point is moved to the next of the last node and lastnode is updated as current node. 
		        if (prev) 
		        	prev->next = current->next; 
		        struct Sale *temp = current->next; 
		        current->next = NULL; 
		        lastPoint->next = current; 
		        lastPoint = current; 
		        current = temp; 
        	}        		
		} 
		
        else // if current country come before than pivot in the alphabet, nothing is changed.prev node assigned to current.
        { 
            if ((*new_head) == NULL) 
                (*new_head) = current; 
  
            prev = current;  
            current = current->next; 
        }
    }  
    // If smallest element in the current list is the the pivot,
    if ((*new_head) == NULL) 
        (*new_head) = pivot; // pivot is now the new head of the list.
  
    (*new_end) = lastPoint; // Update new_end with the current lastPoint of the list. 
  
    return pivot; 
}  
 
struct Sale *quickSortRecursive(struct Sale *head, struct Sale *end) 
{	//recursive quickSort algoritm that takes end point as a pivot.

    // base condition if current linkedlist has elements less than 2
    if (!head || head == end) 
        return head; 
  
    struct Sale *new_head = NULL;
	struct Sale *new_end = NULL; 
  
    // To partition the list, partition function is called.
    // In this function, new_head and new_end will be updated. and pivot will be determined.
    struct Sale *pivot = partition(head, end, &new_head, &new_end); 
  
    // If pivot is the smallest element, recursion for the left part is not needed. 
    if (new_head != pivot) 
    {
        struct Sale *temp = new_head; 
        while (temp->next != pivot) 
            temp = temp->next; 
        temp->next = NULL; 
  
        // Recursion for the list before pivot(left part)
        new_head = quickSortRecursive(new_head, temp); 
  
        // Change the next of the last Sale of the left half to pivot 
        temp = getLastElement(new_head); 
        temp->next = pivot; 
    }  
    // Recursion for the list after the pivot element (right part)
    pivot->next = quickSortRecursive(pivot->next, new_end);  
    return new_head; 
} 

int main(int argc, char **argv){

	ifstream file;
	file.open("sales.txt");	
	ofstream sortfile;
	sortfile.open("sorted.txt");

	if (!file){
		cerr << "File cannot be opened!";
		return 1;
		}
	int N = atoi(argv[1]); //you should read value of N from command line
	string line;
	string Country;
	string ItemType;
	string orderId;	
	int UnitsSold;
	double TotalProfit;	
	struct Sale *sale = NULL;    
    
	getline(file, line); //this is the header line
	
	//sortfile << line << endl;
	for(int i = 0; i<N; i++){

		getline(file, Country, '\t'); //country (string)		
		getline(file, ItemType, '\t'); //item type (string)		 
		getline(file, orderId, '\t'); //order id (string)		
		file >> UnitsSold; //units sold (integer)				
		file >> TotalProfit; //total profit (float)		
	    getline(file, line, '\n'); //this is for reading the \n character into dummy variable.	    
	    add_to_linked_list(&sale,Country,ItemType,orderId,UnitsSold,TotalProfit);
	}
	struct Sale **head = &sale;
	
	clock_t t;
  	t = clock();
  	printf ("Clock is started.\n");  	
    (*head) = quickSortRecursive(*head,getLastElement(*head));
    //t = clock() - t;
  	printf ("Passed time for the algoritm (%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
    
	while (sale != NULL) 
    {
		sortfile << sale->Country << "\t" << sale->ItemType << "\t" << sale->orderId << "\t" << sale->UnitSold << "\t" << sale->TotalProfit << endl;       
        sale = sale->next; 
    }
    file.close();
    sortfile.close();
    
	return 0;
}


  

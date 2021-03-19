#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

#define HOTEL_LONGITUDE 33.40819
#define HOTEL_LATITUDE 39.19001
#define INFINITE 99999

/*
Muhammed Sefa Aydoðan
150150124
*/


int PQ_array_size;
int N = 0; //Number of elements that are stored in PQ


int get_left_child(int i) // left child can be accessed by 2*i
{
	if(((2*i) < PQ_array_size))
		if(i >= 1)
    		return 2*i;
	return -1;
}
int get_right_child(int i) // right child can be accessed by (2*i)+1
{
  	if((((2*i)+1) < PQ_array_size))
	  	if(i >= 1)
    		return (2*i)+1; 
	return -1;
}
int get_parent(int i)  // One element at index i in array, then its parent will be stored at index i/2. Index of root will be 1 in an array.
{
	if((i > 1))
		if(i < PQ_array_size)
    		return i/2;
  	return -1; //if its a root, root has no parent
}

void swap( float *x, float *y ) 
{
	float temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void min_heapify(float PQ[], int index){	// Complexity is O(logN). Goal is to find smallest value among index, left child and right child
	int right_child_index = get_right_child(index);
	int left_child_index = get_left_child(index);
	
	int smallest = index;
	
	if ((left_child_index <= N) && (left_child_index>0) && (PQ[smallest] > PQ[left_child_index]) )
		smallest = left_child_index;	
	
	if ((right_child_index <= N) && (right_child_index>0) && (PQ[smallest] > PQ[right_child_index]) )
		smallest = right_child_index;
	
	// If smallest is changed in the previous steps, then smallest element and the element that index shows has to swap
	if (smallest != index) 
	{
		swap(&PQ[index], &PQ[smallest]);
		min_heapify(PQ, smallest);
	}
}

float extract_minimum_value(float PQ[]) // Complexity is O(log N). Because min_heapify function's complexity is O(log N).
{
	float minimum = PQ[1];  // Index of root will be 1 in an array according to the our design.
  	PQ[1] = PQ[N]; // Last element of the PQ will be the first element of the PQ so that we can heapify after the removal of the smallest number.
  	N--; // number of elements in the heap will be decreased by one.
  	min_heapify(PQ, 1);
  	return minimum;
}

void decrease_value(float PQ[], int index, float value) // Complexity is O(log N).
{
	PQ[index] = value;
	while((index>1) && (PQ[index] < PQ[get_parent(index)])) // if the current nodes value is bigger than its parents,
	{
		swap(&PQ[index], &PQ[get_parent(index)]); // They have to be swapped.
		index = get_parent(index);
  	}
}

void insert(float PQ[], float value) // Complexity is O(log N). Because decrease_value function's complexity is O(log N).
{
	N++;
	PQ[N] = INFINITY;
	decrease_value(PQ, N, value);
}

float distance_to_hotel(float longitude,float latitude)
{
	return sqrt(pow((HOTEL_LONGITUDE-longitude),2) + pow((HOTEL_LATITUDE-latitude),2));
}

int randomize(float p) // update with a probability of p or an addition of a new taxi with a probability of 1 - p.	
{
	p = p*10;		
    float a;
	a = rand() % 10 + 1;
    if(a > p) // addition
    	return true;	
	else if(a <= p) // update
		return false;		
}
void update_value(float PQ[], int random_value) // A random taxis distance to the hotel will be decreases 0.01
{
	PQ[random_value] -= 0.01f;	
}

int main(int argc, char **argv) {
	
	clock_t t;
  	t = clock();	
	srand (time(NULL)); 
	
	ifstream file;
	file.open("locations.txt");

	if (!file)
	{
		cerr << "File cannot be opened!";
		return 1;
	}

	int m = atoi(argv[1]);
	float p = atof(argv[2]);
	float PQ[m];
	PQ_array_size = m;
	
	string line;	
	float longitude;
	float latitude;
	float distance;
	getline(file, line); //this is the header line
	bool flag;
	int update_counter = 0;
	int addition_counter = 0;
	
	for(int i = 0; i<m; i++){			
		flag = randomize(p); // if randomize function returns false, operation is update. 
		if(!flag)
		{ //If an operation is an update, a random taxi’s distance value will be decreased by 0.01.	
			if(N >0) // if heap has elements in it which means does not empty.
			{ 
				int random_value = rand() % N;
				update_value(PQ,random_value);	// 	Time complexity is O(N)
				update_counter ++; //Counter is increased because we need to know how many times does my program updated an information from the queue.
			}    					
		}
		else if(flag)
		{ //If an operation is an addition, new information will be read from the provided file, and the distance value of the new taxi will be added to the PQ.
			file >> longitude;
			file >> latitude;
			float distance = distance_to_hotel(longitude,latitude);
			insert(PQ,distance); // For N values, Time Complexity will become O(NlogN). N is the heap size.
			addition_counter++; //Counter is increased because we need to know how many times does my program added a new information to the queue.
		}
		if((i+1)%100==0)
		{
			cout << "The distance of the called taxi : " << extract_minimum_value(PQ) << endl;
		}		
	}
	
	cout << "\n" << endl;
	cout << "The number of taxi additions : " << addition_counter << endl;
	cout << "The number of taxi distance updates : " << update_counter << endl;   
	t = clock() - t;   
	cout << "Total running time in milliseconds : " << (((float)t)/CLOCKS_PER_SEC)*1000 << endl;
	
	file.close();
	return 0;
}


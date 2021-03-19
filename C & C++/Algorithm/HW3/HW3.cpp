/*
Student Name and Surname : Muhammed Sefa Aydoðan
Student ID: 150150124
*/

#include <iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

/* Global Value holders for max values in the folder */
int max_point=0;
int max_assist=0;
int max_rebound=0;
/*------*/

struct Node { // main node data structure for RBT
	string name;
	int point;
	int rebound;
	int assist;

	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
	int color; // 0 = Black, 1=Red
};
typedef Node *NodePtr;
struct MaxInformation {
	string max_point_name;
	string max_assist_name;
	string max_rebound_name;
	int max_point=0;
    int max_assist=0;
    int max_rebound=0;
};
MaxInformation maxInfos;

class RBT { //RBT is for Red Black Tree. This is the main operation class for Red Black Tree
private:
	NodePtr root;
	NodePtr TNULL;

	void constructorWithNULLPointer(NodePtr node, NodePtr parent){
		node->name = ' ';
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}
	NodePtr searchTreeHelper(NodePtr node, string key_name) {
		if (node == TNULL || key_name == node->name)
			return node;
		if (key_name > node->name) // Because of the property of RBT, if key_name is greater then the node, it goes right subtree
            return searchTreeHelper(node->right, key_name);
		else // Because of the property of RBT, if key_name is less then the node, it goes left subtree.
            return searchTreeHelper(node->left, key_name);
	}
	void fixInsert(NodePtr inserted_node){
		NodePtr uncle;
		while (inserted_node->parent->color == 1) { // while the parent of node is RED.
			if (inserted_node->parent == inserted_node->parent->parent->right) { //If node is the right child of grandParent
				uncle = inserted_node->parent->parent->left; // uncle
				if (uncle->color == 1) { // if uncle's color is red
					uncle->color = 0; // both uncle and parent is assigned to black and grandparent is assigned to red.
					inserted_node->parent->color = 0;
					inserted_node->parent->parent->color = 1;
					inserted_node = inserted_node->parent->parent; // grandparent is assigned to new node
				}
				else { //if uncle is black
					if (inserted_node == inserted_node->parent->left) { // if node is the left child,
						inserted_node = inserted_node->parent;  // parent is assigned to new node and right rotate.
						rightRotate(inserted_node);
					}
					inserted_node->parent->color = 0; // uncle is black and node is right child, it parents will be black
					inserted_node->parent->parent->color = 1; // grandparent will be red
					leftRotate(inserted_node->parent->parent);
				}
			}
			else {//If node is the left child of grandParent
                uncle = inserted_node->parent->parent->right;
				if (uncle->color == 1) { // if the node's uncle's color is red, gp's children will be black and grandparent will be red.
					uncle->color = 0; //black
					inserted_node->parent->color = 0; // black
					inserted_node->parent->parent->color = 1;
					inserted_node = inserted_node->parent->parent; // then grandparent is assigned to new node
				}
				else { // if the uncle is black,
					if (inserted_node == inserted_node->parent->right) { // if the new node is the right child,
						inserted_node = inserted_node->parent; // parent is assigned to new node
						leftRotate(inserted_node);
					}
					inserted_node->parent->color = 0;
					inserted_node->parent->parent->color = 1;
					rightRotate(inserted_node->parent->parent);
				}
			}
			if (inserted_node == root) {
				break;
			}
		}
		root->color = 0;
	}
	void preOrderPrinterHelper(NodePtr root, string node_identation) {
        if (root != TNULL){
            cout << node_identation;
            node_identation += "-"; //(IMPORTANT)if identation is wanted with a tab space, this can be changed to: "    ";
            string nodes_color;
            if(root->color == 1)
                nodes_color = "RED";
            else
                nodes_color = "BLACK";
		   cout<<"(" << nodes_color << ")" << root->name <<endl; //For PreOrder traversal, first the root,
		   preOrderPrinterHelper(root->left, node_identation); //then, left subtree
		   preOrderPrinterHelper(root->right, node_identation); //last, right sub tree
		}
	}
	void findMaximasHelper(NodePtr root) { // traverse in the tree and look for a bigger value than max values
	   	if (root != TNULL) {
		   if(max_point < root->point)
		   {
                max_point = root->point;
                maxInfos.max_point = max_point;
                maxInfos.max_point_name = root->name;
		   }
		   if(max_assist < root->assist)
		   {
                max_assist = root->assist;
                maxInfos.max_assist = max_assist;
                maxInfos.max_assist_name = root->name;
		   }
		   if(max_rebound < root->rebound)
		   {
                max_rebound = root->rebound;
                maxInfos.max_rebound = max_rebound;
                maxInfos.max_rebound_name = root->name;
		   }
		   findMaximasHelper(root->left);
		   findMaximasHelper(root->right);
		}
	}
public:
	RBT() {
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}
	NodePtr searchTree(string key_name) {
		return searchTreeHelper(this->root, key_name);
	}
	void leftRotate(NodePtr x) {// in left rotation, x goes in left direction while its right child goes up,
		NodePtr x_right_child = x->right;//  so, I keep its right child in the y variable
		x->right = x_right_child->left; // x's right child becomes its right child's left child.
		if (x_right_child->left != TNULL) {
			x_right_child->left->parent = x; // right child's left child's parent will be our x node.
		}
		x_right_child->parent = x->parent; // right child's parent will become x's parent while right child goes up.
		if (x->parent == nullptr) { // if x is root, its right child will be the new root
			this->root = x_right_child;
		}
		else if (x == x->parent->left) { // if x is the left child of its parent, right child will the new left child of the parent
			x->parent->left = x_right_child;
		}
		else { // if our x is right child, its right child will be the new right child of the parent
			x->parent->right = x_right_child;
		}
		x_right_child->left = x; // for last x will become its right child's left child and its right child will become its parent
		x->parent = x_right_child;
	}
	void rightRotate(NodePtr x) { // x goes down to right while its left child goes up.
		NodePtr x_left_child = x->left;
		x->left = x_left_child->right; // x' left child becomes its left child's right child
		if (x_left_child->right != TNULL) {
			x_left_child->right->parent = x; // vice versa
		}
		x_left_child->parent = x->parent; // x's left child's parent will be x's parent
		if (x->parent == nullptr) { // if x has no parent, it means that it was the root, so new root will be x's left child
			this->root = x_left_child;
		}
		else if (x == x->parent->right) { // if x was the right child, its left child will also the new right child of the parent
			x->parent->right = x_left_child;
		}
		else {
			x->parent->left = x_left_child;
		}
		x_left_child->right = x; // x will become the right child of its left child and
		x->parent = x_left_child; // x's parent will become its old left child
	}
	void insert(string name,int rebound,int assist, int point) {
		NodePtr node = new Node;
		node->parent = nullptr;
		node->name = name;
		node->point = point;
		node->assist = assist;
		node->rebound = rebound;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1; // new node must be alway red, so that we would not violated the rbt properties. black-height will be same.
        NodePtr x = this->root;
		NodePtr parent_x = nullptr;

		while (x != TNULL) {
			parent_x = x; // first holds the x so that if we go to next level, we hold the parent of it.
			if (node->name < x->name) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		//after finding an appropriate spot for the new node, we assign the parent node we found to the parent pointer.
		// parent_x is parent of x and our node.
		node->parent = parent_x;
		if (parent_x == nullptr) { // if parent is null, it means we are in the root
			root = node;
		}
		else if (node->name < parent_x->name){ // if nodes value less than parent, it becomes the left child.
			parent_x->left = node;
		}
		else { // if nodes value greater than parent, it becomes the right child.
			parent_x->right = node;
		}
		// if new node does not have a parent which means that it is a root node,so return nothing
		if (node->parent == nullptr){
			node->color = 0; // root node must be black
			return;
		}
		// if the grandparent is null, return nothing
		if (node->parent->parent == nullptr) {
			return;
		}
        //After these, we must fix our RBT to hold its states.
		fixInsert(node);
	}
	void preOrderPrinter() {
	    if (root) {
    		preOrderPrinterHelper(this->root,"");
	    }
	}
	void FindMaximums() {
	    if (root) {
    		findMaximasHelper(this->root);
	    }
	}
	void Update(string key_name,int rebound,int assist, int point) {
	    NodePtr updatedNode = searchTree(key_name); //find the corresponding node from the tree and update its properties
	    updatedNode->rebound += rebound;
	    updatedNode->assist += assist;
	    updatedNode->point += point;
	}
};

int main(int argc, char **argv) {
	ifstream file;
    string line;
    // Open an existing file
    file.open(argv[1]);
    string first_half_season,second_half_season,name,team;
    string rebound, assist, point;
    int i_rebound, i_assist, i_point,i_first_half_season,i_second_half_season;
    string first_line;
    getline(file, first_line);
    RBT rbt;
    bool isFirstSeasonEnded = false;
    bool isFirstEntry = false;
    int next_season = 2001; // Since seasons start from 2000, next season will be 2001. If a different input txt files will be changed, this has to be adjusted according to .
    while(!file.eof()){
        getline(file,first_half_season,'-');
        getline(file,second_half_season,',');
        stringstream sfirst_half_season(first_half_season);// since I got my inputs as a string, this function is used for converting strings to integers
        stringstream ssecond_half_season(second_half_season);
        sfirst_half_season >> i_first_half_season;
        ssecond_half_season >> i_second_half_season;
        getline(file,name,',');
	    getline(file,team,',');
	    getline(file,rebound,',');
	    getline(file,assist,',');
	    getline(file,point,'\n');

	    stringstream sRebound(rebound); // since I got my inputs as a string, this function is used for converting strings to integers
	    stringstream sAssist(assist);
	    stringstream sPoint(point);

	    sRebound >> i_rebound;
        sAssist >> i_assist;
        sPoint >> i_point;
        if(isFirstEntry == false){ // First input will be inserted so that in the future, we can check whether new operation is an update or an insert
            rbt.insert(name,i_rebound, i_assist,i_point);
            isFirstEntry=true;
        }else{
            if(i_first_half_season == next_season){
                cout << "End of the " << i_first_half_season-1<< "-" << i_second_half_season-1 << " Season" << endl;
                rbt.FindMaximums();
                cout << "Max Points : " << maxInfos.max_point << " - " << "Player Name: " << maxInfos.max_point_name  << endl;
                cout << "Max Assists : " << maxInfos.max_assist << " - " << "Player Name: " << maxInfos.max_assist_name  << endl;
                cout << "Max Rebs : " << maxInfos.max_rebound << " - " << "Player Name: " << maxInfos.max_rebound_name  << endl;

                maxInfos.max_point = 0;
                maxInfos.max_assist = 0;
                maxInfos.max_rebound = 0;
                max_assist = 0;
                max_point = 0;
                max_rebound = 0;
                if(isFirstSeasonEnded == false){ // Just for the first season, Tree will be printed, so this block will run one time
                    rbt.preOrderPrinter();
                    isFirstSeasonEnded=true;
                }
                next_season++;
            }
            NodePtr searched_key = rbt.searchTree(name);
            if(searched_key->name==name)
            {
                rbt.Update(name,i_rebound,i_assist,i_point);
            }
            else
            {
                rbt.insert(name,i_rebound, i_assist,i_point);
            }
        }
	}
    /*For the last season this block is added*/
	cout << "End of the " << i_first_half_season<< "-" << i_second_half_season << " Season" << endl;
    rbt.FindMaximums();
    cout << "Max Points : " << maxInfos.max_point << " - " << "Player Name: " << maxInfos.max_point_name  << endl;
    cout << "Max Assists : " << maxInfos.max_assist << " - " << "Player Name: " << maxInfos.max_assist_name  << endl;
    cout << "Max Rebs : " << maxInfos.max_rebound << " - " << "Player Name: " << maxInfos.max_rebound_name  << endl;
    /*------------*/


	return 0;
}

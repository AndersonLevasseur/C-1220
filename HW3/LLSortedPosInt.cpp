// Author:  Keith A. Shomper
// Date:    2/13/20
// Purpose: To implement a simple, sorted linked-list of positive integers

#include "LLSortedPosInt.h"

// The linked-list is constructed of Node elements
struct Node {
	int   key;
	Node* next;
};

void destroy(NodePtr list)
{
	if (list->next != nullptr)
	{
		destroy(list->next);
	}
	delete list;
}

// the following function is not a member function, it is a convenience
// function which exists to make the implementation of the LLSortedPosInt
// class more concise

// createNode() allocates a Node and initializes it with the
// given parameter values to simplify the initilization of a Node
static NodePtr createNode(int key, NodePtr p) {
	// allocate a new Node for storing the given key value
	NodePtr n = new Node;

	// store the key value and the next pointer
	n->key = key;
	n->next = p;

	// return the new Node to the caller
	return n;
}

// Student implementation of LLSortedPosInt begins here

// Constructors
LLSortedPosInt::LLSortedPosInt() {
	// create the sentinal Node at the head of the list - constructed
	head = createNode(HEAD_OF_LIST, nullptr);
}

LLSortedPosInt::LLSortedPosInt(int key) : LLSortedPosInt() {
	// create the sentinal Node at the head of the list

	// add the single element key, as long as it is positive
	if (key > 0)
		//sorted
	{
		insert(key);
	}
}

LLSortedPosInt::LLSortedPosInt(int* keys, int n) : LLSortedPosInt() {
	// create the sentinal node at the head of the list
	// add new Nodes for each positive value in keys
	for (int i = 0; i < n; i++)
		//sorted
	{
		if (keys[i] > 0)
		{
			insert(keys[i]);
		}
	}
}

LLSortedPosInt::LLSortedPosInt(const LLSortedPosInt& l) : LLSortedPosInt() {
	// create a deep copy of the input list l

	Node* next = l.head->next;
	Node* copy = head;

	while (next != nullptr)
	{
		copy->next = createNode(next->key, nullptr);
		next = next->next;
		copy = copy->next;
	}

}

// Destructor
LLSortedPosInt::~LLSortedPosInt() {
	// free the Nodes in *this, including the sentinal
	destroy(head);
}

// Assignment Operator
LLSortedPosInt& LLSortedPosInt::operator=
(const LLSortedPosInt& l) {
	// handle self assignment
	if (this == &l) {
		return *this;
	}

	// free old elements of the list before the new elements from l are assigned
	Node* compNext = l.head->next;

	destroy(this->head);
	head = createNode(HEAD_OF_LIST, nullptr);


	while (compNext != nullptr)
	{
		insert(compNext->key);
		compNext = compNext->next;
	}

	// if necessary, rebuild the sentinal

	// build the list as a deep copy of l
	// return *this
	return *this;
}

// Print Operator (a non-member function)
ostream& operator<<  (ostream& out, const LLSortedPosInt& l) {
	// an empty list will be printed as <>
	// a singleton list (a list having one key value k) will be
	//     printed as <k>
	// a list having multiple keys such as 2, 5, 7 will be printed
	//     as <2, 5, 7>

	// print the left angle bracket
	cout << '<';
	// print the keys in the list l
	Node* next = l.head->next;
	if (next != nullptr)
	{
		cout << next->key;
		while (next->next != nullptr)
		{
			next = next->next;
			cout << ", " << next->key;
		}
	}
	// print the right angle bracket
	cout << '>';
	return out;
}

// Boolean Functions
bool LLSortedPosInt::isEmpty() const {
	// return true if only the sentinal is in the list; return false otherwise
	if (head->next == nullptr)
	{
		return true;
	}
	return false;
}

bool LLSortedPosInt::containsElement(int key) const {
	// return true if key is in the list; return false otherwise
	Node* next = head->next;
	while (next != nullptr)
	{
		if (next->key == key)
		{
			return true;
		}
		next = next->next;
	}
	return false;
}

// Other Operator Member Functions
bool LLSortedPosInt::operator==(const LLSortedPosInt& l) const {
	// compare the Nodes in *this with the Nodes in l
	Node* next = head->next;
	Node* copyNext = l.head->next;
	while ((next != nullptr && copyNext != nullptr) || (next == copyNext)/*happens if they both point to Null or are a shallow copy of one another*/)
	{
		if (next == nullptr) { return true; }
		if (next->key != copyNext->key) { return false; }
		next = next->next;
		copyNext = copyNext->next;
	}
	// if all Node key values in *this match the cooresponding
	//  Node key values in l, then the lists are equivalent
	return false;
}

bool LLSortedPosInt::operator!=(const LLSortedPosInt& l) const {
	// do the opposite of operator==
	if (l == *this) { return false; }
	return true;
}

// Other Operator Functions (non-member functions)
LLSortedPosInt  operator+ (const LLSortedPosInt& l1,
	const LLSortedPosInt& l2) {
	// create a copy of l1 and add each element of l2 to it in 
	LLSortedPosInt sum = l1;
	// the correct (sorted ascending) order, allow duplicates
	Node* next = l2.head->next;
	while (next != nullptr)
	{
		sum.insert(next->key);
		next = next->next;
	}
	return sum;
}

LLSortedPosInt  operator- (const LLSortedPosInt& l1,
	const LLSortedPosInt& l2) {
	// copy l1 and remove all of l2 from l1, taking care to 
	// reclaim any storage -- do not to remove the sentinal Node
	LLSortedPosInt diff = l1;
	Node* next = l2.head->next;

	while (next != nullptr) {
		diff.remove(next->key);
		next = next->next;
	}

	return diff;
}

// The following helper functions are provide to assist you in
// building the class--these helper functions are useful in
// several places among the functions you will write--take time
// to learn what they do

// insert() inserts an element in the linked list in sorted order
void LLSortedPosInt::insert(int key) {

	// setup pointers to walk the list
	NodePtr npp = head;
	NodePtr npc = head->next;

	// walk the list, searching until the given key value is exceeded
	while (npc != NULL && npc->key <= key) {
		npp = npc;
		npc = npc->next;
	}

	// insert the new value into the list
	npp->next = createNode(key, npc);
}

// remove() removes an element from the list (if it is present)
void LLSortedPosInt::remove(int key) {

	// negative values should not be stored in the list
	if (key <= 0) {
		return;
	}

	// setup pointers to walk the list
	NodePtr npp = head;
	NodePtr npc = head->next;

	// search the list until the end (if necessary)
	while (npc != NULL) {

		// if the key value is found, then splice this Node from the list and
		// reclaim its storage
		if (npc->key == key) {
			npp->next = npc->next;
			delete npc;
			break;
		}

		// walk the pointers to the next Node
		npp = npc;
		npc = npc->next;
	}
}
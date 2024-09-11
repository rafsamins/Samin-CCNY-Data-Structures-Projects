// Implementation File for Sequence //
// File Name: sequence3.cpp
// Class Implemented: sequence //
// Invariants: //
// 1. The items in the sequence are stored in a linked list. //
// 2. The head pointer of the list is stored in the member variable head_ptr //
// 3. The tail pointer of the list is stored in the member variable tail_ptr //
// 4. The total number of items in the list is stored in the member variable
// many_nodes //
// 5. If there is a current item, then the cursor points to that node //
// 6. If there is an item before the current item, then the precursor points
// to that node //

// Value Semantics: //
// 1. If the source sequence has no current item, then simply copy the source’s
// linked list with list_copy. Then set both precursor and cursor to the
// null pointer
// 2.  If the current item of the source sequence is its first item, then copy
// the source’s linked list with list_copy. Then set precursor to null, and set
// cursor to point to the head node of the newly created linked list.
// 3. If the current item of the source sequence is after its first item, then
// copy the source’s linked list in two pieces using list_piece from Self-Test
// Exercise 24 on page 258. The first piece that you copy goes from the head
// pointer to the precursor; the second piece goes from the cursor to the tail
// pointer. Put these two pieces together by making the link field of the
// precursor node point to the cursor node. The reason for copying in two
// separate pieces is to // easily set the precursor and cursor.

#include "sequence3.h"
#include "node1.h"
#include <cassert>
#include <cstdlib>
using namespace std;

namespace main_savitch_5 {
// GIVEN THIS FIRST IN LIST_PIECE.TXT//
void list_piece(const node *start_ptr, const node *end_ptr, node *&head_ptr,
                node *&tail_ptr) {
  head_ptr = NULL;
  tail_ptr = NULL;
  if (start_ptr == end_ptr)
    return;
  list_head_insert(head_ptr, start_ptr->data());
  tail_ptr = head_ptr;
  start_ptr = start_ptr->link();
  while (start_ptr != end_ptr) {
    list_insert(tail_ptr, start_ptr->data());
    tail_ptr = tail_ptr->link();
    start_ptr = start_ptr->link();
  }
}
// void list_piece creates a new linked list. head_ptr and tail_ptr are the head
// and tail pointers for a new list that contains the items from start_ptr up to
// but not including end_ptr. start_ptr and end_ptr are pointers to nodes on the
// same linked list, with the start_ptr node at or before the end_ptr node. The
// head pointer and tail pointer are null because we want them to be empty when
// the program first starts running.

// if there is an empty list, then head_ptr and tail_ptr are both set to NULL
// and then it just returns.

// now we want to make the head node for the new list. so it is designed to
// insert a new node at the beginning of the list. it updates head pointer to
// point to the new node and its inserted at the head of the list. Since the new
// list currently contains only one node, the head and tail of the list are the

// now moving on to the third case where we have multiple pieces of data being
// inserted. so the start ptr is basically just moving to the next node because
// the first node is already taken by the head of the new list. now there is a
// while loop, while the start pointer does not equal to the end pointer, it
// will keep moving to the next node and inserting it into the new list. BUT it
// is adding to the tail. and as more and more data keeps getting inputted, the
// while loops keep running as long as the condition is met.

  
// DEFAULT CONSTRUCTOR //
sequence::sequence() { // O(1) //
  head_ptr = NULL;
  tail_ptr = NULL;
  cursor = NULL;
  precursor = NULL;
  many_nodes = 0;
}
// implementing the default constructor here. setting everything to null and
// empty and 0 because when we run the program, we want the sequence to be
// empty. and we do not want any prexisting data to be there which can cause
// errors. and because it is a deault constructor, everything is essentially set
// to default.

  
// START MEMBER FUNCTION //
void sequence::start() // O(1) //
{
  precursor = NULL;
  cursor = head_ptr;
}
// implementing the start function here. we want to start the program. so the
// precursor is empty and the cursor is pointing to the head, which is the first
// node

  
// ADVANCE MEMBER FUNCTION //
void sequence::advance() // O(1) //
{
  assert(is_item());
  precursor = cursor;
  cursor = cursor->link();
  if (cursor == NULL) {
    precursor = NULL;
  }
}
// implementing the advance function here. we want to essentially just move one
// aka advance one when we run this. as always, it checks if there is a proper
// item in the list. if there is a proper item, then it sts precursor to cursor
// and then moves cursor the next node.

  
sequence::~sequence() {
  list_clear(head_ptr);
  many_nodes = 0;
}
// implementing the destructor here. we want to clear the list and set many
// nodes equal to 0 because we are basically deleting everything here

  
// CURRENT MEMBER FUNCTION //
sequence::value_type sequence::current() const // O(1) //
{
  assert(is_item());
  return cursor->data();
}
// implementing the current constant member function. this is basically just
// checking whatthe current item is and then returning what it is. first it
// checks if there is an eligible item. and then it makes sure the cursor points
// to the data and then returns it.

  
// REMOVE CURRENT MEMBER FUNCTION //
void sequence::remove_current() // O(1)
{
  assert(is_item());
  if (cursor == head_ptr) {
    list_head_remove(head_ptr);
    cursor = head_ptr;
    if (cursor == NULL)
      tail_ptr = NULL;
  } else {
    list_remove(precursor);
    cursor = precursor->link();
    if (cursor == NULL) {
      tail_ptr = precursor;
      precursor = NULL;
    }
  }
  many_nodes--;
}
// implementing the remove current function. it is just removing the curren
// item. so first it checks if there even is an item. now if the cursor aka the
// current node is the head pointer, then it just removes the first node. now if
// the cursor aka the current node is null, then the tail pointer is null and
// there are no more nodes on the list.

// now if the cursor is not the head pointer, then it removes the node that is
// after precursor. and so cursor is poining to the node after the removed node.
// if the node we removed was the last node, then the tail pointer is set to the
// precursor. and then at the end it decrements many nodes which is like used.
// since we removed a node, the total number of nodes in the list also
// decreases.

  
// ------------------------------------------------------------------------- //
// COPY CONSTRUCTOR //
sequence::sequence(const sequence &source) // O(n)
{
  if (source.cursor == NULL) { // There is no current item in the source list:
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    cursor = precursor = NULL;
  } else if (source.precursor ==
             NULL) { // The current item in the source is at its head:
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    cursor = head_ptr;
    precursor = NULL;
  } else { // The current item in the source is not at its head:
    list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
    list_piece(source.cursor, NULL, cursor, tail_ptr);
    precursor->set_link(cursor);
  }
  many_nodes = source.many_nodes;
}
// implementing another constructor here. this constructor has paramater of
// source and it is a constant reference. this is a copy constructor because of
// its syntax. the syntax is: const classname &object.

// this copy constructor has multiple cases. first case, if the source list is
// empty, then it copies the entire list. second case, if the prescursor is
// null, then the cursor is not at the head pointer so now cursor is set to the
// head pointer. third case, if the prescursor is not null, then the cursor,
// then list is in two pieces.

  
// AUTOMATIC ASSIGNMENT OPERATOR //
void sequence::operator=(const sequence &source) // O(n)
{
  if (this == &source)
    return;

  list_clear(head_ptr);
  if (source.cursor == NULL) { // There is no current item in the source list:
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    cursor = precursor = NULL;
  } else if (source.precursor == NULL) {
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    cursor = head_ptr;
    precursor = NULL;
  } else { // The current item in the source is not at its head:
    list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
    list_piece(source.cursor, NULL, cursor, tail_ptr);
    precursor->set_link(cursor);
  }
  many_nodes = source.many_nodes;
}
// this is implementing the assignment operator. its used to assign one object
// to another.if the current object is the same as the source, it means theyre
// the same so it returns.

// now it then clears the current list to it is deallocated. if the
// source.cursor is empty, it means no current item in the source list, it
// copies the entire list to the current objects. and since there is nothing to
// point too, both cursor and precursor are null.

// ELSE if the precursor is null, then the current item in the source is at its
// head. IT COPIES THE LIST FROM HEAD POINTER TO THE OBJECTS. AND THEN THE
// CURSOR POINTS TO THE HEAD AND PRECURSOR IS NULL.

// else if the current ite, is not at the head, then it copies the list into two
// parts. the first includes nodes from source head pointer upto but not
// including cursor. the second part is copying from the source cursor to the
// end of the list. and then the precursor is set to the cursor.

  
// INSERT MEMBER FUNCTION //
void sequence::insert(const value_type &entry) // O(1) //
{
  if (precursor == NULL) { // The new entry goes at the front:
    list_head_insert(head_ptr, entry);
    cursor = head_ptr;
    if (tail_ptr == NULL)
      tail_ptr = head_ptr; // There were no other nodes.
  } else {                 // The new entry goes between precursor and cursor,
    // and the cursor is set to point at this new entry.
    list_insert(precursor, entry);
    cursor = precursor->link();
  }
  many_nodes++;
}
// implementing the insert function. it also has a paramter called entry. based
// on the other sequence classes in proj2 and proj3, insert is before. meaning
// if we have 4 5 6 and the current item is 5, insert will go before 5. if the
// precursor is null, then it will insert at the head.

// the else is when the new entry needs to inserted between two nodes. it is
// between the precursor and the cursor. and then at the end it increments many
// nodes which is basically like used, it keeps track of how many nodes there
// are.

  
// ATTACH MEMBER FUNCTION //
void sequence::attach(const value_type &entry) // 0(1)
{
  if (tail_ptr == NULL)
    insert(entry);           // First node of the list
  else if (cursor == NULL) { // The new entry goes after the current tail:
    list_insert(tail_ptr, entry);
    precursor = tail_ptr;
    cursor = tail_ptr = precursor->link();
    ++many_nodes;
  } else { // The new entry goes after the current cursor:
    list_insert(cursor, entry);
    precursor = cursor;
    cursor = precursor->link();
    if (tail_ptr == precursor)
      tail_ptr = cursor;
    many_nodes++;
  }
}
// implementing the attach function, it also has a parameter called entry.
// similar to previous projects, attach is after, so if we have 4 5 6 and the
// current item is 5 and the user inputs 10, then the linked list will be 4 5
// 10 6.

// if the tail pointer is empty meaning that the sequence is empty, then it just
// uses insert and whatever the user enters as the first node of the list. now
// if the cursor is null it means that there is no current node set, it puts
// entry after the tail pointer and then the precursor points to the last node.
// and then cursor and tail are set to the last node.and then at the end it
// increments many nodes which is basically like used, it keeps track of how
// many nodes there are.

} // namespace main_savitch_5

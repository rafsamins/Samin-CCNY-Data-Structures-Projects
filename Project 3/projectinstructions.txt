The Assignment:
You will implement and test a revised sequence class that uses a dynamic array to store the items.

Purposes:
Ensure that you can write a small class that uses a dynamic array as a private member variable.

Before Starting:
Read all of Chapter 4.

Files that you must write and turn in (Please do not turn in other files!!):
1.	sequence2.h: The header file for the new sequence class. Actually, you don't have to write much of this file. If some of your member functions are implemented as inline functions, then you may put those implementations in this file too. By the way, you might want to compare this header file with your first sequence header file sequence1.h, the new version no longer has a CAPACITY constant because the items are stored in a dynamic array that grows as needed. But there is a DEFAULT_CAPACITY constant, which provides the initial size of the array for a sequence created by the default constructor.
2.	sequence2.cpp: The implementation file for the new sequence class. You will write all of this file, which will have the implementations of all the sequence's member functions.


Other files that you may find helpful (but you do not need to turn in):
1.	sequence_test.cpp: This is in fact the same interactive test program that you used with the earlier sequence. If you want to use it with the new sequence, then copy it to your directory and open it with your editor.
2. seq_ex2.cxx: A non-interactive test program that will be used to grade the correctness of your new sequence class.

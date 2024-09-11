The Assignment:
You will implement and test a revised sequence class that uses a linked list to store the items.

Purposes:
Ensure that you can write a small class that uses the linked list toolkit to create and manipulate a linked list.

Before Starting:
Read all of Chapter 5, with particular attention to Sections 5.3 and 5.4.

Due Date:
Monday, July 1st before class 

How to Turn In:
	Upload the sequence3.h, sequence3.cpp, node1.h, node1.cpp and screenshot of the output   
            of sequence_exam3.cpp to Canvas.

Files that you must write and turn in:
1.	sequence3.h: The header file for the new sequence class. Actually, you don't have to write much of this file. Just start with our version and add your name and other information at the top. If some of your member functions are implemented as inline functions, then you may put those implementations in this file too. By the way, you might want to compare this header file with your first sequence header file (sequence1.h), and second sequence header file (sequence2.h). The linked list version no longer has a CAPACITY constant nor a DEFAULT_CAPACITY constant because the items are stored on a linked list instead of an array.
2.	sequence3.cpp: The implementation file for the new sequence class. You will write all of this file, which will have the invariant of the sequence class, the implementations of all the member functions of the sequence class, and the Big-Os of these functions.
3.	node1.h and node1.cpp: Copy these files. They contain the linked list toolkit from Section 5.2. You may use these files without changing them. However we only provide the documentation for the function list_piece (see Self-Test Exercise 24 on page 258). You may need to write an implementation of this function if you are going to use it in writing your copy constructor and overloading your assignment operator. If you do make changes, please turn them in.


Other files that you may find helpful:
1.	sequence_test.cpp: This is the same interactive test program that you used with the earlier sequences. This is exactly what we expect for the information hiding of the class - the users do not need to know how the class is implemented (both the member variables and the functions) as far as the interfaces (the prototype of the member functions) remain the same. So if you want to use the test program with the new sequence, the only thing you need to do is to copy it to your directory and open it with your editor. Then change the statements
2.	sequence_exam3.cpp: A non-interactive test program that will be used to grade the correctness of your new sequence class. The points given by the program will only be served as a reference; we are going to look into your code and your analysis (in the form of comment lines) for actual grading.

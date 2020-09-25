#ifndef PROCESS1_H_
#define PROCESS1_H_

void do_one_thing(int *); //pass by ref
void do_another_thing(int *);
void do_wrap_it_up(int, int); //pass by value

#endif // PROCESS1_H_

//#include <stdio.h>
// void do_one_thing(int *); //call-by-reference
// void do_another_thing(int *);
// void do_wrap_up(int, int); //call-by-value
//
//int r1 = 0, r2 = 0;

//declaration of a var/func does not allocate memory
//definition of a var/func allocates the memory

//extern int //extern extends the visibility of a var or func
//main(void)
//{
//	do_one_thing(&r1);
//	do_another_thing(&r2);
//	do_wrap_up(r1, r2);
//	return 0;
//}

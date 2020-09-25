#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>    //access to POSIX-OS API
#include <sys/types.h> //basic derived types
#include <sys/ipc.h>   //inter-process communication struct
#include <sys/shm.h>   //shared memory facility
#include <sys/wait.h>  //declarations for waiting
#include "Process1.h"

//void do_one_thing(int *); //pass by ref
//void do_another_thing(int *);
//void do_wrap_it_up(int, int); //pass by value

int shared_mem_id;
int *shared_mem_ptr; //ptr to integer type
int *r1p;
int *r2p;
int main(void)
{

    pid_t child1_pid, child2_pid;
    int status;

    /* initialize shared mem seg. */
    //returns the shared mem identifier for given key
    shared_mem_id = shmget(IPC_PRIVATE, 2 * sizeof(int), 0660);

    //Attaches the seg identified by above and returns address of mem seg
    shared_mem_ptr = (int *)shmat(shared_mem_id, (void *)0, 0);
    r1p = shared_mem_ptr;
    r2p = (shared_mem_ptr + 1);

    *r1p = 0;
    *r2p = 0;

    //if fork returns 0, child code continues, for parent code, return is childs pid
    if ((child1_pid = fork()) == 0)
    {
        /*first  child process*/
        do_one_thing(r1p);
        exit(0);
    }
    /* parent */
    if ((child2_pid = fork()) == 0)
    {
        /* second child process */
        do_another_thing(r2p);
        exit(0);
    }

    //wait until termination of child (default); ie., it suspends the execution of current process (parent in this case), until once of its child terminates
    waitpid(child1_pid, &status, 0);
    waitpid(child2_pid, &status, 0);

    do_wrap_it_up(*r1p, *r2p);
    return 0;
}

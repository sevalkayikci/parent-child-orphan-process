#include <stdio.h>//stdio.h for printf function
#include <unistd.h>//unistd.h for system calls and constants and fork function
#include <sys/types.h>//sys/types.h for data types pid_t and uid_t (for pid and uid process)
#include <sys/wait.h>//sys/wait.h for wait and WIFEXITED funtions

int main(){

    pid_t child_pid = fork(); //for is used to create a new process aka creating the child process

        if (child_pid < 0) { //if fork function is failed it will return to error - checks child_pid for that
        perror("Fork failed");
        return 1;
    }
        if (child_pid == 0) { 
               printf("CHILD PROCESS:\n");
               printf("pid: %d\n", getpid()); //returns the process ID (pid) of the current process
               printf("parent id: %d\n", getppid());//returns the parent process ID (ppid) of the current process
               printf("user id: %d\n", getuid());//returns the user ID (uid) owner of the current process
            printf("child process is done...now exiting the child process");
        return 0;
    } //checks if the fork function worked and if it is the child process, if it is the child process it will continue in this block
       
        else{ //if child process didnt terminated parent process will continue 

               printf("PARENT PROCESS:\n");
               printf("parent-child pid: %d\n", child_pid);//identifies the pid of child within parent process
               printf("pid: %d\n", getpid()); //returns the process ID (pid) of the current process
               printf("parent id: %d\n", getppid());//returns the parent process ID (ppid) of the current process
               printf("user id: %d\n", getuid());//returns the user ID (uid) owner of the current process

        int status;
        pid_t terminated_pid = wait(&status); //parent waits for child to terminate
        //status:information about how the child process terminated
                if (terminated_pid == -1) {//if wait() failed returned with -1 error message will be executed
            perror("Error waiting for child");
            return 1;
        }
}
    return 0;
} 
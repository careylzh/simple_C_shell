/*
 * daemonize.c
 * This example daemonizes a process, writes a few log messages,
 * sleeps 60 seconds and terminates afterwards.
 */

// To test compile: gcc Daemonize.c -o summond
// ./summond
// see output at Console : search the log message or process name i.e: summond
// can check using ps aux | grep summond
// for better formatted:  ps -ejf | egrep 'STIME|summond'

#include "shellPrograms.h"

//TODO: change to appropriate path
char *path = "../logfile_test.txt";
//controlling terminal becomes the root at the end of create_daemon cuz of the chdir("/") line. meaning the logfile_test.txt will be created at root. before the second fork

/*This function summons a daemon process out of the current process*/
static int create_daemon()
{
    /* TASK 7 */
    // Incantation on creating a daemon with fork() twice
    pid_t child = fork();     // 1. Fork() from the parent process
     // 2. Close parent with exit(1) 
    if (child == -1){
        printf("fork unsuccessful");
        return 1;       
    } else if (child > 0){
        exit(1);
    }

    pid_t sid = setsid();     // 3. On child process (this is intermediate process), call setsid() so that the child becomes session leader to lose the controlling TTY

    if (sid == -1) {
        exit(1);
    }

    // 4. Ignore SIGCHLD, SIGHUP
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    // 5. Fork() again, parent (the intermediate) process terminates
    child = fork(); //intermediate process calls fork, creates target daemon
    if (child == -1){
        printf("fork unsuccessful");
        return 1;
        
    } 
    else if (child > 0){
        exit(1);
    }
    // 6. Child process (the daemon) set new file permissions using umask(0). Daemon's PPID at this point is 1 (the init), NOT octal
    umask(0);
    chdir("/");      // 7. Change working directory to root
    /*If a daemon were to leave its current working directory unchanged then
     this would prevent the filesystem containing that directory 
     from being unmounted while the daemon was running. 
     It is therefore good practice for daemons to change their working directory to a safe location. 
    */
    for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
        close(x);
    }
    // 8. Close all open file descriptors using sysconf(_SC_OPEN_MAX) and redirect fd 0,1,2 to /dev/null
    stdin=fopen("/dev/null","r");   //fd=0, according to screenshot,  stdin is mapped to fd0, etc etc
    stdout=fopen("/dev/null","w+");  //fd=1
    stderr=fopen("/dev/null","w+");  //fd=2

    // 9. Return to main
    return 0;
}

static int daemon_work()
{

    int num = 0;
    FILE *fptr;

    //write PID of daemon in the beginning
    fptr = fopen(path, "a");
    if (fptr == NULL)
    {
        return EXIT_FAILURE;
    }

    fprintf(fptr, "%d with FD %d\n", getpid(), fileno(fptr));
    fclose(fptr);

    while (1)
    {

        fptr = fopen(path, "a");

        if (fptr == NULL)
        {
            return EXIT_FAILURE;
        }

        fprintf(fptr, "PID %d Daemon writing line %d to the file.  \n", getpid(), num);
        num++;

        fclose(fptr);

        sleep(10);

        if (num == 10)
            break;
    }

    return EXIT_SUCCESS;
}
int main(int argc, char **args)
{
    create_daemon();

    /* Open the log file */
    openlog("customdaemon", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "Daemon started.");
    closelog();

    return daemon_work();
}
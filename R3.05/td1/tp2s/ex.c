#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

#define MAX_RUNNERS 50

typedef struct
{
    pid_t pid;
    time_t start_time;
    time_t total_time;
    time_t last_laps[3];
    int total_laps;
} Runner;

Runner runners[MAX_RUNNERS];
int runner_count = 0;

void handle_new_runner(int sig)
{
    pid_t pid = getpid(); // This should be replaced with the PID of the signal sender
    for (int i = 0; i < runner_count; i++)
    {
        if (runners[i].pid == pid)
            return; // Runner already exists
    }
    if (runner_count < MAX_RUNNERS)
    {
        runners[runner_count].pid = pid;
        runners[runner_count].start_time = time(NULL);
        runners[runner_count].total_laps = 0;
        memset(runners[runner_count].last_laps, 0, sizeof(runners[runner_count].last_laps));
        runner_count++;
    }
}

void handle_lap_completed(int sig)
{
    pid_t pid = getpid(); // This should be replaced with the PID of the signal sender
    for (int i = 0; i < runner_count; i++)
    {
        if (runners[i].pid == pid)
        {
            runners[i].total_laps++;
            time_t now = time(NULL);
            runners[i].total_time = now - runners[i].start_time;
            // Shift last laps and add new lap time
            runners[i].last_laps[0] = runners[i].last_laps[1];
            runners[i].last_laps[1] = runners[i].last_laps[2];
            runners[i].last_laps[2] = now;
            break;
        }
    }
}

void handle_end_race(int sig)
{
    for (int i = 0; i < runner_count; i++)
    {
        printf("Runner PID: %d, Total Laps: %d, Total Time: %ld\n", runners[i].pid, runners[i].total_laps, runners[i].total_time);
        // Calculate average of last three laps if possible
        if (runners[i].total_laps >= 3)
        {
            time_t avg = (runners[i].last_laps[2] - runners[i].last_laps[0]) / 3;
            printf("Average Time of Last 3 Laps: %ld\n", avg);
        }
    }
    exit(0);
}

int main()
{
    signal(SIGUSR1, handle_new_runner);
    signal(SIGUSR2, handle_lap_completed);
    signal(SIGTERM, handle_end_race);

    while (1)
    {
        pause(); // Wait for signals
    }

    return 0;
}
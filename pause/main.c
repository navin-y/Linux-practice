#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Signal %d caught! Exiting now.\n", sig);
}

int main() {
    signal(SIGINT, handler);  // Catch Ctrl+C (SIGINT)
    
    printf("Waiting for signal... Press Ctrl+C\n");

    pause();  // Sleep until any signal is received

    printf("pause() returned. Exiting.\n");
    return 0;
}

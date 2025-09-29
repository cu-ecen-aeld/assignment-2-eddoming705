#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Check that exactly two arguments are provided
    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file> <string>", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    const char *text = argv[2];

    // Initialize syslog with LOG_USER facility
    openlog("writer", LOG_PID, LOG_USER);

    // Try to open the file for writing
    FILE *fp = fopen(file_path, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Failed to open file: %s", file_path);
        closelog();
        return 1;
    }

    // Write the text to the file
    if (fprintf(fp, "%s\n", text) < 0) {
        syslog(LOG_ERR, "Failed to write to file: %s", file_path);
        fclose(fp);
        closelog();
        return 1;
    }

    // Debug message
    syslog(LOG_DEBUG, "Writing %s to %s", text, file_path);

    // Close the file and syslog
    fclose(fp);
    closelog();

    return 0;
}

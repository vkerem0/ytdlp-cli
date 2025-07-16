#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//visual
void clear();
void printTitle();
void printMenu();
void paraBreak();
//yt-dlp functionality
int execute_command(const char* command);
void listFormats(const char* url);
void bestVideo(const char* url);
void download_audio(const char* url);
void download_user_format(const char* url);



int main() {
    char url[4096];
    int choice;

    
    while (1) {

        clear();

        printf("\nEnter YouTube URL: ");
        

        if (fgets(url, sizeof(url), stdin) == NULL) {
            printf("Error reading URL.\n");
            paraBreak();
            continue;
        }
        
        start:
        
        printTitle();
        printMenu();
        
        

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); //clear inout buffer
            paraBreak();
            continue;
        }

        //clear input buffer Ｃ
        while (getchar() != '\n');
        

        //handle wrong input🥀
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter 1-5.\n");
            paraBreak();
            continue;
        }
        
        
        
        
        url[strcspn(url, "\n")] = 0;
        
        
        printf("\n");

        
        
        switch (choice) {
            case 1:
                listFormats(url);
                goto start;
            case 2:
                bestVideo(url);
                break;
            case 3:
                download_audio(url);
                break;
            case 4:
                download_user_format(url);
                break;
            case 5:
                printf("O hell nah\n");
                goto quit;
                break;
            default:
                printf("enter valid number bozo");
        }
        
        paraBreak();
    }
    
    quit:

    return 0;
}


void clear() {
    system("clear");
}

void printTitle() {
    printf("===========================================\n");
    printf("       YT-DLP CLI\n");
    printf("===========================================\n\n");
}

void paraBreak() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
}

void printMenu() {
    printf("Choose an option:\n");
    printf("1. List available formats\n");
    printf("2. Download video (best quality)\n");
    printf("3. Download audio only (mp3)\n");
    printf("4. Download specific format\n");
    printf("5. Exit\n");
    printf("\nEnter your choice (1-5): ");
}


int execute_command(const char* command) {
    printf("\nExecuting: %s\n", command);
    printf("----------------------------------------\n");
    
    int result = system(command);
    
    printf("----------------------------------------\n");
    if (result == 0) {
        printf("Command completed successfully!\n");
    } else {
        printf("Command failed with exit code: %d\n", result);
    }
    
    return result;
}

void listFormats(const char* url) {
    char command[4096];
    snprintf(command, sizeof(command), "yt-dlp -F \"%s\"", url);
    execute_command(command);
}


void bestVideo(const char* url) {
    char command[4096];
    snprintf(command, sizeof(command), "yt-dlp -f 'best[height<=720]' \"%s\"", url);
    execute_command(command);
}

void download_audio(const char* url) {
    char command[4096];
    snprintf(command, sizeof(command), "yt-dlp -x --audio-format mp3 \"%s\"", url);
    execute_command(command);
}

void download_user_format(const char* url) {
    char format[32];
    char command[4096];
    
    printf("Enter format code (e.g., 22, 18, best, worst): ");
    if (fgets(format, sizeof(format), stdin) != NULL) {
        // Remove newline character
        format[strcspn(format, "\n")] = 0;
        
        snprintf(command, sizeof(command), "yt-dlp -f '%s' \"%s\"", format, url);
        execute_command(command);
    }
}
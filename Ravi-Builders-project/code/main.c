#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "models.h"
#include "utils.h"
#include "project.h"
#include "workers.h"
#include "attendance.h"

// Function Prototypes
void projectMenu(int *option);          // Display the main menu options and update the user's choice.
void projectModuleMenu(int *choice);    // Display the project module options and update the user's choice.
void workersModuleMenu(int *choice);    // Display the workers module options and update the user's choice.
void attendanceModuleMenu(int *choice); // Display the attendance module options and update the user's choice.

int main()
{
    int option = 0, choice = 0; // Variables to store user menu selections.

    // File paths for storing project, transaction, worker, and attendance data.
    char proj_filepath[200] = "C:\\Users\\rabbu\\OneDrive\\Documents\\coding\\c\\Ravi-Builders-project\\data\\project_data.dat";
    char projtrsn_filepath[200] = "C:\\Users\\rabbu\\OneDrive\\Documents\\coding\\c\\Ravi-Builders-project\\data\\project_transaction_data.dat";
    char wkr_filepath[200] = "C:\\Users\\rabbu\\OneDrive\\Documents\\coding\\c\\Ravi-Builders-project\\data\\worker_data.dat";
    char wkrtrsn_filepath[200] = "C:\\Users\\rabbu\\OneDrive\\Documents\\coding\\c\\Ravi-Builders-project\\data\\workers_transaction_data.dat";
    char atd_filepath[200] = "C:\\Users\\rabbu\\OneDrive\\Documents\\coding\\c\\Ravi-Builders-project\\data\\attendance_data.dat";

    // Title/Header of the program.
    printf("\n=========================================================================================================\n");
    printf("||                                            RAVI BUILDERS                                            ||\n");
    printf("=========================================================================================================\n");

    // Main menu loop to keep the program running until the user exits.
    while (1)
    {
        projectMenu(&option); // Display the main menu and get user's choice.

        // Handle user selection from the main menu.
        switch (option)
        {
        case 1:                         // Project Module
            projectModuleMenu(&choice); // Display the project module menu and get user's choice.

            // Handle user selection from the project module menu.
            switch (choice)
            {
            case 1:
                create_project(proj_filepath);
                break; // Create a new project.
            case 2:
                update_project(proj_filepath);
                break; // Update project details.
            case 3:
                display_project_details(proj_filepath);
                break; // Display project details.
            case 4:
                create_transaction(projtrsn_filepath);
                break; // Create a new transaction.
            case 5:
                update_transaction(projtrsn_filepath);
                break; // Update transaction details.
            case 6:
                display_transaction_details(projtrsn_filepath);
                break; // Display all transactions.
            case 7:
                get_project_transactions(projtrsn_filepath);
                break; // Get transactions for a project.
            case 8:
                end_project(proj_filepath);
                break; // End a project.
            case 9:
                break; // Return to the main menu.
            default:
                printf("*** ERROR: Invalid Option ***\n");
            }
            break;

        case 2:                         // Workers Module
            workersModuleMenu(&choice); // Display the workers module menu and get user's choice.

            // Handle user selection from the workers module menu.
            switch (choice)
            {
            case 1:
                register_worker(wkr_filepath);
                break; // Register a new worker.
            case 2:
                update_worker_details(wkr_filepath);
                break; // Update worker details.
            case 3:
                display_worker_details(wkr_filepath);
                break; // Display worker details.
            case 4:
                create_worker_transaction(wkrtrsn_filepath);
                break; // Create worker transaction.
            case 5:
                update_worker_transaction(wkrtrsn_filepath);
                break; // Update worker transaction.
            case 6:
                display_workers_transaction_details(wkrtrsn_filepath);
                break; // Display worker transactions.
            case 7:
                get_workers_transactions(wkrtrsn_filepath);
                break; // Get worker transactions.
            case 8:
                break; // Return to the main menu.
            default:
                printf("*** ERROR: Invalid Option ***\n");
            }
            break;

        case 3:                            // Attendance Module
            attendanceModuleMenu(&choice); // Display the attendance module menu and get user's choice.

            // Handle user selection from the attendance module menu.
            switch (choice)
            {
            case 1:
                create_attendance(atd_filepath);
                break; // Create attendance record.
            case 2:
                update_attendance(atd_filepath);
                break; // Update attendance record.
            case 3:
                display_attendance_details(atd_filepath);
                break; // Display attendance details.
            case 4:
                break; // Return to the main menu.
            default:
                printf("*** ERROR: Invalid Option ***\n");
            }
            break;

        case 4: // Exit
            printf("\n*** Thank you for using Ravi Builders Management System ***\n");
            exit(0); // Terminate the program.

        default: // Invalid main menu option.
            printf("*** ERROR: Invalid Option ***\n");
        }
    }

    return 0; // Return 0 to indicate successful program execution.
}

// Function Definitions

// Display the main menu options and get the user's choice.
void projectMenu(int *option)
{
    printf("\n\tMENU:- \n");
    printf("\t1. PROJECT MODULE.\n");
    printf("\t2. WORKERS MODULE.\n");
    printf("\t3. ATTENDANCE MODULE.\n");
    printf("\t4. EXIT.\n");
    printf("\nEnter option: ");
    fflush(stdin);       // Clear input buffer.
    scanf("%d", option); // Read the user's choice for the main menu.
}

// Display the project module menu options and get the user's choice.
void projectModuleMenu(int *choice)
{
    printf("\n*** Project Module Menu ***\n");
    printf("\n1. Create a new project.\n");
    printf("2. Update project details.\n");
    printf("3. Display project details.\n");
    printf("4. Create a new transaction.\n");
    printf("5. Update transaction.\n");
    printf("6. Display all transactions.\n");
    printf("7. Get project transactions.\n");
    printf("8. End a project.\n");
    printf("9. GO TO MENU.\n");
    printf("\nEnter the choice: ");
    fflush(stdin);       // Clear input buffer.
    scanf("%d", choice); // Read the user's choice for the project module menu.
}

// Display the workers module menu options and get the user's choice.
void workersModuleMenu(int *choice)
{
    printf("\n*** Workers Module Menu ***\n");
    printf("\n1. Register a new worker.\n");
    printf("2. Update worker details.\n");
    printf("3. Display worker details.\n");
    printf("4. Create worker transaction.\n");
    printf("5. Update worker transaction.\n");
    printf("6. Display worker transactions.\n");
    printf("7. Get worker transactions.\n");
    printf("8. GO TO MENU.\n");
    printf("\nEnter the choice: ");
    fflush(stdin);       // Clear input buffer.
    scanf("%d", choice); // Read the user's choice for the workers module menu.
}

// Display the attendance module menu options and get the user's choice.
void attendanceModuleMenu(int *choice)
{
    printf("\n*** Attendance Module Menu ***\n");
    printf("\n1. Create attendance record.\n");
    printf("2. Update attendance record.\n");
    printf("3. Display attendance details.\n");
    printf("4. GO TO MENU.\n");
    printf("\nEnter the choice: ");
    fflush(stdin);       // Clear input buffer.
    scanf("%d", choice); // Read the user's choice for the attendance module menu.
}

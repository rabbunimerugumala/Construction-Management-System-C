#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// FUNCTION DECLARATION..
void create_attendance(char *);
void display_attendance_details(char *);
void print_attendance_details();
void update_attendance(char *);

// TO PRINT THE ATTENDANCE DETAILS..
void print_attendance_details()
{
    printf("\n----------------------------------------------------------\n");
    printf("Date\t \tProject\t \tWorker ID\t Status\n");
    printf("----------------------------------------------------------\n");
    printf("%s\t %s\t%s\t  \t %s\t", atd.date, atd.project_id, atd.worker_id, atd.status);
}

// TO CREATE THE ATTENDANCE FOR WORKERS..
void create_attendance(char *filepath)
{
    int ch;
    FILE *f;
    f = fopen(filepath, "a+b");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file to create the project ***\n");
        exit(1);
    }
    printf("\n*** Enter attendance details ***\n");

    printf("\nProject ID: ");
    fflush(stdin);
    scanf("%[^\n]%*c", atd.project_id);

    printf("Worker ID: ");
    fflush(stdin);
    scanf("%[^\n]%*c", atd.worker_id);

    printf("Date (dd/mm/yyyy): ");
    fflush(stdin);
    scanf("%s", atd.date);

    printf("Status\n");
    printf("1.Present\n2.Absent\n");
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &ch);
    if (ch == 1)
    {
        strcpy(atd.status, "P");
    }
    else if (ch == 2)
    {
        strcpy(atd.status, "A");
    }

    else
    {
        printf("*** ERROR:invalid option ***");
        exit(1);
    }
    fwrite(&atd, sizeof(atd), 1, f);
    printf("\n*** Success: Project details successfully saved ***\n");
    fclose(f);
}

// TO DISPLAY THE WORKERS ATTENDANCE..
void display_attendance_details(char *filepath)
{
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file ***\n");
        exit(1);
    }

    printf("\n*** Displaying Worker Attendance Details ***\n");
    while (fread(&atd, sizeof(atd), 1, f) == 1)
    {
        print_attendance_details();
    }
    fclose(f);
}

// TO UPDATE THE ATTENDANCE..
void update_attendance(char *filepath)
{
    char worker_id[8], ch;
    int choice, flag = 0;
    FILE *f;
    f = fopen(filepath, "r+b");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    printf("\n*** Update attendance details *** \n");
    printf("\nEnter worker ID to update: ");
    fflush(stdin);
    scanf("%s", worker_id);
    while (fread(&atd, sizeof(atd), 1, f) == 1)
    {
        if (strcmp(atd.worker_id, worker_id) == 0)
        {
            flag = 1;
            printf("\n*** Old project details ***\n");
            print_attendance_details();

            printf("\n\nDo you want to update \"project ID\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"project ID\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", atd.project_id);
            }

            printf("Do you want to update \"date\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"date\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", atd.date);
            }

            printf("Do you want to update \"status\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Status\n");
                printf("1.Present\n2.Absent\n");
                printf("Enter your choice: ");
                fflush(stdin);
                scanf("%d", &choice);
                if (choice == 1)
                {
                    strcpy(atd.status, "P");
                }
                else if (choice == 2)
                {
                    strcpy(atd.status, "A");
                }

                else
                {
                    printf("*** ERROR:invalid option ***");
                    exit(1);
                }
            }
            int rec_size = sizeof(atd);
            fseek(f, -rec_size, SEEK_CUR);
            fwrite(&atd, rec_size, 1, f);
            printf("\n*** SUCCESS: The attendance with %s updated successfully ***", worker_id);
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n*** ERROR:Invalid Worker ID ***");
    }
    fclose(f);
}

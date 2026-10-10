#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// PROJECT FUNCTIONS DECLARATION..

void create_project(char *);
void display_project_details(char *);
char *get_projectid(char *);
void print_project_details();
void update_project(char *);
void end_project(char *);

// TRANSACTION FUNCTIONS DECLARATION..

void create_transaction(char *);
void display_transaction_details(char *);
void print_transaction_details();
void update_transaction(char *);
char *get_transactionid();
void get_project_transactions(char *);

// TO ASIGN THE PROJECT ID..
char *get_projectid(char *filepath)

{
    int count = 1;
    char num_count[5];
    static char id[7] = "RBP";

    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file  ***\n");
        exit(1);
    }
    while (fread(&proj, sizeof(proj), 1, f) == 1)
    {
        count++;
    }
    fclose(f);
    sprintf(num_count, "%04d", count);
    strcat(id, num_count);
    // printf("%s", id);
    return id;
}

// TO PRINT THE PROJECT DETAILS..
void print_project_details()
{

    printf("%s\t  %s\t   \t\t%s\t\t%s\t\t \t%d\t\t %d\t\t %d\t\t%s\t\t%s\t%s\t\t%s\t%s\n", proj.id, proj.name, proj.type, proj.status, proj.cost_per_sqft, proj.total_sqft, proj.budget, proj.start_date, proj.end_date, proj.ownr.name, proj.ownr.phone_number, proj.ownr.address);
}

// TO CREATE THE NEW PROJECT..
void create_project(char *filepath) // definition
{
    int ch;
    FILE *f;
    f = fopen(filepath, "a+b");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file to create the project ***\n");
        exit(1);
    }
    printf("\n*** Enter project details ***\n");
    // printf("%s\n", get_projectid(filepath));
    strcpy(proj.id, get_projectid(filepath));
    // puts(proj.id);

    // return;

    printf("Project name: ");
    fflush(stdin);
    scanf("%[^\n]%*c", proj.name);

    printf("\nProject type \n");
    printf("1.contract\n2.material-contract\n3.non-contract\n");
    printf("Enter yours choice: ");
    fflush(stdin);
    scanf("%d", &ch);
    if (ch == 1)
    {
        strcpy(proj.type, "contract");
    }
    else if (ch == 2)
    {
        strcpy(proj.type, "material-contract");
    }
    else if (ch == 3)
    {
        strcpy(proj.type, "non-contract");
    }
    else
    {
        printf("*** ERROR:invalid option ***");
        exit(1);
    }

    printf("\nProject Status: \n");
    printf("1.New\n2.On-processing\n3.Completed\n");
    printf("Enter yours choice: ");
    fflush(stdin);
    scanf("%d", &ch);
    if (ch == 1)
    {
        strcpy(proj.status, "new");
    }
    else if (ch == 2)
    {
        strcpy(proj.status, "in-progress");
    }
    else if (ch == 3)
    {
        strcpy(proj.status, "completed");
    }
    else
    {
        printf("*** ERROR:invalid option ***");
        exit(1);
    }

    if (strcmp(proj.type, "non-contract") == 0)
    {
        proj.cost_per_sqft = 0;
        proj.total_sqft = 0;
    }
    else
    {
        printf("Cost per square feet: ");
        fflush(stdin);
        scanf("%d", &proj.cost_per_sqft);

        printf("Total square feet: ");
        fflush(stdin);
        scanf("%d", &proj.total_sqft);
    }

    proj.budget = proj.cost_per_sqft * proj.total_sqft;

    printf("Project start date (dd-mm-yyyy): ");
    fflush(stdin);
    scanf("%s", proj.start_date);

    printf("Owner name: ");
    fflush(stdin);
    scanf("%[^\n]%*c", proj.ownr.name);

    printf("Owner phone number: ");
    fflush(stdin);
    scanf("%[^\n]%*c", proj.ownr.phone_number);

    printf("Owner address: ");
    fflush(stdin);
    scanf("%[^\n]%*c", proj.ownr.address);

    fwrite(&proj, sizeof(proj), 1, f);
    printf("\n*** Success: Project details successfully saved ***\n");
    fclose(f);
}

// TO DISPLAY THE PROJECT DETAILS..
void display_project_details(char *filepath)
{
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:unable to open file ***\n");
        exit(1);
    }
    // printf("\n*** Displaying Project Details ***\n");
    // printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    // printf(" Project id: %s\n Project Name: %s\n Project Type: %s\n Project Status: %s\n Project Cost Per Square Feet: %d\n Project Total Square Feet: %d\n Project Budget: %d\n Project Starting Date: %s\n Project End Date:  %s\n Project Owner Name: %s\n Owner Mobile Number: %s\n Owner address: %s\n ", proj.id, proj.name, proj.type, proj.status, proj.cost_per_sqft, proj.total_sqft, proj.budget, proj.start_date, proj.end_date, proj.ownr.name, proj.ownr.phone_number, proj.ownr.address);
    // printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&proj, sizeof(proj), 1, f) == 1)
    {

        // print_project_details();
        printf("\n         *** Displaying Project Details ***         \n");
        printf("\tProject id                   : %s\n", proj.id);
        printf("\tProject Name                 : %s\n", proj.name);
        printf("\tProject Type                 : %s\n", proj.type);
        printf("\tProject Status               : %s\n", proj.status);
        printf("\tProject Cost Per Square Feet : %d\n", proj.cost_per_sqft);
        printf("\tProject Total Square Feet    : %d\n", proj.total_sqft);
        printf("\tProject Budget               : %d\n", proj.budget);
        printf("\tProject Starting Date        : %s\n", proj.start_date);
        printf("\tProject End Date             :  %s\n", proj.end_date);
        printf("\tProject Owner Name           : %s\n", proj.ownr.name);
        printf("\tOwner Mobile Number          : %s\n", proj.ownr.phone_number);
        printf("\tOwner address                : %s\n", proj.ownr.address);
    }
    fclose(f);
}

// TO UPDATE THE PROJECT DETAILS..
void update_project(char *filepath)
{
    char proj_id[8], ch;
    int choice, flag = 0;
    FILE *f;
    f = fopen(filepath, "r+b");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    printf("\n*** Update project details *** \n");
    printf("Enter project ID to update: ");
    fflush(stdin);

    while (scanf("%s", proj_id))
    {
        fflush(stdin);

        if (vaildate_projectid(filepath, proj_id) == 1)
        {
            break;
        }

        printf("*** ERROR:invaild project id entered ***\n");
        printf("\nEnter project ID to update: ");
    }
    while (fread(&proj, sizeof(proj), 1, f) == 1)
    {
        if (strcmp(proj.id, proj_id) == 0)
        {
            flag = 1;
            printf("\n*** Old project details ***\n");
            print_project_details();

            printf("\nDo you want to update \"project name\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"project name\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", proj.name);
            }

            printf("Do you want to update \"project type\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Choose updated \"project type\": ");
                printf("\n1.contract\n2.material-contract\n3.non-contract\n");
                printf("Enter yours choice: ");
                fflush(stdin);
                scanf("%d", &choice);
                if (choice == 1)
                {
                    strcpy(proj.type, "contract");
                }
                else if (choice == 2)
                {
                    strcpy(proj.type, "material-contract");
                }
                else if (choice == 3)
                {
                    strcpy(proj.type, "non-contract");
                }
                else
                {
                    printf("*** ERROR:invalid option ***");
                    exit(1);
                }
            }

            printf("Do you want to update \"project status\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Choose updated \"project status\": ");
                printf("\n1.new\n2.in-progress\n3.completed\n");
                printf("Enter yours choice: ");
                fflush(stdin);
                scanf("%d", &choice);
                if (choice == 1)
                {
                    strcpy(proj.status, "new");
                }
                else if (choice == 2)
                {
                    strcpy(proj.status, "in-progress");
                }
                else if (choice == 3)
                {
                    strcpy(proj.status, "completed");
                }
                else
                {
                    printf("*** ERROR:invalid option ***");
                    exit(1);
                }
            }

            if (strcmp(proj.type, "non-contract") != 0)
            {
                printf("Do you want to update \"cost per square feet\" (Y/N): ");
                fflush(stdin);
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                    printf("Enter updated \"cost per square feet \": ");
                    fflush(stdin);
                    scanf("%d", &proj.cost_per_sqft);
                }

                printf("Do you want to update \"total square feet\" (Y/N): ");
                fflush(stdin);
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                    printf("Enter updated \"total square feet \": ");
                    fflush(stdin);
                    scanf("%d", &proj.total_sqft);
                }
                proj.budget = proj.cost_per_sqft * proj.total_sqft;
            }

            printf("Do you want to update \"start date\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"start date\": ");
                fflush(stdin);
                scanf("%s", proj.start_date);
            }

            printf("Do you want to update \"end date\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"end date\": ");
                fflush(stdin);
                scanf("%s", proj.end_date);
            }

            printf("Do you want to update \"owner name\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"owner name\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", proj.ownr.name);
            }

            printf("Do you want to update \"owner phone number\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"owner phone number\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", proj.ownr.phone_number);
            }

            printf("Do you want to update \"owner address\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"owner address\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", proj.ownr.address);
            }

            // updating the record in file

            int rec_size = sizeof(proj);
            fseek(f, -rec_size, SEEK_CUR);
            fwrite(&proj, rec_size, 1, f);
            printf("\n*** SUCCESS: The project with %s updated successfully ***", proj_id);
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n*** ERROR:Invalid project id ***");
    }
    fclose(f);
}

// THE END OF THE PROJECT..
void end_project(char *filepath)
{
    FILE *f;
    int choice;
    char proj_id[8];
    f = fopen(filepath, "r+b");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    printf("\n*** Ending the project *** \n");
    printf("Enter project ID to end: ");
    fflush(stdin);
    while (scanf("%s", proj_id))
    {
        fflush(stdin);

        if (vaildate_projectid(filepath, proj_id) == 1)
        {
            break;
        }

        printf("*** ERROR:invaild project id entered ***\n");
        printf("\nEnter project ID to update: ");
    }

    while (fread(&proj, sizeof(proj), 1, f) == 1)
    {
        if (strcmp(proj_id, proj.id) == 0)
        {
            strcpy(proj.status, "completed");
            int rec_size = sizeof(proj);
            fseek(f, -rec_size, SEEK_CUR);
            fwrite(&proj, rec_size, 1, f);
            printf("*** SUCCESS:project successfully ended ***");
            break;
        }
    }
    fclose(f);
}

// TO ASIGN THE TRANSACTION ID..
char *get_transactionid()
{
    static char trsn_id[15];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(trsn_id, "PT%d%02d%02d%d%d%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return (trsn_id);
}

// TO CREATE THE TRANSACTION DETAILS..
void create_transaction(char *filepath)
{
    char proj_id[12];
    FILE *f;
    f = fopen(filepath, "a+b");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file to create the transaction ***\n");
        exit(1);
    }

    printf("\n*** Enter The Trasaction Details ***\n");

    strcpy(trsn.id, get_transactionid());

    printf("\nProject ID: ");
    fflush(stdin);
    while (scanf("%s", proj_id))
    {
        fflush(stdin);
        printf("%d", vaildate_projectid(filepath, proj_id));

        if (vaildate_projectid(filepath, proj_id) == 1)
        {

            break;
        }
        printf("\n*** ERROR:invaild project id entered ***\n");
        printf("\nEnter project ID to create the transaction: ");
    }
    strcpy(trsn.project_id, proj_id);
    printf("Date (dd/mm/yyyy): ");
    fflush(stdin);
    scanf("%s", trsn.date);

    printf("Amount: ");
    fflush(stdin);
    scanf("%d", &trsn.amount);

    fwrite(&trsn, sizeof(struct Transaction), 1, f);
    printf("\n*** Success: transaction details successfully saved ***\n");
    fclose(f);
}

// TO PRINT THE PROJECT TRANSACTION DETAILS..
void print_transaction_details()

{
    printf("\nProject ID: %s\n", trsn.project_id);
    printf("Transaction ID: %s\n", trsn.id);
    printf("Date: %s\n", trsn.date);
    printf("Amount: %d\n", trsn.amount);
}

// TO DISPLAY THE PROJECT TRANSACTION DETAILS..
void display_transaction_details(char *filepath)
{
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:unable to open file ***\n");
        exit(1);
    }
    printf("\n*** Displaying trasaction Details ***\n");

    while (fread(&trsn, sizeof(trsn), 1, f) == 1)
    {
        print_transaction_details();
    }
    fclose(f);
}

// TO UPDATE THE PROJECT TRANSACTION DETAILS..
void update_transaction(char *filepath)
{
    char trsn_id[16], ch;
    int choice, flag = 0;
    FILE *f;
    f = fopen(filepath, "r+b");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    printf("\n*** Update transaction details *** \n");
    printf("\nEnter transaction ID to update: ");
    fflush(stdin);
    while (scanf("%s", trsn_id))
    {
        fflush(stdin);

        if (vaildate_project_trsnid(filepath, trsn_id) == 1)
        {
            break;
        }

        printf("\n*** ERROR:invalid transaction id entered ***\n");
        printf("\nEnter transaction ID to update: ");
    }
    // while (scanf("%s", trsn_id))
    // {
    //     fflush(stdin);

    //     if (vaildate_project_trsnid(filepath, proj_id) == 1)
    //     {
    //         break;
    //     }
    // scanf("%s", trsn_id);

    while (fread(&trsn, sizeof(struct Transaction), 1, f) == 1)
    {
        if (strcmp(trsn.id, trsn_id) == 0)
        {
            flag = 1;
            printf("\n*** Old project details ***\n");
            print_transaction_details();

            printf("\nDo you want to update \"project ID\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"project ID\": ");
                fflush(stdin);
                while (scanf("%s", trsn.project_id))
                {
                    fflush(stdin);

                    if (vaildate_projectid(filepath, trsn.project_id) == 1)
                    {
                        break;
                    }

                    printf("*** ERROR:invaild project id entered ***\n");
                    printf("\nEnter project ID to update: ");
                }
            }

            printf("Do you want to update \"date\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"date\": ");
                fflush(stdin);
                scanf("%s", &trsn.date);
            }

            printf("Do you want to update \"amount\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"amount\": ");
                fflush(stdin);
                scanf("%d", &trsn.amount);
            }

            // updateing the record in file
            int rec_size = sizeof(struct Transaction);
            fseek(f, -rec_size, SEEK_CUR);
            fwrite(&trsn, rec_size, 1, f);

            printf("\n*** SUCCESS: The transaction with %s updated successfully ***", trsn_id);
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n*** ERROR: Invalid transaction id ***");
    }
    fclose(f);
}

// TO PRINT THE PROJECT TRANSACTIONS..-
void get_project_transactions(char *filepath)
{
    char proj_id[10];
    int total = 0;
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:File not found ***");
        exit(1);
    }
    printf("\n*** Project transactions details ***\n");
    printf("Enter the \"project ID\": ");
    fflush(stdin);
    while (scanf("%s", proj_id))
    {
        fflush(stdin);

        if (vaildate_projectid(filepath, proj_id) == 1)
        {
            break;
        }

        printf("*** ERROR:invalid project id entered ***\n");
        printf("Enter the \"project ID\": ");
    }
    printf("\n--------------------------------------------------------\n");
    printf("Date\t\tTransaction ID\tProject ID\tAmount\n");
    printf("--------------------------------------------------------\n");

    while (fread(&trsn, sizeof(struct Transaction), 1, f) == 1)
    {

        if (strcmp(trsn.project_id, proj_id) == 0)
        {
            printf("%s\t%s\t%s\t\t%d\n", trsn.date, trsn.id, trsn.project_id, trsn.amount);
            total += trsn.amount;
        }
    }
    printf("---------------------------------------------------------\n");
    printf("Total: %d\n", total);
    printf("---------------------------------------------------------\n");
}
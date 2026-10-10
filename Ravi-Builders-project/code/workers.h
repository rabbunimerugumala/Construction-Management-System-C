#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// WORKERS FUNCTION DECLARATION..

char *get_workerid(char *);
void register_worker(char *);
void display_worker_details(char *);
void update_worker_details(char *);
void print_workers_details();

// WORKWRS TRANSACTION FUNCTION DECLARATION..

char *get_worker_transactionid();
void print_workers_transaction_details();
void create_worker_transaction(char *);
void display_workers_transaction_details(char *);
void update_worker_transaction(char *filepath);
void get_workers_transactions(char *filepath);

// TO ASIGN THE WORKER ID..
char *get_workerid(char *filepath)

{
    int count = 1;
    char num_count[5];
    static char id[7] = "RBW";

    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file  ***\n");
        exit(1);
    }
    while (fread(&wkr, sizeof(wkr), 1, f) == 1)
    {
        count++;
    }
    fclose(f);
    sprintf(num_count, "%04d", count);
    strcat(id, num_count);
    return id;
}

// TO PRINT THE WORKERS DETAILS..
void print_workers_details()
{

    printf(" %s\t  %s\t \t%s\t %s\t %s\t %d\t %d\t\t  %s\n", wkr.id, wkr.name, wkr.type, wkr.phone_number, wkr.gender, wkr.wage, wkr.adv_amount, wkr.address);
}

// TO REGISTER THE WORKERS..
void register_worker(char *filepath)
{
    int ch;
    FILE *f;
    f = fopen(filepath, "a+b");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file to create the project ***\n");
        exit(1);
    }
    printf("\n*** Enter The Worker Details ***\n");
    strcpy(wkr.id, get_workerid(filepath));

    printf("\nWorker name: ");
    fflush(stdin);
    scanf("%[^\n]%*c", wkr.name);

    printf("Select worker type: ");
    printf("\n1.Senior\n2.Junior\n");
    printf("Choose option: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        strcpy(wkr.type, "senior");
    }
    else if (ch == 2)
    {
        strcpy(wkr.type, "junior");
    }

    printf("Worker phone number: ");
    fflush(stdin);
    scanf("%[^\n]%*c", wkr.phone_number);

    printf("Worker address: ");
    fflush(stdin);
    scanf("%[^\n]%*c", wkr.address);

    printf("Worker gender: ");
    printf("\n1.Male\n2.Female\n");
    printf("Choose option: ");
    fflush(stdin);
    scanf("%d", &ch);
    if (ch == 1)
    {
        strcpy(wkr.gender, "M");
    }
    else if (ch == 2)
    {
        strcpy(wkr.gender, "F");
    }

    wkr.adv_amount = 0;

    printf("Worker wage: ");
    fflush(stdin);
    scanf("%d", &wkr.wage);

    fwrite(&wkr, sizeof(wkr), 1, f);

    fclose(f);
}

// TO DISPLAY THE WORKER DETAILS..
void display_worker_details(char *filepath)
{
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file ***\n");
        exit(1);
    }

    printf("\n*** Displaying Worker Transaction Details ***\n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("ID\t\t  Name\t\t Type\t Phone Number\t Gender\t Wage\t Advance Amount\t  Address\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    while (fread(&wkr, sizeof(wkr), 1, f) == 1)
    {
        print_workers_details();
    }
    fclose(f);
}

// TO UPDATE THE WORKERS DETAILS..
void update_worker_details(char *filepath)
{
    char wkr_id[8], ch;
    int choice, flag = 0;
    FILE *f;
    f = fopen(filepath, "r+b");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    printf("\n*** Update workers details *** \n");
    printf("Enter worker ID to update: ");
    fflush(stdin);
    while (scanf("%s", wkr_id))
    {
        fflush(stdin);

        if (vaildate_workerid(filepath, wkr_id) == 1)
        {
            break;
        }

        printf("*** ERROR:invalid worker id entered ***\n");
        printf("\nEnter worker ID to update: ");
    }
    while (fread(&wkr, sizeof(wkr), 1, f) == 1)
    {
        if (strcmp(wkr.id, wkr_id) == 0)
        {
            flag = 1;
            printf("\n*** Old workers details ***\n");

            print_workers_details();

            printf("\nDo you want to update \"worker name\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"worker name\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", wkr.name);
            }

            printf("Do you want to update \"worker type\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Select worker type: ");
                printf("\n1.Senior\n2.Junior\n");
                printf("Choose option: ");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    strcpy(wkr.type, "senior");
                }
                else if (ch == 2)
                {
                    strcpy(wkr.type, "junior");
                }
            }
            printf("Do you want to update \"worker phone number\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"worker phone number\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", wkr.phone_number);
            }

            printf("Do you want to update \"worker address\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"worker address\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", wkr.address);
            }

            printf("Do you want to update \"worker gender\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {

                printf("Worker gender: ");
                printf("\n1.Male\n2.Female\n");
                printf("Choose option: ");
                fflush(stdin);
                scanf("%d", &ch);
                if (ch == 1)
                {
                    strcpy(wkr.gender, "M");
                }
                else if (ch == 2)
                {
                    strcpy(wkr.gender, "F");
                }
            }

            printf("Do you want to update \"worker wage\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"worker wage\": ");
                fflush(stdin);
                scanf("%d", &wkr.wage);
            }
            int rec_size = sizeof(wkr);
            fseek(f, -rec_size, SEEK_CUR);
            fwrite(&wkr, rec_size, 1, f);
            printf("\n*** SUCCESS: The worker details with %s updated successfully ***\n", wkr_id);
            break;
        }
    }
    fclose(f);
}

// TO ASIGN THE WORKERS TRANSACTION ID..
char *get_worker_transactionid()
{
    static char trsn_id[17];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(trsn_id, "WT%d%02d%02d%d%d%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return (trsn_id);
}

void print_workers_transaction_details()
{

    printf("%s\t\t%s\t\t%s\t%s\t %d\n", wkrtrsn.id, wkrtrsn.worker_id, wkrtrsn.date, wkrtrsn.type, wkrtrsn.amount);
}
// TO CREATE THE WORKERS TRANSACTION..
void create_worker_transaction(char *filepath)
{
    int choice;
    FILE *f;
    f = fopen(filepath, "a+b");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file to create the transaction ***\n");
        exit(1);
    }

    printf("\n*** Enter The Worker Trasaction Details ***\n");

    strcpy(wkrtrsn.id, get_worker_transactionid());

    printf("\nWorker ID: ");
    fflush(stdin);
    scanf("%[^\n]%*c", wkrtrsn.worker_id);

    printf("Date (dd/mm/yyyy): ");
    fflush(stdin);
    scanf("%s", wkrtrsn.date);

    printf("select transaction type: \n");
    printf("1.credit\n2.debit\n");
    printf("Enter the choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    if (choice == 1)
    {
        strcpy(wkrtrsn.type, "credit");
    }
    else if (choice == 2)
    {
        strcpy(wkrtrsn.type, "debit");
    }
    else
    {
        printf("*** ERROR:Invaild choice ***");
        exit(1);
    }

    printf("Amount: ");
    fflush(stdin);
    scanf("%d", &wkrtrsn.amount);

    fwrite(&wkrtrsn, sizeof(wkrtrsn), 1, f);
    printf("\n*** Success: workers transaction details successfully saved ***\n");
    fclose(f);
}

// TO UPDATE THE WORKERS TRANSACTION..
void update_worker_transaction(char *filepath)
{
    char wkrtrsn_id[20], ch;
    int choice, flag = 0;
    FILE *f;
    f = fopen(filepath, "r+b");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    printf("\n*** Update workers transaction details *** \n");
    printf("\nEnter transaction ID to update: ");
    fflush(stdin);
    scanf("%s", wkrtrsn_id);
    while (fread(&wkrtrsn, sizeof(wkrtrsn), 1, f) == 1)
    {
        if (strcmp(wkrtrsn.id, wkrtrsn_id) == 0)
        {
            flag = 1;
            printf("\n*** Old workers details ***\n");

            print_workers_transaction_details();

            printf("\nDo you want to update \"worker ID\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"worker ID\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", wkrtrsn.worker_id);
            }

            printf("\nDo you want to update \"date\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"date\": ");
                fflush(stdin);
                scanf("%[^\n]%*c", wkrtrsn.date);
            }

            printf("\nDo you want to update \"transaction type\" (Y/N): ");
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Select \"transaction type\": ");
                printf("\n1.credit\n2.debit\n");
                printf("Enter the choice: ");
                fflush(stdin);
                scanf("%d", &choice);
                if (choice == 1)
                {
                    strcpy(wkrtrsn.type, "credit");
                }
                else if (choice == 2)
                {
                    strcpy(wkrtrsn.type, "debit");
                }
                else
                {
                    printf("*** ERROR:Invaild choice ***");
                    exit(1);
                }
            }

            printf("\nDo you want to update \"amount\" (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                printf("Enter updated \"amount\": ");
                fflush(stdin);
                scanf("%d", &wkrtrsn.amount);
            }

            int rec_size = sizeof(wkrtrsn);
            fseek(f, -rec_size, SEEK_CUR);
            fwrite(&wkrtrsn, rec_size, 1, f);
            printf("\n*** SUCCESS: The project with %s updated successfully ***", wkrtrsn_id);
            break;
        }
    }
    fclose(f);
}

// TO DISPLAY WORKERS TRANSACTION DETAILS..
void display_workers_transaction_details(char *filepath)
{
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR: unable to open the file ***\n");
        exit(1);
    }

    printf("\n*** Displaying Worker Transaction Details ***\n");
    printf("\n---------------------------------------------------------------------------------\n");
    printf(" ID\t\t\t\tWorker ID\tDate\t\tType\t Amount\n");
    printf("---------------------------------------------------------------------------------\n");

    while (fread(&wkrtrsn, sizeof(wkrtrsn), 1, f) == 1)
    {
        print_workers_transaction_details();
    }
    fclose(f);
}

// TO PRINT ALL WORKERS TRANSACTION DETAILS
void get_workers_transactions(char *filepath)
{
    char worker_id[8], trsntype[8];
    int total = 0, choice;
    FILE *f;
    f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:File not found ***");
        exit(1);
    }
    printf("\n*** Workers transactions details ***\n");
    printf("Enter the \"Worker ID\": ");
    fflush(stdin);
    // scanf("%s", worker_id);
    while (scanf("%s", worker_id))
    {
        fflush(stdin);

        if (vaildate_workerid("data/worker_data.dat", worker_id) == 1)
        {
            break;
        }

        printf("\n*** ERROR:invalid worker id entered ***\n");
        printf("\nEnter worker ID: ");
    }

    printf("Select \"transaction type\": ");
    printf("\n1.credit\n2.debit\n3.all\n");
    printf("Enter the choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    if (choice == 1)
    {
        strcpy(trsntype, "credit");
    }
    else if (choice == 2)
    {
        strcpy(trsntype, "debit");
    }
    else if (choice == 3)
    {
        strcpy(trsntype, "all");
    }
    else
    {
        printf("*** ERROR:Invaild choice ***");
        exit(1);
    }
    printf("\n------------------------------------------------------------------------------------------\n");
    printf("Date\t\tTransaction ID\t\tProject ID\tTransaction Type\tAmount\n");
    printf("------------------------------------------------------------------------------------------\n\n");

    while (fread(&wkrtrsn, sizeof(wkrtrsn), 1, f) == 1)
    {

        if (strcmp(wkrtrsn.worker_id, worker_id) == 0)
        {
            if (strcmp(wkrtrsn.type, trsntype) == 0)
            {
                printf("credit/debit\n");
                printf("%s\t%s\t%s\t\t%s\t\t\t%d\n", wkrtrsn.date, wkrtrsn.id, wkrtrsn.worker_id, wkrtrsn.type, wkrtrsn.amount);
                total += wkrtrsn.amount;
            }
            else if (strcmp(trsntype, "all") == 0)
            {
                // printf("%s-%s-%d", wkrtrsn.type, trsntype, strcmp(wkrtrsn.type, trsntype));
                printf("%s\t%s\t%s\t\t%s\t\t\t%d\n", wkrtrsn.date, wkrtrsn.id, wkrtrsn.worker_id, wkrtrsn.type, wkrtrsn.amount);
                if (strcmp(wkrtrsn.type, "credit") == 0)
                {
                    total += wkrtrsn.amount;
                }
                else
                {
                    total -= wkrtrsn.amount;
                }
            }
        }
    }
    printf("\n------------------------------------------------------------------------------------------\n");

    if (strcmp(trsntype, "all") == 0)
    {
        printf("Total Outstanding Amount: %d\n", total);
    }
    else
    {
        printf("Total %s Amount: %d\n", trsntype, total);
    }
    printf("------------------------------------------------------------------------------------------\n");

    fclose(f);
}

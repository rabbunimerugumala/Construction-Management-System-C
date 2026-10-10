// OWNER STRUCTURE..
struct Owner
{
    char name[60];
    char phone_number[13];
    char address[50];
};

// PROJECT STRUCTURE..
struct Project
{
    char id[12];
    char name[50];
    char type[20];
    char status[10];
    int cost_per_sqft;
    int total_sqft;
    int budget;
    char start_date[10];
    char end_date[10];
    struct Owner ownr;
} proj;

// PROJECT TRANSACTION STRUCTURE..
struct Transaction
{
    char project_id[8];
    char id[16];
    char date[10];
    int amount;
} trsn;

// WORKERS STRUCTURE..
struct Worker
{
    char name[60];
    char id[8];
    char type[8];
    char phone_number[13];
    char address[50];
    char gender[1];
    int adv_amount;
    int wage;

} wkr;

// WORKERS TRANSACTION STRUCTURE..
struct WorkerTransaction
{
    char date[14];
    char id[18];
    char worker_id[8];
    char type[8];
    int amount;
} wkrtrsn;

// ATTENDANCE STRUCTURE..
struct Attendance
{
    char date[14];
    char project_id[8];
    char worker_id[8];
    char status[3];

} atd;
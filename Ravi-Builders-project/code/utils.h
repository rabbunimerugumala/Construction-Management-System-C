#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vaildate_workerid(char *, char *);
int vaildate_projectid(char *, char *);
int vaildate_project_trsnid(char *, char *);
int vaildate_worker_trsnid(char *, char *);

int vaildate_workerid(char *filename, char *id)
{
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    while (fread(&wkr, sizeof(wkr), 1, f) == 1)
    {
        if (strcmp(wkr.id, id) == 0)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int vaildate_projectid(char *filename, char *id)
{
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    while (fread(&proj, sizeof(proj), 1, f) == 1)
    {
        printf("%s %s\n", proj.id, id);
        if (strcmp(proj.id, id) == 0)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int vaildate_project_trsnid(char *filename, char *id)
{
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    while (fread(&trsn, sizeof(trsn), 1, f) == 1)
    {
        if (strcmp(trsn.id, id) == 0)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int vaildate_worker_trsnid(char *filename, char *id)
{
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("*** ERROR:file not found ***");
        exit(1);
    }
    while (fread(&wkrtrsn, sizeof(wkrtrsn), 1, f) == 1)
    {
        if (strcmp(wkrtrsn.id, id) == 0)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

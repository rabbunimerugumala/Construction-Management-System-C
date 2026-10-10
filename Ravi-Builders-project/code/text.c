#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "models.h"
#include "utils.h"
#include "project.h"
#include "workers.h"
#include "attendance.h"
void main()
{
    char proj_filepath[200] = "C:\\Users\\rabbu\\OneDrive\\Documents\\coding\\c\\Ravi-Builders-project\\data\\project_data.dat";
    printf("%d", vaildate_projectid(proj_filepath, "RBP0001"));
}
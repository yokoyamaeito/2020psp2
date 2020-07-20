#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave, double square_ave);

double i = 0;

int main(void)
{
    double val, ave = 0, square_ave = 0, var = 0, u2;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        i++;
        var = var_online(val,ave,square_ave);
        square_ave = ave_online(pow(val, 2), square_ave);
        ave = ave_online(val,ave);
    }

    u2 = (i/(i-1))*var;

    printf("smple mean: %.2f\n", ave);
    printf("sample variance: %.2f\n", var);
    printf("ulation mean (estimated): %.2f+-%.2f\n", ave, sqrt(u2/i));
    printf("ulation variance (estimated): %.2f\n", u2);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;
}

double ave_online(double val,double ave)
{
    ave = ((i-1)*ave + val) / i;
    return ave;
}

double var_online(double val,double ave, double square_ave)
{
    double var;
    var = (((i-1)* square_ave)/i + pow(val,2.0)/i) - pow(((i-1)*ave/i + val/i),2.0);
    return var;
}
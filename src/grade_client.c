#include "compute.h"

void compute_prog_1(char *host)
{
CLIENT *clnt; float	*result_1;
marks	compute_1_arg;

#ifndef	DEBUG
clnt = clnt_create (host, COMPUTE_PROG, COMPUTE_VERS, "udp");
if (clnt == NULL) { clnt_pcreateerror (host); exit (1);
}


#endif	/* DEBUG */
printf("################## Percentage and Grade Calculation Software ##################\n");
printf("Enter the marks scored in Microprocessor course (out of 100) : ");


scanf("%d",&(compute_1_arg.micro));
printf("Enter the marks scored in Operating Systems course (out of 100) : ");
scanf("%d",&(compute_1_arg.os));
printf("Enter the marks scored in Math course (out of 100) : ");
scanf("%d",&(compute_1_arg.math));
printf("Enter the marks scored in Java course (out of 100) : ");
scanf("%d",&(compute_1_arg.java));
printf("Enter the marks scored in Web Programming course (out of 100) : ");
scanf("%d",&(compute_1_arg.iwp));

result_1 = compute_1(&compute_1_arg, clnt); if (result_1 == (float *) NULL) {
clnt_perror (clnt, "call failed");
}

else{
printf("Your Percentage is : %f%\n",*result_1); if(*result_1>=90)
printf("You have secured S grade!!"); else if (*result_1>=80 && *result_1<90)
printf("You have secured A grade!!"); else if (*result_1>=70 && *result_1<80)
printf("You have secured B grade!!"); else if(*result_1>=60 && *result_1<70)
printf("You have secured C grade!!"); else if(*result_1>=50 && *result_1<60)
printf("You have secured D grade!!");
else
printf("You have secured E grade!!");

}
#ifndef	DEBUG
clnt_destroy (clnt); #endif	/* DEBUG */
}


int
main (int argc, char *argv[])
{
char *host;

if (argc < 2) {
printf ("usage: %s server_host\n", argv[0]); exit (1);
}
host = argv[1];
 
12

compute_prog_1 (host); exit (0);
}


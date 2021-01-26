#include "compute.h" 
float * compute_1_svc(marks *argp, struct svc_req *rqstp)
{
static float result;
float total = (argp->micro + argp->os + argp->iwp + argp->java + argp->math);
float per = total/500;
result = per*100;
printf("compute() is called. This function returns the student's percentage");

return &result;
}



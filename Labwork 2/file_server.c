/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "file.h"

int* transfer_file_1_svc(file* argp, struct svc_req* rqstp)
{
	static int  result;
	FILE* fp;
	fp = fopen("received.txt", "a");
	if (fp == NULL) {
		perror("Error in reading file..\n");
		exit(1);
	}

	fwrite(argp->buffer, 1, argp->buffer_size, fp);
	printf("%s \n", argp->buffer);
	fclose(fp);

	return &result;
}

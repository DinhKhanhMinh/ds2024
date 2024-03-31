/*
 This file was generated using rpcgen.
 */

#include <memory.h> // for memset
#include "file.h"

// Default timeout can be changed using clnt_control()
static struct timeval TIMEOUT = { 25, 0 };

int *
transfer_file_1(file *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, transfer_file,
		(xdrproc_t) xdr_file, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

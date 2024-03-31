/*
 This file was generated using rpcgen.
 */

#ifndef _FILE_H_RPCGEN
#define _FILE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SIZE 1024

struct file {
	char filename[MAX_SIZE];
	char buffer[MAX_SIZE];
	int buffer_size;
};
typedef struct file file;

#define FILESTRANSFER 0x31230000
#define FILESTRANSFER_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define transfer_file 1
extern  int * transfer_file_1(file *, CLIENT *);
extern  int * transfer_file_1_svc(file *, struct svc_req *);
extern int filestransfer_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else // K&R C
#define transfer_file 1
extern  int * transfer_file_1();
extern  int * transfer_file_1_svc();
extern int filestransfer_1_freeresult ();
#endif // K&R C

// the xdr functions

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_file (XDR *, file*);

#else // K&R C
extern bool_t xdr_file ();

#endif // K&R C

#ifdef __cplusplus
}
#endif

#endif // !_FILE_H_RPCGEN

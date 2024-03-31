/*
 This file was generated using rpcgen.
 */

#include "file.h"

bool_t
xdr_file (XDR *xdrs, file *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->filename, MAX_SIZE,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->buffer, MAX_SIZE,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->buffer_size))
		 return FALSE;
	return TRUE;
}

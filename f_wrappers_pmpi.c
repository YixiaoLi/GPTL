#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_MPI
#include <mpi.h>
#endif

#if ( defined FORTRANCAPS )

#define iargc IARGC
#define getarg GETARG
#define mpi_init MPI_INIT
#define mpi_finalize MPI_FINALIZE
#define mpi_send MPI_SEND
#define mpi_recv MPI_RECV
#define mpi_sendrecv MPI_SENDRECV
#define mpi_isend MPI_ISEND
#define mpi_irecv MPI_IRECV
#define mpi_wait MPI_WAIT
#define mpi_waitall MPI_WAITALL
#define mpi_barrier MPI_BARRIER
#define mpi_bcast MPI_BCAST
#define mpi_allreduce MPI_ALLREDUCE
#define mpi_gather MPI_GATHER
#define mpi_gatherv MPI_GATHERV
#define mpi_scatter MPI_SCATTER
#define mpi_alltoall MPI_ALLTOALL
#define mpi_reduce MPI_REDUCE
#define mpi_allgather MPI_ALLGATHER
#define mpi_allgatherv MPI_ALLGATHERV
#define mpi_iprobe MPI_IPROBE
#define mpi_probe MPI_PROBE
#define mpi_ssend MPI_SSEND
#define mpi_alltoallv MPI_ALLTOALLV
#define mpi_scatterv MPI_SCATTERV
#define mpi_test MPI_TEST

#elif ( defined FORTRANUNDERSCORE )

#define iargc iargc_
#define getarg getarg_
#define mpi_init mpi_init_
#define mpi_finalize mpi_finalize_
#define mpi_send mpi_send_
#define mpi_recv mpi_recv_
#define mpi_sendrecv mpi_sendrecv_
#define mpi_isend mpi_isend_
#define mpi_irecv mpi_irecv_
#define mpi_wait mpi_wait_
#define mpi_waitall mpi_waitall_
#define mpi_barrier mpi_barrier_
#define mpi_bcast mpi_bcast_
#define mpi_allreduce mpi_allreduce_
#define mpi_gather mpi_gather_
#define mpi_gatherv mpi_gatherv_
#define mpi_scatter mpi_scatter_
#define mpi_alltoall mpi_alltoall_
#define mpi_reduce mpi_reduce_
#define mpi_allgather mpi_allgather_
#define mpi_allgatherv mpi_allgatherv_
#define mpi_iprobe mpi_iprobe_
#define mpi_probe mpi_probe_
#define mpi_ssend mpi_ssend_
#define mpi_alltoallv mpi_alltoallv_
#define mpi_scatterv mpi_scatterv_
#define mpi_test mpi_test_

#elif ( defined FORTRANDOUBLEUNDERSCORE )

#define iargc iargc_
#define getarg getarg_
#define mpi_init mpi_init__
#define mpi_finalize mpi_finalize__
#define mpi_send mpi_send__
#define mpi_recv mpi_recv__
#define mpi_sendrecv mpi_sendrecv__
#define mpi_isend mpi_isend__
#define mpi_irecv mpi_irecv__
#define mpi_wait mpi_wait__
#define mpi_waitall mpi_waitall__
#define mpi_barrier mpi_barrier__
#define mpi_bcast mpi_bcast__
#define mpi_allreduce mpi_allreduce__
#define mpi_gather mpi_gather__
#define mpi_gatherv mpi_gatherv__
#define mpi_scatter mpi_scatter__
#define mpi_alltoall mpi_alltoall__
#define mpi_reduce mpi_reduce__
#define mpi_allgather mpi_allgather__
#define mpi_allgatherv mpi_allgatherv__
#define mpi_iprobe mpi_iprobe__
#define mpi_probe mpi_probe__
#define mpi_ssend mpi_ssend__
#define mpi_alltoallv mpi_alltoallv__
#define mpi_scatterv mpi_scatterv__
#define mpi_test mpi_test__

#endif

#ifdef HAVE_IARGCGETARG
void mpi_init (MPI_Fint *ierr);
void mpi_finalize (MPI_Fint *ierr);
#endif

#ifdef HAVE_MPI

/*
** Wart needed for MPI_Waitall
*/

#ifndef MPI_STATUS_SIZE
#define MPI_STATUS_SIZE 5
#endif

/*
** Local prototypes
*/

void mpi_send (void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest,
	       MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_recv (void *buf, MPI_Fint *count, MPI_Fint *datatype, 
	       MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, 
	       MPI_Fint *status, MPI_Fint *__ierr);
void mpi_sendrecv (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, 
		   MPI_Fint *dest, MPI_Fint *sendtag, 
		   void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		   MPI_Fint *source, MPI_Fint *recvtag, 
		   MPI_Fint *comm, MPI_Fint *status, MPI_Fint *__ierr);
void mpi_isend (void *buf, MPI_Fint *count, MPI_Fint *datatype, 
		MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, 
		MPI_Fint *request, MPI_Fint *__ierr);
void mpi_irecv (void *buf, MPI_Fint *count, MPI_Fint *datatype, 
		MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, 
		MPI_Fint *request, MPI_Fint *__ierr);
void mpi_wait (MPI_Fint *request, MPI_Fint *status, MPI_Fint *__ierr);
void mpi_waitall (MPI_Fint *count, MPI_Fint array_of_requests[], 
                  MPI_Fint array_of_statuses[][MPI_STATUS_SIZE], 
                  MPI_Fint *__ierr);
void mpi_barrier (MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_bcast (void *buffer, MPI_Fint *count, MPI_Fint *datatype, 
		MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_allreduce (void *sendbuf, void *recvbuf, MPI_Fint *count, 
		    MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm,
		    MPI_Fint *__ierr);
void mpi_gather (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		 void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		 MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_gatherv (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		  void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs,
		  MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_scatter (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, 
		  void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		  MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_alltoall (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		   void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		   MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_reduce (void *sendbuf, void *recvbuf, MPI_Fint *count, 
		 MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, 
		 MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_allgather (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		    void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		    MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_allgatherv (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, 
		     void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, 
		     MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_iprobe (MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm,
		 MPI_Fint *flag, MPI_Fint *status, MPI_Fint *__ierr);
void mpi_probe (MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm,
		MPI_Fint *status, MPI_Fint *__ierr);
void mpi_ssend (void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest,
		MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *__ierr);
void mpi_alltoallv (void *sendbuf, MPI_Fint *sendcnts, MPI_Fint *sdispls, 
		    MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcnts,
		    MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, 
		    MPI_Fint *__ierr);
void mpi_scatterv (void *sendbuf, MPI_Fint *sendcnts, MPI_Fint *displs, 
		   MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcnt,
		   MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, 
		   MPI_Fint *__ierr );
void mpi_test (MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status, 
	       MPI_Fint *__ierr );

#ifdef ENABLE_PMPI
/*
** These routines were adapted from the FPMPI distribution. They ensure profiling of 
** Fortran codes, using the routines defined in pmpi.c
*/

/*
** mpi_init requires iargc and getarg. If these exist, define mpi_init and mpi_finalize
** wrappers so that GPTLinitialize and GPTLpr will be called.
*/

#ifdef HAVE_IARGCGETARG
extern int iargc (void);
extern void getarg (int *, char *, int);

void mpi_init (MPI_Fint *ierr)
{
  int Argc;
  int i, argsize = 1024;
  char **Argv, *p;
  int  ArgcSave;           /* Save the argument count */
  char **ArgvSave;         /* Save the pointer to the argument vector */
  char **ArgvValSave;      /* Save entries in the argument vector */

/* Recover the args with the Fortran routines iargc and getarg */
  ArgcSave    = Argc = iargc() + 1; 
  ArgvSave    = Argv = (char **) malloc (Argc * sizeof(char *));
  ArgvValSave = (char**) malloc (Argc * sizeof(char *));
  if ( ! Argv) {
    fprintf (stderr, "Out of space in MPI_INIT");
    *ierr = -1;
    return;
  }

  for (i = 0; i < Argc; i++) {
    ArgvValSave[i] = Argv[i] = (char *) malloc (argsize + 1);
    if ( ! Argv[i]) {
      fprintf (stderr, "Out of space in MPI_INIT");
      *ierr = -1;
      return;
    }
    getarg (&i, Argv[i], argsize);

    /* Trim trailing blanks */
    p = Argv[i] + argsize - 1;
    while (p > Argv[i]) {
      if (*p != ' ') {
	p[1] = '\0';
	break;
      }
      p--;
    }
  }
  
  *ierr = MPI_Init (&Argc, &Argv);
    
  /* Recover space */
  for (i = 0; i < ArgcSave; i++) {
    free (ArgvValSave[i]);
  }
  free (ArgvValSave);
  free (ArgvSave);
}

void mpi_finalize (MPI_Fint *ierr)
{
  *ierr = MPI_Finalize();
}
#endif

void mpi_send (void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest,
	       MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Send (buf, *count, MPI_Type_f2c (*datatype), *dest, *tag, 
		      MPI_Comm_f2c (*comm));
}

void mpi_recv (void *buf, MPI_Fint *count, MPI_Fint *datatype, 
	       MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, 
	       MPI_Fint *status, MPI_Fint *__ierr)
{
  MPI_Status s;
  /* A local status should be used if MPI_Fint and int are different sizes */
  *__ierr = MPI_Recv (buf, *count, MPI_Type_f2c (*datatype), *source, *tag, 
		      MPI_Comm_f2c (*comm), &s);
  MPI_Status_c2f (&s, status);
}

void mpi_sendrecv (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, 
		   MPI_Fint *dest, MPI_Fint *sendtag, 
		   void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		   MPI_Fint *source, MPI_Fint *recvtag, 
		   MPI_Fint *comm, MPI_Fint *status, MPI_Fint *__ierr)
{
  MPI_Status s;
  *__ierr = MPI_Sendrecv (sendbuf, *sendcount, MPI_Type_f2c (*sendtype),
			  *dest, *sendtag, recvbuf, *recvcount,
			  MPI_Type_f2c (*recvtype), *source, *recvtag,
			  MPI_Comm_f2c (*comm), &s);
  MPI_Status_c2f (&s, status);
}

void mpi_isend (void *buf, MPI_Fint *count, MPI_Fint *datatype, 
		MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, 
		MPI_Fint *request, MPI_Fint *__ierr)
{
  MPI_Request lrequest;
  *__ierr = MPI_Isend (buf, (int) *count, MPI_Type_f2c (*datatype),
		       (int) *dest, (int) *tag, MPI_Comm_f2c (*comm),
		       &lrequest);
  *request = MPI_Request_c2f (lrequest);
}

void mpi_irecv (void *buf, MPI_Fint *count, MPI_Fint *datatype, 
		MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, 
		MPI_Fint *request, MPI_Fint *__ierr)
{
  MPI_Request lrequest;
  *__ierr = MPI_Irecv (buf, (int)*count, MPI_Type_f2c (*datatype),
		       (int)*source,(int)*tag,
		       MPI_Comm_f2c(*comm),&lrequest);
  *request = MPI_Request_c2f (lrequest);
}

void mpi_wait (MPI_Fint *request, MPI_Fint *status, MPI_Fint *__ierr)
{
  MPI_Request lrequest;
  MPI_Status c_status;

  lrequest = MPI_Request_f2c(*request);
  *__ierr = MPI_Wait(&lrequest, &c_status);
  *request = MPI_Request_c2f(lrequest);

  MPI_Status_c2f (&c_status, status);
}

/*
** mpi_waitall was simplified from the FPMPI version.
** This one has a hard limit of LOCAL_ARRAY_SIZE requests.
** If this limit is exceeded, MPI_Abort is called. There is probably
** a better solution.
*/

void mpi_waitall (MPI_Fint *count, MPI_Fint array_of_requests[], 
                  MPI_Fint array_of_statuses[][MPI_STATUS_SIZE], 
                  MPI_Fint *__ierr)
{
  const int LOCAL_ARRAY_SIZE = 1000;
  int i;
  MPI_Request lrequest[LOCAL_ARRAY_SIZE];
  MPI_Status c_status[LOCAL_ARRAY_SIZE];

  if (MPI_STATUS_SIZE != sizeof(MPI_Status)/sizeof(int)) {
    /* Warning - */
    fprintf (stderr, "Warning: The Fortran GPTL code expected the sizeof MPI_Status\n"
	     "to be %d integers but it is %d.  Rebuild GPTL and make sure that the\n"
	     "correct value is found and set in f_wrappers.c\n", MPI_STATUS_SIZE,
	     (int) (sizeof(MPI_Status)/sizeof(int)) );
    fprintf (stderr, "Aborting...\n");
    (void) MPI_Abort (MPI_COMM_WORLD, -1);
  }

  if ((int) *count > LOCAL_ARRAY_SIZE) {
    fprintf (stderr, "mpi_waitall: %d is too many requests: recompile f_wrappers.c "
	     "with LOCAL_ARRAY_SIZE > %d\n", (int)*count, LOCAL_ARRAY_SIZE);
    fprintf (stderr, "Aborting...\n");
    (void) MPI_Abort (MPI_COMM_WORLD, -1);
  }

  if ((int)*count > 0) {
    for (i = 0; i < (int)*count; i++) {
      lrequest[i] = MPI_Request_f2c (array_of_requests[i]);
    }

    *__ierr = MPI_Waitall ((int)*count, lrequest, c_status);
    /* By checking for lrequest[i] = 0, we handle persistent requests */
    for (i = 0; i < (int)*count; i++) {
      array_of_requests[i] = MPI_Request_c2f (lrequest[i]);
    }
  } else {
    *__ierr = MPI_Waitall ((int)*count, (MPI_Request *)0, c_status);
  }

  for (i = 0; i < (int)*count; i++) 
    MPI_Status_c2f (&(c_status[i]), &(array_of_statuses[i][0]));
}

void mpi_barrier (MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Barrier (MPI_Comm_f2c (*comm));
}

void mpi_bcast (void *buffer, MPI_Fint *count, MPI_Fint *datatype, 
		MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Bcast (buffer, *count, MPI_Type_f2c (*datatype), *root, 
		       MPI_Comm_f2c (*comm));
}

void mpi_allreduce (void *sendbuf, void *recvbuf, MPI_Fint *count, 
		    MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm,
		    MPI_Fint *__ierr)
{
  *__ierr = MPI_Allreduce (sendbuf, recvbuf, *count, MPI_Type_f2c (*datatype),
			   MPI_Op_f2c (*op), MPI_Comm_f2c (*comm));
}

void mpi_gather (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		 void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		 MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Gather (sendbuf, *sendcount, MPI_Type_f2c (*sendtype),
			recvbuf, *recvcount, MPI_Type_f2c (*recvtype), *root,
			MPI_Comm_f2c (*comm));
}

void mpi_gatherv (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		  void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs,
		  MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Gatherv (sendbuf, *sendcount, MPI_Type_f2c (*sendtype),
			 recvbuf, recvcounts, displs, 
			 MPI_Type_f2c (*recvtype), *root,MPI_Comm_f2c (*comm));
}

void mpi_scatter (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, 
		  void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		  MPI_Fint *root, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Scatter (sendbuf, *sendcount, MPI_Type_f2c (*sendtype), 
			 recvbuf, *recvcount, MPI_Type_f2c (*recvtype),
			 *root, MPI_Comm_f2c (*comm));
}

void mpi_alltoall (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		   void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		   MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Alltoall (sendbuf, *sendcount, MPI_Type_f2c(*sendtype),
			  recvbuf, *recvcount, MPI_Type_f2c(*recvtype), 
			  MPI_Comm_f2c (*comm));
}

void mpi_reduce (void *sendbuf, void *recvbuf, MPI_Fint *count, 
		 MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, 
		 MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Reduce (sendbuf, recvbuf, *count, MPI_Type_f2c(*datatype),
			MPI_Op_f2c(*op), *root, MPI_Comm_f2c(*comm));
}

void mpi_allgather (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype,
		    void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, 
		    MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Allgather (sendbuf, *sendcount, MPI_Type_f2c (*sendtype),
			   recvbuf, *recvcount, MPI_Type_f2c (*recvtype), 
			   MPI_Comm_f2c (*comm));
}

void mpi_allgatherv (void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, 
		     void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, 
		     MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Allgatherv (sendbuf, *sendcount, MPI_Type_f2c (*sendtype),
			    recvbuf, recvcounts, displs, 
			    MPI_Type_f2c (*recvtype), MPI_Comm_f2c (*comm));
}

void mpi_iprobe (MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm,
		 MPI_Fint *flag, MPI_Fint *status, MPI_Fint *__ierr)
{
  int        l_flag;
  MPI_Status c_status;
  *__ierr = MPI_Iprobe ((int) *source, (int) *tag, MPI_Comm_f2c (*comm),
			&l_flag, &c_status );
  /* 
  ** The following setting ASSUMES that the C value for l_flag (0=false, non-zero=true)
  ** maps properly to a Fortran logical. Have tested gfortran, Cray, Intel, PGI,
  ** Pathscale and found this to be valid in all cases.
  */

  *flag = (MPI_Fint) l_flag;
  if (l_flag) {
    MPI_Status_c2f (&c_status, status);
  }
}

void mpi_probe (MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm,
		MPI_Fint *status, MPI_Fint *__ierr)
{
  MPI_Status c_status;
  *__ierr = MPI_Probe ((int) *source, (int) *tag, MPI_Comm_f2c (*comm),
		       &c_status );
  MPI_Status_c2f (&c_status, status);
}

void mpi_ssend (void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest,
		MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *__ierr)
{
  *__ierr = MPI_Ssend (buf, *count, MPI_Type_f2c (*datatype), *dest, *tag, 
		       MPI_Comm_f2c (*comm));
}

void mpi_alltoallv (void *sendbuf, MPI_Fint *sendcnts, MPI_Fint *sdispls, 
		    MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcnts,
		    MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, 
		    MPI_Fint *__ierr)
{
  *__ierr = MPI_Alltoallv (sendbuf, sendcnts, sdispls, 
			   MPI_Type_f2c (*sendtype), recvbuf,
			   recvcnts, rdispls, MPI_Type_f2c (*recvtype),
			   MPI_Comm_f2c (*comm));
}

void mpi_scatterv (void *sendbuf, MPI_Fint *sendcnts, MPI_Fint *displs, 
		   MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcnt,
		   MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, 
		   MPI_Fint *__ierr )
{
  *__ierr = MPI_Scatterv (sendbuf, sendcnts, displs, MPI_Type_f2c (*sendtype),
			  recvbuf, *recvcnt, MPI_Type_f2c (*recvtype), *root,
			  MPI_Comm_f2c (*comm));
}

void mpi_test (MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status, 
	       MPI_Fint *__ierr )
{
  int        l_flag;
  MPI_Status c_status;
  MPI_Request lrequest = MPI_Request_f2c (*request);
  
  *__ierr = MPI_Test (&lrequest, &l_flag, &c_status);
  *request = MPI_Request_c2f (lrequest);  /* In case request is changed */

  /* 
  ** The following setting ASSUMES that the C value for l_flag (0=false, non-zero=true)
  ** maps properly to a Fortran logical. Have tested gfortran, Cray, Intel, PGI,
  ** Pathscale and found this to be valid in all cases.
  */

  *flag = (MPI_Fint) l_flag;
  if (l_flag) {
    MPI_Status_c2f (&c_status, status);
  }
}

/* ENABLE_PMPI */
#endif
/* HAVE_MPI */
#endif
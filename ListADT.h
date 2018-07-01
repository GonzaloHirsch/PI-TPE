
#ifndef _ListADT_h

#define _ListADT_h

typedef struct ListCDT * ListADT;

 struct Movement {
   char oaci[4];
   int isLocal;
   int arrivals;
   int departures;
 };

#endif

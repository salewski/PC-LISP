

/*
 | PC-LISP (C) 1984-1989 Peter J.Ashwood-Smith
 */
#include <stdio.h>
#include <math.h>
#include "lisp.h"

/*************************************************************************
 ** (member exp list) Will return the sublist of list beginning with exp**
 ** if that list is (equal) to exp. Otherwise it returns nil.           **
 *************************************************************************/
struct conscell *bumember(form)
struct conscell *form;
{      struct conscell *list,*exp;
       if ((form!=NULL)&&(form->cdrp != NULL))
       {   exp = form->carp;
           form = form->cdrp;
           if ((form!=NULL)&&(form->cdrp == NULL))
           {   for(list = form->carp; list != NULL; list = list->cdrp)
               {   if (list->celltype != CONSCELL) return(NULL);
                   if (equal(list->carp,exp))
                       return(list);
               };
               return(NULL);
           };
       };
       ierror("member");  /*  doesn't return  */
       return NULL;   /*  keep compiler happy  */
}

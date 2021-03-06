

/*
 | PC-LISP (C) 1984-1989 Peter J.Ashwood-Smith
 */
#include <stdio.h>
#include <math.h>
#include "lisp.h"



/*************************************************************************
 ** bunexploden:built in atom explosion function. Will explode an atom  **
 ** into a sequence of ascii values, one for each character.            **
 *************************************************************************/
struct conscell *bunexplode(form)
struct conscell *form;
{      char *s; struct conscell *f,*l;
       push(f); push(l);
       if  ((form!=NULL)&&(form->cdrp == NULL))
       {    if (!GetNumberOrString(form->carp,&s)) goto ERR;
            f = l = NULL;
            while(*s)
            {   f = new(CONSCELL);
                f->carp = LIST(newintop((long) *s++));
                f->cdrp = l;
                l = f;
            };
            xret(reverse(f),2);
       };
  ERR: ierror("exploden");  /*  doesn't return  */
       return NULL;   /*  keep compiler happy  */
}

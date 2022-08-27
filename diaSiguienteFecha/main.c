#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int year;

} tFecha;


int esBisiesto(tFecha ff);
tFecha siguienteDia(tFecha ff, int diaSumar);

int main()
{
    tFecha fecha = {2, 9, 1997};
    int diaASumar = 1;

    printf("fecha inicial: %d/%d/%d", fecha.dia, fecha.mes, fecha.year);

    fecha = siguienteDia(fecha, diaASumar);

    printf("\n\ndia Siguiente: %d/%d/%d", fecha.dia, fecha.mes, fecha.year);

    return 0;
}

int esBisiesto(tFecha ff)
{
    if ((ff.year % 4 == 0 && ff.year % 100 != 0) || ff.year % 400 == 0)
        return 1;
    else
        return 0;
}

tFecha siguienteDia(tFecha ff, int diaSumar)
{
   int vecDias[] = {30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // hago el vector de dias para compararlo con el dia que recibi

  // if(esBisiesto(ff.year) ff.mes == 2) DEBERIA ANDAR CON ESTE PERO NO COMPILA
    if(ff.mes == 2)
        vecDias[ff.mes-1] = 29;

    if(ff.dia + diaSumar > vecDias[ff.mes-1]) // 30 > 29
    {
       ff.dia = 1;
       ff.mes++;

       if(ff.mes > 12)
       {
           ff.mes = 1;
           ff.year++;
       }
   }
   else
    ff.dia++;

   return ff;
}

#include <stdio.h>

unsigned int funcionExponencial(int base, int exp);
unsigned int factorial(int num);
double eElevadoALaX(int tol);


int main()
{
    int x;

    printf("Ingrese el valor de x: ");
    scanf("%d", &x);

    printf("El factorial de %d es :%d \n", x, factorial(x));

    printf("e^%d = %2f", x, eElevadoALaX(x));

    return 0;
}

unsigned int funcionExponencial(int base, int exp) // no quise usar el pow
{
    int numero = 1;
    int i;

    if(exp != 0)
    {
        for(i=0; i<exp; i++)
        {
          numero = numero*base;
        }
        return numero;
    }
    else
        return numero;
}


unsigned int factorial(int num)
{
    int i = 1;
    if(num != 0)
    {
        while(num>0)
        {
            i *=num;
            num--;
        }

        return i;
    }
    else
        return num;
}

double eElevadoALaX(int tol)
{
    int resultado = 1;
    int i;

    for(i = 0; i < tol; i++)
    {
        resultado = resultado + (funcionExponencial(tol, i)/factorial(tol)); // resultado =  1 + tol^i / i!
    }

    return (double)resultado;
}


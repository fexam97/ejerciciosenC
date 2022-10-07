#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_ARCH 3
#define TAM_CAD 21

typedef struct
{
    int dni;
    char apellido[TAM_CAD];
    char nombre[TAM_CAD];
    double sueldo;
}t_empleados;

typedef struct
{
    int dni;
    char apellido[TAM_CAD];
    char nombre[TAM_CAD];
    float promedio;
}t_estudiantes;


typedef struct
{
    int dia,
    mes,
    anio;
}t_fecha;

typedef struct
{
    char ntap[50];
    int dni;
    t_fecha fnac;
    double sueldo;
}t_empl;

int crearLoteDePruebaEmp();
int crearLoteDePruebaEst();

int actualizarEmpConEst(int(*comparar)(const void*, const void*));

void mostrarArchivoEstudiantes();
void mostrarArchivoEmpleados();

int compararRegEj13(const void* emp, const void* est);

#endif // FUNCIONES_H_INCLUDED

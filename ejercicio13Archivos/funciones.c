#include "funciones.h"



int crearLoteDePruebaEmp()
{
    t_empleados vecEmp[]=
    {
        {2222, "Benedetto", "Pipa", 803.25},
        {1010, "Burgos", "Agustin", 700.5},
        {1111, "Burgos", "Agustin", 700.5},
        {5555, "El Bambino", "Tito", 123.11},
        {7071, "Espaguetti", "Robson", 519.72},
        {7777, "Espaguetti", "Tobac", 519.72},
        {4444, "Gonzalez", "Saul", 1025.32},
        {8888, "Mercury", "Jhonfer", 420.46},
        {6666, "Riquelme", "Juan Roman", 1505.32},
        {3333, "Sanchez", "Raul", 354.95}
    };
    FILE* pf;
    pf = fopen("empleados.dat", "w+b");
    if(!pf)
        return ERR_ARCH;

    fwrite(vecEmp, sizeof(vecEmp), 1, pf);
    fclose(pf);
    return 0;
}

int crearLoteDePruebaEst()
{
    t_estudiantes vecEst[] =
    {
        {4567, "Banega", "Carreta", 9.4},
        {2222, "Benedetto", "Pipa", 7.4},
        {2023, "Benedetto", "Pipa", 7.4},
        {1234, "Bermudez", "Tito", 5.7},
        {1111, "Burgos", "Agustin", 8.2},
        {7777, "Espaguetti", "Tobac", 8.7},
        {8888, "Mercury", "Jhonfer", 4.2},
        {8033, "Mercury", "Juan", 4.2},
        {6666, "Riquelme", "Juan Roman", 9.3},
        {7890, "Zanetti", "Pupi", 7.7}
    };
    FILE* pf;
    pf = fopen("estudiantes.dat", "w+b");
    if(!pf)
        return ERR_ARCH;

    fwrite(vecEst, sizeof(vecEst), 1, pf);
    fclose(pf);
    return 0;
}

int actualizarEmpConEst(int(*comparar)(const void*, const void*))
{
    t_empleados emp;
    t_estudiantes est;

    int cmp;
    FILE* fpEmp;
    FILE* fpEst;

    fpEmp = fopen("empleados.dat", "r+b");
    if(!fpEmp)
        return ERR_ARCH;
    fpEst = fopen("estudiantes.dat", "rb");
    if(!fpEst){
        fclose(fpEmp);
        return ERR_ARCH;
    }
    fread(&emp, sizeof(t_empleados), 1, fpEmp);
    fread(&est, sizeof(t_estudiantes), 1, fpEst);
    while(!feof(fpEmp) && !feof(fpEst))
    {
        if((cmp=comparar(&emp,&est)) == 0)
        {
            if(est.promedio > 7)
            {
                emp.sueldo *= 1.0728;
                fseek(fpEmp, -(long)sizeof(t_empleados), SEEK_CUR);
                fwrite(&emp, sizeof(t_empleados), 1, fpEmp);
                fseek(fpEmp, (long)0, SEEK_CUR);
            }

            fread(&emp, sizeof(t_empleados), 1, fpEmp);
            fread(&est, sizeof(t_estudiantes), 1, fpEst);
        }
        else if(cmp < 0)
                fread(&est, sizeof(t_estudiantes), 1, fpEst);
        else
                fread(&emp, sizeof(t_empleados), 1, fpEmp);
    }

    fclose(fpEmp);
    fclose(fpEst);
    return 0;
}

int compararRegEj13(const void* empleado, const void* estudiante)
{
    t_empleados* emp = (t_empleados*)empleado;
    t_estudiantes* est = (t_estudiantes*)estudiante;
    int cmp;
    if( !(cmp = strcmp(est->apellido, emp->apellido)))
            if( !(cmp = strcmp(est->nombre, emp->nombre)))
                cmp = ((est->dni) - (emp->dni));
    return cmp;
}

void mostrarArchivoEstudiantes()
{
    t_estudiantes estudiante;
    FILE* est = fopen("estudiantes.dat", "rb");
    if(est == NULL)
    {
        printf("Error al abrir el archivo de estudiantes.");
        return;
    }
    fread(&estudiante, sizeof(t_estudiantes), 1, est);
    while(!feof(est))
    {
        printf("%8d %-25s %-30s %4.2f\n", estudiante.dni, estudiante.apellido, estudiante.nombre, estudiante.promedio);
        fread(&estudiante, sizeof(t_estudiantes), 1, est);
    }
    fclose(est);
}

void mostrarArchivoEmpleados()
{
    t_empleados empleado;
    FILE* emp = fopen("empleados.dat", "rb");
    if(emp == NULL)
    {
        printf("Error al abrir el archivo de estudiantes.");
        return;
    }
    fread(&empleado, sizeof(t_empleados), 1, emp);
    while(!feof(emp))
    {
        printf("%8d %-25s %-30s %10.2lf\n", empleado.dni, empleado.apellido, empleado.nombre, empleado.sueldo);
        fread(&empleado, sizeof(t_empleados), 1, emp);
    }
    fclose(emp);
}


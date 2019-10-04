#include "Biblioteca.h"
#include "string.h"


void mostrar(sPersona persona[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(persona[i].vacio == OCUPADO)
        {
            printf("\n %02d %15s %15s       %d %20f\t",persona[i].id,persona[i].nombre,persona[i].apellido,persona[i].sector,persona[i].salario);
        }
    }
}

void mostrarUnaPersona(sPersona persona)
{
    printf("\n%02d %15s %15s       %d %20f\t\n",persona.id,persona.nombre,persona.apellido,persona.sector,persona.salario);
}

int inicializarPersonas(sPersona lista[],int cantidad)
{
    int i;
    int retorno=-1;
    if(cantidad > 0 && lista != NULL)
    {
        for(i=0; i<cantidad; i++)
        {
            lista[i].vacio = LIBRE;
        }
        retorno = 0;
    }
    return retorno;
}

int cargaAleatoriaDePersonas(sPersona persona[], int cantidad,int id)
{
    int flagEncontro = 0;
    int i;
    int retorno;

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].vacio==LIBRE)
        {
            printf("ingrese nombre ");
            fflush(stdin);
            gets(persona[i].nombre);

            printf("ingrese apellido ");
            fflush(stdin);
            gets(persona[i].apellido);

            printf("ingrese sector ");
            scanf("%d",&persona[i].sector);

            printf("ingrese salario ");
            scanf("%f",&persona[i].salario);

            persona[i].id = id;
            flagEncontro = 1;
            persona[i].vacio = OCUPADO;
            retorno = 0;
            return retorno;
            break;
        }
    }

    if(flagEncontro==0)
    {
        printf("NO HAY ESPACIO \n");
    }
    return -1;
}

int buscarIndice(sPersona lista[],int cantidad)
{
    int i;
    int id;
    printf("\nID\t     NOMBRE\t   APELLIDO\tSECTOR\t      SALARIO\t");
    mostrar(lista,cantidad);
    printf("\ningrese ID del empleado ");
    scanf("%d",&id);
    for(i=0; i<cantidad; i++)
    {
        if(id == lista[i].id)
        {
            return i;
        }
    }

    return -1;
}

int modificarEmpleado(sPersona persona[], int cantidad)
{
    int i;
    int operacion;
    i = buscarIndice(persona,cantidad);
    if(i != -1)
    {

        printf("que desea modificar?\n");
        printf("1. nombre\n");
        printf("2. apellido\n");
        printf("3. sector\n");
        printf("4. salario\n");
        scanf("%d",&operacion);
        switch(operacion)
        {
        case 1:
            printf("ingrese nuevo nombre ");
            fflush(stdin);
            gets(persona[i].nombre);
            return 0;
            break;
        case 2:
            printf("ingrese nuevo apellido ");
            fflush(stdin);
            gets(persona[i].apellido);
            return 0;
            break;
        case 3:
            printf("ingrese nuevo sector ");
            fflush(stdin);
            scanf("%d",&persona[i].sector);
            return 0;
            break;
        case 4:
            printf("ingrese nuevo salario ");
            fflush(stdin);
            scanf("%f",&persona[i].salario);
            return 0;
            break;
        }
    }
    return -1;
}


int darBaja(sPersona persona[], int cantidad)
{
    int i;
    i = buscarIndice(persona,cantidad);
    if(i !=-1)
    {
        persona[i].vacio = LIBRE;
        return 0;
    }
    return -1;
}

void ordenarPorSector(sPersona persona[],int cantidad)
{
    int i;
    int j;
    sPersona sectorAux;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(persona[i].sector>persona[j].sector)
            {
                sectorAux = persona[i];
                persona[i] = persona[j];
                persona[j] = sectorAux;
            }
        }
    }
}

void mostrarSalarioTotal(sPersona persona[],int cantidad,int id)
{
    int i;
    float salarioTotal;
    float promedio;

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].vacio == OCUPADO)
        {
            salarioTotal = salarioTotal + persona[i].salario;

        }

    }

    printf("\n\n\nel salario total es %f\n",salarioTotal);

    promedio = salarioTotal / id;

    printf("el promedio es %f\n",promedio);

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].vacio == OCUPADO)
        {
            if(promedio < persona[i].salario)
            {
                printf("\nlos empleados que superan el sueldo promedio son %s\n",persona[i].nombre);
            }
        }

    }
}

void ordenarPorApellido(sPersona persona[], int cantidad)
{
    int i;
    int j;
    sPersona apellidoAux;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(persona[i].sector == persona[j].sector && strcmp(persona[i].apellido,persona[j].apellido)>0)
            {
                apellidoAux = persona[i];
                persona[i] = persona[j];
                persona[j] = apellidoAux;
            }
        }
    }
}

int buscarLibre(sPersona lista[],int cantidad)
{
    int i;
    int index = -1;
    for(i=0; i<cantidad; i++)
    {
        if(lista[i].vacio == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}





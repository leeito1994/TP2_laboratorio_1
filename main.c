#include "Biblioteca.h"

int main()
{
    int operacion;
    int flag1=0;
    int id=0;
    int retorno;
    sPersona lasPersonas[T];
    if(inicializarPersonas(lasPersonas,T)==0)
    {
        do
        {
            printf("1. cargar empleados \n");
            printf("2. modificar empleados \n");
            printf("3. dar de baja\n");
            printf("4. mostrar lista de empleados \n");
            printf("5. para salir \n");
            printf("eleji una opcion amigo \n");
            scanf("%d",&operacion);
            while(operacion < 1 || operacion > 5)
            {
                printf("error, reingrese opcion \n");
                break;
            }

            switch(operacion)
            {
            case 1:
                id++;
                retorno = cargaAleatoriaDePersonas(lasPersonas,T,id);
                if(retorno==0)
                {
                    printf("se cargo un empleado con exito \n");
                }
                flag1=1;
                break;
            case 2:
                if(flag1 == 1)
                {
                    if(modificarEmpleado(lasPersonas,T)==0)
                        printf("se modifico con exito\n");
                }
                else
                {
                    printf("ERROR, se necesita ingresar empleados\n ");
                }

                break;
            case 3:
                if(flag1 == 1)
                {
                    if(darBaja(lasPersonas,T)==0)
                        printf("se dio de baja con exito\n");
                }
                else
                {
                    printf("ERROR, se necesita ingresar empleados \n");
                }

                break;
            case 4:
                if(flag1 == 1)
                {
                    printf("\nID\t     NOMBRE\t   APELLIDO\tSECTOR\t      SALARIO\t");
                    ordenarPorSector(lasPersonas,T);
                    ordenarPorApellido(lasPersonas,T);
                    mostrar(lasPersonas,T);
                    mostrarSalarioTotal(lasPersonas,T,id);
                }
                else
                {
                    printf("ERROR, se necesita ingresar empleados \n");
                }
                break;
            }

            system("pause");
            system("cls");

        }
        while(operacion != 5);
    }
    return 0;
}

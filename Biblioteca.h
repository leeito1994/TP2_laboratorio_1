#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "conio.h"
#define T 1000
#define OCUPADO 0
#define LIBRE 1

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int sector;
    float salario;
    int vacio;

}sPersona;

void mostrar(sPersona[],int);
/** \brief muestra la lista de empleados.
 *
 * \param [] sPersona recibe un empleado.
 * \param int cantidad
 *
 */

int inicializarPersonas(sPersona [], int);
/** \brief pone modo LIBRE a todos los lugares para cargar empleados.
 *
 * \param [] sPersona recibe un empleado.
 * \param int cantidad.
 * \return int retorna 0 si incializo correctamente.
 *
 */

 int cargaAleatoriaDePersonas(sPersona lista[], int,int);
/** \brief carga empleados aleatoriamente.
 *
 * \param lista[] sPersona recibe un espacio para un empleado.
 * \param int cantidad
 * \param int recibe el id del empleado.
 * \return int retorna 0 si cargo con exito.
 *
 */

int buscarIndice(sPersona[],int);
/** \brief busca el id de un empleado para su uso.
 *
 * \param sPersona[] un empleado.
 * \param int cantidad
 * \return int retorna 0 si encontro id correctamente.
 *
 */

int modificarEmpleado(sPersona[], int);
/** \brief modifica un campo de un empleado.
 *
 * \param sPersona[] empleado al que modifica.
 * \param int cantidad
 * \return int retorna 0 si modifico correctamente.
 *
 */

 int darBaja(sPersona[], int);
/** \brief da de baja a un empleado.
 *
 * \param sPersona[] persona a dar de baja.
 * \param int cantidad
 * \return int retorna 0 si da de baja correctamente.
 *
 */

 void ordenarPorSector(sPersona[],int);
/** \brief ordena por sector a los empleados.
 *
 * \param sPersona[] los empleados.
 * \param int cantidad
 * \return void
 *
 */

 void ordenarPorApellido(sPersona[],int);
/** \brief ordena por apellido a los empleados.
 *
 * \param sPersona[] empleados.
 * \param int cantidad
 * \return void
 *
 */

 void mostrarSalarioTotal(sPersona[],int,int);
/** \brief muestra el total y el promedio de los salarios de empleados. Tambien los salarios mayores al promedio.
 *
 * \param sPersona[] empleados
 * \param int cantidad
 * \param int ids ingresador para sacar el promedio.
 * \return void
 *
 */





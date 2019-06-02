#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include<stdlib.h>

struct huracan
{
string nombre;  // nombre del huracan
int categoria;  // categoria del huracan
int velocidad;  // velocidad del huracan 
int costo;  // costo del huracan
};

//-----------------------------------------------------
//variables globales 
string MayorDano;
string MenorDano;
string MayorVel;
int numeroHuracan=10;   // contador de huracanes para registrar
int i;   // variable para ciclos 
int opcion; // segun la opciÛn que elige el usuario
string textoTemporal; // para almacenar los datos
int numeroTemporal;

void inicializarLista (huracan *registro){
  
registro[0].nombre="TormentaTropicalDeLongBeach";
registro[0].categoria=3;
registro[0].velocidad=220;
registro[0].costo=31;

registro[1].nombre="SanDiego";
registro[1].categoria=4;
registro[1].velocidad=140;
registro[1].costo=500;

registro[2].nombre="Rosa";
registro[2].categoria=3;
registro[2].velocidad=250;
registro[2].costo=14;

registro[3].nombre="Arthur";
registro[3].categoria=4;
registro[3].velocidad=155;
registro[3].costo=10;

registro[4].nombre="Bret";
registro[4].categoria=4;
registro[4].velocidad=95;
registro[4].costo=36;

registro[5].nombre="Chantal";
registro[5].categoria=3;
registro[5].velocidad=130;
registro[5].costo=174;

registro[6].nombre="Bill";
registro[6].categoria=3;
registro[6].velocidad=215;
registro[6].costo=18;

registro[7].nombre="Maria";
registro[7].categoria=5;
registro[7].velocidad=220;
registro[7].costo=2100000;

registro[8].nombre="Lisa";
registro[8].categoria=3;
registro[8].velocidad=230;
registro[8].costo=0;

registro[9].nombre="Alex";
registro[9].categoria=2;
registro[9].velocidad=175;
registro[9].costo=1;
}

//1.  Ver la lista de huracanes registrados.
void Huracanesregistrados(huracan *registro)
{

//system("cls"); //limpia la pantalla
cout<<"-----LISTADO DE HURACANES-----"<<endl<<endl;
for (i=0; i<=sizeof(registro)+1; i++)
        {cout << i+1 <<". " << registro[i].nombre<< endl;
        }

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;
}

bool compararNombre (huracan lhs, huracan rhs) {
    return lhs.nombre < rhs.nombre; //orden ascendente (cambiar < por > para orden descendente)
}

// 2. Ordenar ascendentemente la lista de los huracanes por nombre.
void OrdenarAscendentementeNombre (huracan *registro)
{

std::sort( registro, registro+sizeof(registro)+2, compararNombre);

cout<<"-----Orden ascendente por nombre-----"<<endl<<endl;
for (i=0; i<=sizeof(registro)+1; i++)
        {cout << i+1 <<". " << registro[i].nombre<<endl;
        }

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;

}


bool compararCosto (huracan lhs, huracan rhs) {
    return lhs.costo < rhs.costo; //orden ascendente (cambiar < por > para orden descendente)
}

//3. Ordenar ascendentemente la lista de los huracanes por costo en daños..
void OrdenarAscendentementePorCosto (huracan *registro)
{

std::sort( registro, registro+sizeof(registro)+2, compararCosto);

cout<<"-----Orden ascendente por costo-----"<<endl<<endl;
for (i=0; i<=sizeof(registro)+1; i++)
        {cout << i+1 <<". " << registro[i].nombre<< "->Costo: " << registro[i].costo<<endl;
        }

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;

//MayorDano=registro[sizeof(registro)+1].nombre;
//MenorDano=registro[0].nombre;
}

bool compararV (huracan lhs, huracan rhs) {
    return lhs.velocidad > rhs.velocidad; //orden descendente (cambiar > por < para orden ascendente)
}

//4. Ordenar descendentemente la lista de los huracanes por la velocidad de los vientos. 
void OrdenardescendentementeVelocidad (huracan *registro)
{
std::sort( registro, registro+sizeof(registro)+2, compararV);

cout<<"-----Orden descendente por velocidad-----"<<endl<<endl;
for (i=0; i<=sizeof(registro)+1; i++)
        {cout << i+1 <<". " << registro[i].nombre<< "->Velocidad: " << registro[i].velocidad<<endl;
        }

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;

//MayorVel=registro[0].nombre;
}

//5. Mostrar la información de un huracán específico.
void HuracanEspecifico(huracan *registro)
{
int nHuracan;
int n;

cout << "Escriba el número (de la lista) del huracán de interés:" << endl;
cin >> nHuracan;
n=nHuracan-1;

if(n<sizeof(registro)){
cout << "Este huracan tiene las siguientes características: " << endl;
cout << "Nombre: " << registro[n].nombre << endl;
cout << "Categoría: " << registro[n].categoria << endl;
cout << "Velocidad: " << registro[n].velocidad <<"km/h" <<  endl;
cout << "Costo de daños: " << registro[n].costo <<" M.USD" <<  endl;
}
else {
        cout << "Ingrese un número válido" << endl;
}

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;

}

//6. Registrar un nuevo huracán.
void RegistrarNuevoHuracan(huracan *registro)
{
cout<<"introduzca el nombre del huracan:";
cin>>registro[numeroHuracan].nombre;
cout<<"introduzca la categoria (Escala Saffir-Simpson, entre 1 a 5):";  // solo ingreso de numeros
cin>>registro[numeroHuracan].categoria;
cout<<"velocidad (En km/h):";  // solo ingreso de numeros
cin>>registro[numeroHuracan].velocidad;
cout<<"Costo en daños materiales (En Millones de dólares):"; // solo ingreso de numeros
cin>>registro[numeroHuracan].costo;
numeroHuracan++;
}

//7. Buscar un huracan por su nombre.
void BuscarPorNombre(huracan *registro)
{
string huracanBuscado; 
int k=0; //variable para saber la posición en que se encuentra el huracan con el nombre ingresado
int n=0; //indicador para saber si se encontró un huracan con el nombre ingresado

cout << "Escriba el nombre exacto del huracan a buscar (sin espacios):" << endl;
cin >> huracanBuscado;
 
    for (int i=0; i<20; i++)
    {
 if(huracanBuscado== registro[i].nombre){
n=1;
k=i;
} 
    }//fin del for
 
if(n==1){
cout << "Este huracan tiene las siguientes características: " << endl;
cout << "Categoría: " << registro[k].categoria << endl;
cout << "Velocidad: " << registro[k].velocidad <<"km/h" <<  endl;
cout << "Costo de daños: " << registro[k].costo <<" M.USD" <<  endl;
}
else {
        cout << "El huracán no está registrado" << endl;
}

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;

}
//8. Buscar el huracán que causó más daños materiales.
void BuscarMasDanos(huracan *registro)
{
std::sort( registro, registro+sizeof(registro)+2, compararCosto);
MayorDano=registro[sizeof(registro)+1].nombre;
cout<<"El huracán que causó mayores daños fue: " <<MayorDano<<endl;

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;
}

//9. Buscar el huracán que causó menos daños materiales.
void BuscarMenosDanos(huracan *registro)
{
std::sort( registro, registro+sizeof(registro)+2, compararCosto);
MenorDano=registro[0].nombre;
cout<<"El huracán que causó menores daños fue: " <<MenorDano<<endl;

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;
}

//10. Buscar el huracán que tiene una mayor velocidad de los vientos..
void MayorVelocidad(huracan *registro)
{
std::sort( registro, registro+sizeof(registro)+2, compararV);
MayorVel=registro[0].nombre;
cout<<"El huracán con mayor velocidad fue: " <<MayorVel<<endl;

string enter; //para continuar
cout << "-----------------------------------" << endl;
cout << "Introduzca cualquier letra y presione ENTER para continuar" << endl;
cin >> enter;
}



//-----------------------------------------------------
int main()
{

huracan *registro = new huracan[20]; //huracan registro 
cout<<"----- CENTRO DE INVESTIGACION ESTADOS UNIDOS DE HURACANES -----"<<endl<<"----- B I E N V E N I D O ! -----"<<endl;

inicializarLista (registro);

int i=0;
do{
// menu de opciones del proyecto 
    cout << endl;
    cout<<"selecione una opción"<<endl;
    cout<<"Ordenamiento"<<endl;
cout<<"1= Ver la lista de huracanes registrados"<<endl;
cout<<"2= Ordenar ascendentemente la lista de los huracanes por nombre"<<endl;
cout<<"3= Ordenar ascendentemente la lista de los huracanes por costo en daños"<<endl;
cout<<"4= Ordenar descendentemente la lista de los huracanes por la velocidad"<<endl;
cout<<"Consultas al sistema"<<endl;
cout<<"5= Mostrar la información de un huracán específico"<<endl;
cout<<"6= Registrar un nuevo huracán"<<endl;
cout<<"7= Buscar un huracán por su nombre"<<endl;
cout<<"8= Buscar el huracán que causó más daños materiales"<<endl;
cout<<"9= Buscar el huracán que causó menos daños materiales"<<endl;
cout<<"10= Buscar el huracán que tiene una mayor velocidad de los vientos"<<endl;
cout<<"11= Salir"<<endl;
cin>>opcion;
switch(opcion)
{
case 1:
Huracanesregistrados(registro);
break;

case 2:
OrdenarAscendentementeNombre(registro);
break;

case 3:
OrdenarAscendentementePorCosto(registro);
break;

case 4:
OrdenardescendentementeVelocidad(registro);
break;

case 5:
HuracanEspecifico(registro);
break;

case 6:  // ingresar un nuevo huracan
if (numeroHuracan < 20)
   RegistrarNuevoHuracan(registro);  // se llama la función
   else    // si numero de huracan es mayor a 20
       cout << "Máximo de huracanes registrados - solicite mas espacio" << endl;    // para registrar mas huracanes aumentar el valor de 100
break;

case 7:
BuscarPorNombre(registro);
break;

case 8:
BuscarMasDanos(registro);
break;

case 9:
BuscarMenosDanos(registro);
break;

case 10:
MayorVelocidad(registro);
break;
   
   case 11:  // salir - finaliza 
        cout << "Gracias por usar nuestros servicios" << endl;

break;

default: // otra opción no valida
cout<<"Este # de opción no está incluido, por favor intente nuevamente"<<endl;
break;



} // cierra Switch
}while (opcion !=11); // Si es 11 finaliza y cierra

return 0;

}

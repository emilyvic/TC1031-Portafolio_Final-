//A00828347
#include <iostream>
#include <sstream> 
#include<fstream>
#include<string>

using namespace std;
#include"Dato.h"
#include"strIP.h"
#include"IPfreq.h"
#include"PriorityQueue.h"

void leeArchivo(DoubleLinkedList <Dato> &dll, DoubleLinkedList<strIP> &IPS){
    string  month, hora, mins, seg, IP, port, fault; //variables auxiliares
    int day;
    ifstream archEnt; //declarar archivo de entrada
    archEnt.open("bitacora2.txt");//abrir archivo de entrada
    
    while(!archEnt.eof()){ //mientras esté abierto el archivo
        archEnt >> month >> day;//leer tanto el mes como el día
        getline(archEnt, hora, ':'); //separar y almacenar en variable aux, ignorando :
        getline(archEnt, mins, ':');//separar y almacenar en variable aux, ignorando :
        archEnt >> seg; //leer los segundos
        getline(archEnt, IP, ':'); //leer todo el IP
        archEnt >> port; //leer el puerto
        getline (archEnt, fault); //leer la falla con espacios
        Dato dato1(month, day, stoi(hora), stoi(mins), stoi(seg), IP, port, fault);//declarar nuevo dato
        dll.addLast(dato1);//agregar el dato a la Double LinkedList de tipo dato
        strIP datIP(IP, stoi(port));//declarar nuevo dato de tipo strIP
        IPS.addLast(datIP);//agregar el nuevo dato a la lista de strIP
    }
    archEnt.close(); //Cerrar el archivo
}

template<class T>
void heapSort(DoubleLinkedList<T> &dllist, string order="a"){
    PriorityQueue<T> heapAux(dllist); //inicializar heap auxiliar con los datos de la lista y arreglarlos en orden de prioridad
    dllist.clear();//limpiar la lista de todos los datos
    while(!heapAux.isEmpty()){//mientras todavia no se vacie la lista
        if(order == "a"){//para orden ascendente
            dllist.addFirst(heapAux.remove()); //recoger los elementos de la heap y agregarlos al principio de la lista
        }else{ //para orden descendente
            dllist.addLast(heapAux.remove());//recoger los elementos de la heap y agregarlos al final de la lista
        }
    }
}

void count(DoubleLinkedList <strIP> dll, PriorityQueue<strIP> &heap){
    int cont =1; //inicializar el contador
    for(int i =2; i<=dll.getSize(); i++){//recorrer toda la lista desde el segundo elemento
        if(dll[i-1] != dll[i]){//cuando el elemento anterior sea diferente al actual
            strIP dat(dll[i-1].IP, dll[i-1].port, cont);//generar un dato de tipo strIP con el IP y la cantidad
            heap.insert(dat);//insertar el dato al final de la heap 
            cont = 0; //volver a inicializar el contador
        }
        cont++;//actualizar contador
        if(i==dll.getSize()){
            strIP dat(dll[i].IP, dll[i].port, cont);//generar un dato de tipo strIP con el IP y la cantidad
            heap.insert(dat);//insertar el dato al final de la heap 
        }else if(i==dll.getSize() && dll[i-1] != dll[i]){
            strIP dat(dll[i].IP, dll[i].port, cont+1);//generar un dato de tipo strIP con el IP y la cantidad
            heap.insert(dat);//insertar el dato al final de la heap 
        }
    }
}

//Funcion para obtener los 5 datos mas accedidos de la lista
void getTop5(PriorityQueue<strIP> data, DoubleLinkedList<IPfreq> &result){
    while(!data.isEmpty()){ //mientras la heap no este vacia
        strIP s = data.remove(); //guardar en un dato cada dato que se quita de la lista
        IPfreq f (s.IP, s.port, s.count); //inicializar cada dato de la estructura con los parametros del dato s
        result.addFirst(f);//agregar cada dato al inicio de la lista
    }
    heapSort(result, "d"); //ordenar descendentemente todos los datos de la lista
    for(int i=1; i<=5; i++){ //recorrer unicamente los 5 primeros datos
        cout<< result[i];//imprimir cada dato
    }
    cout <<endl;//salto de linea
}

int main(){
    DoubleLinkedList <Dato> data; //declarar DoubleLinkedList de tipo dato
    DoubleLinkedList <strIP> IPS;//declarar DoubleLinkedList de tipo string para almacenar los IPS

    DoubleLinkedList <IPfreq> top5;//declarar DoubleLinkedList de tipo string para almacenar los IPS
    PriorityQueue<strIP> heapIPS; //Meter los datos a un binary heap

    leeArchivo(data, IPS);//invocar a la función que lee el archivo

    cout <<"\n*** 1. CARGANDO LOS SIGUIENTES DATOS A LA LISTA DE DATOS***"<<endl;
    data.print();//imprimir los datos del archivo que se cargaron

    cout <<"\n *** 2. ORDENANDO LOS DATOS POR IP COMPLETO: ***" <<
    "\n __________________________________________________________"<<endl;
    heapSort(data);//ORDENAR LOS DATOS DEL ARCHIVO por heap sort
    data.print();//despliega para confirmar

    //cout<<"\n *** ORDENANDO LOS DATOS de IPS: ***" <<
    //"\n __________________________________________________________"<<endl;
    heapSort(IPS);//ORDENAR LOS IPS, sin considerar puerto
    //IPS.print();

    cout <<"\n *** 3. AGRUPACION POR PUERTO IP: ***" <<
    "\n __________________________________________________________"<<endl;
    count(IPS, heapIPS);//obtener registro de todos los IPS diferentes y su cantidad
    heapIPS.print();//desplegar los datos
    
   cout <<"\n *** OBTENIENDO LOS 5 IPS MAS ACCESADOS: ***" <<
    "\n __________________________________________________________"<<endl;
    getTop5(heapIPS, top5);//invocar a la funcion

    cout<<"Programa terminado con exito"<<endl; //indicacion de que corrio todo el programa

    return 0;
}

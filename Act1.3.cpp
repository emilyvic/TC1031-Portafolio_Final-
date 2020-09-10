#include <iostream>
#include<fstream>
#include <sstream> 
#include<vector>
#include<string>
using namespace std;
#include"structureDato.h"

void leeArchivo(vector <Dato> &vect ){
    string hora, mins, seg; //variables auxiliares
    ifstream archEnt; //declarar archivo de entrada
    archEnt.open("simple.txt");//abrir archivo de entrada
    
    while(!archEnt.eof()){ //mientras esté abierto el archivo
        Dato dato1;
        archEnt >> dato1.mes >> dato1.dia;//leer tanto el mes como el día
        getline(archEnt, hora, ':'); //separar y almacenar en variable aux, ignorando :
        getline(archEnt, mins, ':');//separar y almacenar en variable aux, ignorando :
        getline(archEnt, seg,':');//separar y almacenar en variable aux, ignorando :
        archEnt >> dato1.IP;//leer el IP
        getline (archEnt, dato1.falla); //leer la falla con espacios

        dato1.hh = stoi(hora);//convertir parámetros a int
        dato1.mm = stoi(mins);//convertir parámetros a int
        dato1.ss = stoi(seg);//convertir parámetros a int
        vect.push_back(dato1);
    }
    archEnt.close(); //Cerrar el archivo
}

void imprimir (vector <Dato> vect){
    for (int i =0; i<vect.size(); i++){
        cout << vect[i].mes << endl; 
    }
}

void writeFile(){//funcion para escribir en nuevo archivo
    ofstream archSal("nuevabitacora.txt");//crear nuevo archivo
    archSal << "helloWorld" <<endl;//escribir en el archivo
    archSal.close();//cerrar el archivo
}

void cambia(int a, int b, vector <Dato> &vect){ //pos a, pos b, y vector
    Dato aux;
    aux = vect[a];
    vect[a] = vect[b];
    vect[b] = aux;  
}

void dividir(vector<Dato> &vect, int inicio, int fin, int &pivot){
    int pivVal = vect[inicio].key; //el elemento pivote es el primer elemento
    int j = inicio; // posición de inicio

    for(int i=inicio+1; i<=fin; i++ ){ //recorrer el subvector de inicio a fin
        if(vect[i].key < pivVal){ //si el elemento es menor al pivote
            j++;
            cambia(i,j,vect);//entonces ponerlo Antes del pivote
        }//de lo contrario dejarlo donde esta ()
    }
    pivot = j; //posicion de pivote
    cambia(inicio, pivot,vect); //inicializar el pivote con el elemento del inicio
}

void quickSort(vector<Dato> &vect, int inicio, int fin){
    int pivot;
    if(inicio<fin){ // si hay más de un elemento por comparar
        dividir(vect, inicio, fin, pivot);
        quickSort(vect, inicio, pivot-1);
        quickSort(vect, pivot+1, fin);
    }
}

int traduceMes(string mes){//expresar el mes en numero
    int result;
    if(mes == "Jun"){
        result = 6;
    }else if (mes == "Jul"){
        result = 7;
    }else if (mes == "Aug"){
        result = 8;
    }else if (mes == "Sep"){
        result = 9;
    }else if (mes == "Oct"){
        result = 10;
    }
    return result;//retorna el numero del mes
}

void askUser(int mot, int day, int hour, int min, int sec){
    string month;
    cout<<"Digite la Fecha en formato MMM y DD"<<endl;
    cin >> month >> day;
    mot = traduceMes(month);
    cout << "Digitar la hora exacta en formato HH MM SS" <<endl;
    cin >>hour >> min >> sec;
}

int main(){
    vector <Dato> data;//declarar vector de tipo dato
    int mes, dia, hora, minu, seg;
    leeArchivo(data);//invocar a la función que lee el archivo
    for (int i = 0; i < data.size(); i++){//recorrer todo el arreglo
        data[i].month = traduceMes(data[i].mes); //convertir el mes a un numero
        data[i].key = (data[i].month * 100000000) + (data[i].dia * 1000000) + 
        (data[i].hh * 10000) + (data[i].mm * 100) + data[i].ss; //crear una clave númerica que indique la magnitud de cada dato.
    }
    quickSort(data, 0, data.size());//odernar el vector utilizando el método de quicksort por clave num[erica]
    askUser(mes, dia, hora, minu, seg);//invocar a la funcion para preguntar datos al usuario
    
    return 0;
}

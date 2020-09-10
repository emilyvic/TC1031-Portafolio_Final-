#include <iostream>
#include<fstream>
#include <sstream> 
#include<vector>
#include<string>
using namespace std;

void imprimir (vector <Dato> vect){
    for (int i =0; i<vect.size(); i++){
        cout << vect[i] << endl;
    }
}

void writeFile(){//funcion para escribir en nuevo archivo
    ofstream archSal("nuevabitacora.txt");//crear nuevo archivo
    archSal << "helloWorld" <<endl;//escribir en el archivo
    archSal.close();//cerrar el archivo
}

void cambia(int a, int b, vector <int> &vect){ //pos a, pos b, y vector
    int aux;
    aux = vect[a];
    vect[a] = vect[b];
    vect[b] = aux;  
}

void dividir(vector<int> &vect, int inicio, int fin, int &pivot, int &comp){
    int pivVal = vect[inicio]; //el elemento pivote es el primer elemento
    int j = inicio; // posición de inicio

    for(int i=inicio+1; i<=fin; i++ ){ //recorrer el subvector de inicio a fin
        comp++;
        if(vect[i] < pivVal){ //si el elemento es menor al pivote
            j++;
            cambia(i,j,vect);//entonces ponerlo Antes del pivote
        }//de lo contrario dejarlo donde esta ()
    }
    pivot = j; //posicion de pivote
    cambia(inicio, pivot,vect); //inicializar el pivote con el elemento del inicio
}

void quickSort(vector<int> &vect, int inicio, int fin, int &comp){
    int pivot;
    if(inicio<fin){ // si hay más de un elemento por comparar
        dividir(vect, inicio, fin, pivot, comp);
        quickSort(vect, inicio, pivot-1, comp);
        quickSort(vect, pivot+1, fin, comp);
    }
}

void copiaArrVect(struct Dato arr[], vector<Dato> vect, int cant){
    for(int i=0; i<=cant;i++ ){
        vect.push_back(arr[i]);
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

int traduceHora(int hour, int min, int sec){//escribe la hora como en cantidad de segundos
    int result = 0;
    result = hour/3600;
    result+= min/60;
    result+= sec;
    return result;//retornar la cantidad de minutos
}

int main(){
    int n = 1; //cantidad de datos en el arr
    struct Dato {
        string mes, IP, falla; //caracteristicas string del dato
        int dia, hh, mm, ss, time, month; //características del dato
    };
    vector <Dato> data;//vector de tipo dato
    string hora, mins, seg; //variables auxiliares
    struct Dato lineas[16900]; // arreglo de tipo dato
    ifstream archEnt; //declarar archivo de entrada
    archEnt.open("simple.txt");//abrir archivo de entrada

    while(!archEnt.eof()){ //mientras esté abierto el archivo
        archEnt >> lineas[n].mes >> lineas[n].dia;//leer tanto el mes como el día
        getline(archEnt, hora, ':'); //separar y almacenar en variable aux, ignorando :
        getline(archEnt, mins, ':');//separar y almacenar en variable aux, ignorando :
        getline(archEnt, seg,':');//separar y almacenar en variable aux, ignorando :
        archEnt >> lineas[n].IP;//leer el IP
        getline (archEnt, lineas[n].falla); //leer la falla con espacios

        lineas[n].hh = stoi(hora);//convertir parámetros a int
        lineas[n].mm = stoi(mins);//convertir parámetros a int
        lineas[n].ss = stoi(seg);//convertir parámetros a int
        n++; //actualizar cantidad de datos
    }
    archEnt.close(); //Cerrar el archivo
    cout << n << endl; // imprimir cantidad de datos

    for (int j = 0; j < n; j++){//recorrer todo el arreglo
        lineas[j].month = traduceMes(lineas[j].mes); //convertir el mes a un numero
        lineas[j].time = traduceHora(lineas[j].hh, lineas[j].mm, lineas[j].ss ); //convertir la hora exacta a cantidad de segundos
    }
    return 0;
}

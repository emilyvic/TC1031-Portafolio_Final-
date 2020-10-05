//A00828347
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
    archEnt.open("bitacora.txt");//abrir archivo de entrada
    
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
        vect.push_back(dato1);//agregar el dato al vector
    }
    archEnt.close(); //Cerrar el archivo
}

void imprimir (vector <Dato> vect){
    for (int i =0; i<vect.size(); i++){
        cout << vect[i].mes << " " << vect[i].dia << " " << vect[i].hh 
        << ":" << vect[i].mm << ":" << vect[i].ss << " " << vect[i].IP << " " << vect[i].falla<<endl; 
    }
}

void writeFile(vector <Dato> vect){//funcion para escribir en nuevo archivo
    ofstream archSal("nuevabitacora.txt");//crear nuevo archivo
    
    for (int i =0; i<vect.size(); i++){
    archSal << vect[i].mes << " " << vect[i].dia << " " << vect[i].hh 
        << ":" << vect[i].mm << ":" << vect[i].ss << " " << vect[i].IP << " " << vect[i].falla<<endl; 
    }
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
    // Complejidad: O(nlog(n))
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

void askUser(int &key1, int &key2){
    int mot, day, hour, min, sec; //datos para inferior
    int mot2, day2, hour2, min2, sec2; //datos para superior
    string month, month2; //variables auxiliares para conversion
    cout <<"DATOS LIMITE INFERIOR:"
    <<" \n Digite la Fecha en formato MMM DD HH MM SS"<<endl;
    cin >> month >> day >> hour >> min >> sec;
    mot = traduceMes(month);

    cout <<"DATOS LIMITE SUPERIOR:"
    <<" \n Digite la Fecha en formato MMM DD HH MM SS"<<endl;
    cin >> month2 >> day2 >> hour2 >> min2 >> sec2;
    mot2 = traduceMes(month2);

    key1 = (mot * 100000000) + (day * 1000000) + (hour * 10000) + (min * 100) + sec;
    key2 = (mot2 * 100000000) + (day2 * 1000000) + (hour2 * 10000) + (min2 * 100) + sec2;
}

int busqBin(vector<Dato> vect, int key){
    int cant = vect.size();

    int low, high, mid;
    int result = -2;
    low = 0; // El primer elemento del vector 
    high = cant-1; // El ultimo elemento del vector

    while( (low <= high)){ //mientras no se haya encontrado el elemento o se llegue al final de las particiones de búsqueda
        mid = (high + low)/2; //la posicion de la mitad sera el promedio entre el menor y el mayor
        
        if ( (key <= vect[mid].key) && (key>vect[mid-1].key) ){ //si la clave en la mitad es menor o igual a la buscada y la anterior es menor
            result = mid; // retornar la posición de la mitad como rango superior
            break; //se ha encontrado elemento, entonces se puede salir
        }else if ( (key > vect[mid].key) && (key>vect[mid-1].key)){// si tanto el elemento de la mitad es menor como el anterior, entonces establecer mitad como nuevo low
                low = mid +1; // el elemento siguiente de la mitad será el nuevo menor
        }else{ //si tanto el elemento de la mitad es mayor como el anterior, entonces establecer mitad como nuevo low
                high = mid -1;//entonces el anterior al de la mitad será el nuevo mayor 
        }
    }
    return result;
    //Complejidad: O(log(n))
}

void crearRango(vector<Dato> datos, vector<Dato> &result, int inf, int sup){
    for(int i = inf; i<sup; i++){
        result.push_back(datos[i]); 
    }
}

int main(){
    vector <Dato> data, result;//declarar vector de tipo dato
    int key1, key2, limI, limS;
    leeArchivo(data);//invocar a la función que lee el archivo
    for (int i = 0; i < data.size(); i++){//recorrer todo el arreglo
        data[i].month = traduceMes(data[i].mes); //convertir el mes a un numero
        data[i].key = (data[i].month * 100000000) + (data[i].dia * 1000000) + 
        (data[i].hh * 10000) + (data[i].mm * 100) + data[i].ss; //crear una clave númerica que indique la magnitud de cada dato.
    }
    quickSort(data, 0, data.size());//odernar el vector utilizando el método de quicksort por clave num[erica]
    cout <<"***DATOS ORDENADOS: ***"<<endl;
    imprimir(data);//imprimir los datos ordenados
    writeFile(data);//Escribir el nuevo archivo ordenado en un archivo nuevo
    askUser(key1, key2);//preguntar datos al usuario
    cout <<key1<<endl;
    cout <<key2<<endl;
    limI = busqBin(data, key1);//buscar la posición de primer elemento mayor a esa fecha
    limS = busqBin(data, key2);//buscar la posición del primer elemento menor a esta fecha.
    //cout << "Inferior: " << limI << endl;
    //cout << "Superior: " << limS << endl;
    crearRango(data, result, limI, limS);
    cout <<"***DATOS DEL RANGO SOLICITADO: ***"<<endl;
    imprimir(result);//imprimir los datos del rango solicitado
    return 0;
}

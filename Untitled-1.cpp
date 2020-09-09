#include<iostream>
#include<string>

using namespace std;

int main(){
    fstream archEnt; //declarar archivo de entrada
    archEnt.open("bitacora.txt");//abrir archivo de entrada 
    int n = 0; //cantidad de datos en el arr
    string line, word, pal, arr[50]; //variables auxiliares
    struct Dato {
        string mes, hora, IP, falla; //caracteristicas string del dato
        int dia; //características del dato
    }; //declarar objeto de tipo dato
    struct Dato lineas[10]; //declarar arreglo de tipo dato

    while(getline(archEnt, line)){ //mientras todavía haya líneas que leer en el archivo
        stringstream s(line); //separar las líneas
        int i = 0; //contador de palabras
        while(getline(s, word, ' ') ){
            arr[i++] = word; //capturar cada palabra
        }

        lineas[n].mes = arr[0]; //asignar el mes
        lineas[n].dia = stoi(arr[1]); // asignar el día
        lineas[n].hora = arr[2];//asignar la hora
        lineas[n].IP = arr[3];//asignar el IP

        pal = " "; //reiniciar la palabra

        for (int j=4; j<i; j++){ //Porque la falla son distintas palabras, entonces sera igual a la palabra de la posicion 5 en adelante
            pal += " " + arr[j];
        }
        lineas[n].falla = pal; //asignar el mensaje de falla
        n++; //actualizar la cantidad de datos
    }
    archEnt.close(); //Cerrar el archivo de entrada
    cout << "cant" << endl;
    return 0;
}



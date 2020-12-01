template<class T> struct Hash;

template<class T> 
struct Hash{ //definir clase List
    private:
        vector<T> tabla;
        vector<char> status;//vector de status
        vector<int> pos; //vector posicion b
        vector<vector<T>> tablaChain; //vector de vectores encadenados
        int tam; //tamano de la tabla
        void updateVertexes(vector<T> &vertexes);
    public:
        Hash();
        Hash(vector<T> &lista);//constructor por parametros
        void lineal(vector<T> lista); //metodo lineal
        void quadratic(vector<T> lista); //metodo cuadratico
        void chain(vector<T> lista);
        void printTable(); //metodo para imprimir
        void printChainTable(); //metodo para imprimir
        int findVposLin(T vertex);  
        int findVposQua(T vertex);      
};

template<class T>
Hash<T>::Hash(){

}

template<class T>
Hash<T>::Hash(vector<T> &lista){
    tam = lista.size();
    //Inicializar vector key, vector pos
    vector<int> key_aux(tam);
    pos = key_aux;

    //Inicializar vector tablaChain
    vector<vector<T>> chain_aux(tam);
    tablaChain = chain_aux;

    //Técnica de Hashing
    for(int i=0; i<tam; i++){ //recorrer todos los elementos del vector
        pos[i] = lista[i].createHashKey()%tam; //la posicion sera el modulo de la llave
    }
    //lineal(lista);
    quadratic(lista);
    updateVertexes(lista);
}
//Complejidad: O(N)

template<class T>
void Hash<T>::lineal(vector<T> lista){
    //Inicializar vector de status como banderas vacias: 'v'
    vector<char> aux_status(tam, 'v');
    status = aux_status;

    //Inicializar vector tabla
    vector<T> t_aux(tam);
    tabla = t_aux;

    cout<<"* * * Manejo de Colisiones Lineal: * * *" <<endl;
    int pos_aux;
    //Prueba Lineal
    tabla[pos[0]] = lista[0]; //asignar el primer dato obtenido de la lista a la primera posicion
    status[pos[0]] = 'o'; //cambiar status a ocupado en la primera celda
    for(int i=1; i<tam; i++){
        pos_aux = pos[i]; //la posicion auxiliar sera la posicion indicada por el vector posicion
        if(status[pos_aux] != 'v' ){ //si la posicion ya esta ocupada
            while(status[pos_aux] == 'o'){//mientras la casilla en la posicion indicada este ocupada
                pos_aux++;//saltar a la siguiente posicion
                if(pos_aux >= tam){//al llegar al elemento final de la tabla
                    pos_aux = 0;//saltar a la posicion 0
                }
            }
        }
        tabla[pos_aux] = lista[i]; //el elemento de la lista se asignará a la posición auxiliar
        status[pos_aux] = 'o'; //marcar la casilla como ocupada
    }
    printTable();//imprimir la tabla
}
//Complejidad: O(n^2)

template<class T>
void Hash<T>::quadratic(vector<T> lista){
    //Inicializar vector de status como banderas vacias: 'v'
    vector<char> aux_status(tam, 'v');
    status = aux_status;

    //Inicializar vector tabla
    vector<T> str_aux(tam);
    tabla = str_aux;
    
    cout<<"* * * Manejo de Colisiones Cuadratico: * * *" <<endl;
    int pos_aux;
    tabla[pos[0]] = lista[0]; //reordernar la tabla de acuerdo a la posicion//la primera vez 
    status[pos[0]] = 'o'; //cambiar status a ocupado en la primera celda
    for(int i=1; i<tam; i++){
        pos_aux = pos[i]; 
        if(status[pos_aux] != 'v' ){ //si la posicion ya esta ocupada
            int cont =1; //inicializar el contador en 1 ya que el primer elemento ya fue asignado desde el principio
            while(status[pos_aux] == 'o'){ //mientras la casilla en la posición auxiliar esté ocupada
                pos_aux = (pos_aux + (cont*cont))%tam; //saltar a la casilla + i*i y sacar el modulo
                cont++;//incrementar el contador
            }
        }
        tabla[pos_aux] = lista[i];
        status[pos_aux] = 'o';//marcar la casilla como ocupada
    }
    printTable();
}
//Complejidad: O(n^2)

template<class T>
void Hash<T>::chain(vector<T> lista){
    cout<<"* * * Manejo de Colisiones Chain: * * *" <<endl;
    int pos_aux;
    tablaChain[pos[0]].push_back(lista[0]); //reordernar la tabla de acuerdo a la posicion//la primera vez 
    for(int i=1; i<tam; i++){
        pos_aux = pos[i]; 
        tablaChain[pos_aux].push_back(lista[i]); //asignar dicho elemento a la tabla en esa posicion
    }
    printChainTable();
}
//Complejidad: O(n)

template<class T>
void Hash<T>::updateVertexes(vector<T> &vertexes){
    vertexes = tabla;
}
//Complejidad: O(1)

template<class T>
void Hash<T>::printTable(){
    //Imprimir mi hash table
    for(int i=0; i<tam; i++){
        cout << tabla[i]<<endl;
    }
    cout <<endl;
}
//Complejidad: O(n)

template<class T>
int Hash<T>::findVposLin(T vertex){
    //Imprimir mi hash table
    int cont =1;
    int index_pos = vertex.createHashKey()%tam;    
    if(tabla[index_pos] == vertex){
        return index_pos;
    }else{
        while(tabla[index_pos] != vertex){//mientras no coincidan
            cont++;//incrementar contador por 1
            index_pos++;//incrementar la posicion
            if(index_pos >= tam){//al llegar al elemento final de la tabla
                index_pos = 0;//saltar a la posicion 0
            }
            if(cont>tam){//si ya se recorrio toda la lista y no se encontro el elemento que buscaba
                return -1;//retornar -1
            }
        }
        return index_pos; //retornar el valor de la posicion
    }

}
//Complejidad: O(n)

template<class T>
int Hash<T>::findVposQua(T vertex){
    //Imprimir mi hash table
    int cont =1, i=1;
    int index_pos = vertex.createHashKey()%tam;    
    if(tabla[index_pos] == vertex){
        return index_pos;
    }else{
        while(tabla[index_pos] != vertex){//mientras no coincidan
            index_pos = (index_pos + (i*i))%tam;//buscar en la siguiente posicion
            if(cont>tam){//si ya se recorrio toda la lista y no se encontro el elemento que buscaba
                return -1;//retornar -1
            }
            cont++;//incrementar contador por 1
            i++;
        }
        return index_pos; //retornar el valor de la posicion
    }

}
//Complejidad: O(n)

template<class T>
void Hash<T>::printChainTable(){
    //Imprimir mi hash table
    for(int i=0; i<tam; i++){
        cout << i << "-> ";
        for(auto ele: tablaChain[i]){
            cout << ele << " ";
        }
        cout <<endl;
    }
}
//Complejidad: O(n^2)
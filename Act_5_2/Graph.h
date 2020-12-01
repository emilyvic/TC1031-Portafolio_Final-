#if !defined graph_h
#define graph_h

template<class T> struct Edge;//metodo para desplegar estructura de tipo Edge<T>
template<class T>
ostream& operator<<(ostream& os, const Edge<T> &dat){
    os << dat.vertex << " " << dat.cant_adj;
    return os;
}

template<class T>
struct Edge{
    public:
        friend ostream& operator<< <T>(ostream& os, const Edge<T> &dat);
        T vertex;
        int cant_adj;
        //Sobrecargar de operadores en base a la cantidad de adyacencias del Edge
        bool operator == (Edge<T> vertex2){ //sobrecarga del operador ==
            if (cant_adj == vertex2.cant_adj){
                return true;
            }else{
                return false;
            }
        }
        void operator = (Edge<T> vertex2){ //sobrecarga del operador = con respecto a otro elemento edge
            vertex = vertex2.vertex;
            cant_adj = vertex2.cant_adj;
        }
        
        bool operator > (Edge<T> vertex2){ //sobrecarga del operador ==
            if (cant_adj > vertex2.cant_adj){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator < (Edge<T> vertex2){ //sobrecarga del operador ==
            if (cant_adj < vertex2.cant_adj){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator >= (Edge<T> vertex2){ //sobrecarga del operador ==
            if (cant_adj >= vertex2.cant_adj){
                return true;
            }else{
                return false;
            }
        }
        
        bool operator <= (Edge<T> vertex2){ //sobrecarga del operador ==
            if (cant_adj <= vertex2.cant_adj){
                return true;
            }else{
                return false;
            }
        }

        bool operator != (Edge<T> vertex2){ //sobrecarga del operador ==
            if (cant_adj != vertex2.cant_adj){
                return true;
            }else{
                return false;
            }
        }
};

template<class T>
class Graph{
    private:
        //Atributos:
        vector<vector<T>> adjList; //lista de adyacencias
        vector<T> vertexes;//lista de vertices
        Hash<T> hVertexes;
        //Metodos Privados
        void copyVertices();//metodo para copiar los vertices al vector vertices
    public:
        vector<Edge<T>> vertices; //lista de vertices y cantidad de adyacencias
        Graph();//constructor default
        Graph(stack<T> stk);//constructor con parametro stack
        int findVertex(T vertex); //funcion para buscar la posicion de un vertice
        void printPersonalAdjList(T vertex); //método para imprimir la lista de adyancencia de un solo vertice en determinado
        void addAdj(T origin, T target); //metodo para añadir una adyacencia
        void countAdj();//metodo para contar la cantidad de adyacencias
        void print();//imprimir lista de adyacencias completa
};

template<class T> //constructor por default
Graph<T>::Graph(){

}

template<class T> 
void Graph<T>::copyVertices(){
    Edge<T> e;//crear variable auxiliar tipo Edge<T>
    for(int i=0; i<vertexes.size(); i++){//recorrer todo el vector de vertices
        e.vertex = vertexes[i];//copiar cada elemento de vertexes al atributo vertex de vertices
        e.cant_adj = 0;//inicializar la cantidad de adyacencias con 0
        vertices.push_back(e);//agregar ese elemento al vector de vertices
    }
}//Complejidad O(n)


template<class T> 
Graph<T>::Graph(stack<T> stk){
    //Construir lista de vertices
    int tam = stk.size();
    for (int i=0; i<tam;i++){ //para toda la pila de elementos
        T aux = stk.top();//guardar el primer elemento del stack en una variable auxiliar
        vertexes.push_back(aux);
        stk.pop();//eliminar el primer elemento del stack
    }
    Hash<T> h_aux(vertexes); //inicializar una instancia de hash con la lista de vertices
    hVertexes = h_aux; //copiar la hash al atributo privado de la clase
    copyVertices();//copiar vertexes a lista de vertices

    vector<vector<T>> v_auxT (vertices.size());//inicializar el vector con el mismo tamaño de la cantidad de vertices
    adjList = v_auxT; //copiarlo a la lista de adyacencia
}
//Complejidad O(n)

template<class T> 
int Graph<T>::findVertex(T vertex){//buscar la posicion de un vertice
    if(hVertexes.findVposQua(vertex) >= 0){ //si la posicion si existe dentro de la lista
        return hVertexes.findVposQua(vertex); //retornar el valor de la posicion
    }else{//si no encuentra el elemento; obtiene una posicion invalida
        throw runtime_error("No existente"); //bota un error de excepción
    }
}//Complejidad: O(n)

template<class T> 
void Graph<T>::print(){
    cout <<"\n * * * LISTA DE ADYACENCIAS: * * * "<<endl;
    for (int i=0; i<vertices.size(); i++){//vector dentro de vector
        cout << "\n" << vertices[i].vertex << " -> " << "{";//desplegar el vertice 
        for(auto target: adjList[i]){//recorrer cada subvector
            cout << target << ", ";//se imprimira el vector dentro del vector
        }
        cout << "}";
    }
    cout <<endl;
}
//Complejidad: O(N^2)

template<class T> 
void Graph<T>::addAdj(T origin, T target){
    int pos = findVertex(origin);//encontrar la posicion en la que se encuentra el vertice de origen
    adjList[pos].push_back(target);//Agregar el vector target al vector de posicion de la Lista de Adyacencia en esa posicion
}//complejidad O(1)

template<class T> 
void Graph<T>::countAdj(){
    for (int i=0; i<vertexes.size(); i++){//para cada vertice
        int cant=0;
        vertices[i].cant_adj = adjList[i].size();//asignar el contador al atributo cantidad de adyacencias de vertices 
    }
}//Complejidad: O(n)

template<class T> 
void Graph<T>::printPersonalAdjList(T vertex){
    int pos = findVertex(vertex);
    cout << "\n" << vertices[pos].vertex << " -> " << "{";//desplegar el vertice 
    for(auto target: adjList[pos]){//recorrer cada subvector
        cout << target << ", ";//se imprimira el vector dentro del vector
    }
    cout << "}" <<endl;
}
//Complejidad: O(n)
#endif
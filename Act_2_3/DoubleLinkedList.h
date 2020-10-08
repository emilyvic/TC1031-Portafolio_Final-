#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include "Node.h"
#include "Queue.h"
#include <vector>

template<class T>
class DoubleLinkedList{ //definir clase List
	private:
		Node <T>* head;
        Node <T>* tail;
		int size; //tamaño de la lista 
	public:
		DoubleLinkedList();
        void print(); //método para imprimir
        bool isEmpty();//método para checar si la lista está vacía
        int getSize();//obtener el valor del tamaño
        void addFirst(T data); //para agregar un nuevo elemento dado al inicio
        void addLast(T data); //para agregar un nuevo elemento al final
        T getData(int index); //imprimir el elemento en la posicion dada
        bool updateAt(int index, T newData);//cambiar un dato en una posicion dada
        void clear(); //vaciar la lista
        int findData(T data); //encontrar un determinado dato    
        int binarySearch(T dataKey); //encontrar un determinado dato    
        void sort(); //para ordenar la lista
        void merge (int beg, int mid, int fin); //metodo merge de merge sort
        void mergeSort(int beg, int fin); //metodo merge sort
        bool updateData(T data, T newDAta);//Cambiar el primer elemento dado con uno nuevo.
        void printReverse(); //método para imprimir a la inversa
        void reverse();//invertir el orden de los elementos de la lista
        void removeHead(); //eliminar el primer elemento de la lista
        void removeTail(); //eliminar el utlimo elemento de la lista
        void deleteAt(int index);//borrar un elemento en una posicion dada
        void deleteData(T data); //para borrar un dato de la lista
        void insertAt(int index, T newData);//insertar un valor en una posicion determinada

        void operator = (vector<T> vect){ //sobrecarga del operador =
            for(int i = 0; i<vect.size(); i++){//recorrer todos los elementos del vector
                addLast(vect[i]); //anadir cada elemento del vector a la linked list
            }
        }//Complejidad O(n)
        T operator [] (int index){ //sobrecarga del operador =
            if( (!isEmpty()) && (index <= size) && (index >0) ){ //si no esta vacia
                if(index ==1 ){
                    return head->data;
                }else if (index == size){
                    return tail->data;
                }else{
                    Node<T>* aux = head; //crear una variable auxiliar que empieza en head
                    for (int i=1; i<index; i++){
                        aux = aux->next; //ir recorriendo los elementos de la lista
                    }
                    return (aux->data);
                }
            }
            else{
                throw runtime_error("No hay elementos, la lista esta vacia");
            }
        }   
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
	head = NULL; //head apunta a NULL
    tail = NULL; //tail apunta a NULL
	size = 0; //el tamaño de la lista es 0
} //Complejidad: O(N)

//método para imprimir
template<class T>
void DoubleLinkedList<T>::print(){
	Node<T>* aux = head; //crear una variable auxiliar donde de almacena head
	for (int i=0; i<size; i++){ //recorrer size veces
		cout <<( aux -> data); //imprimir el dato aux
        aux = aux -> next; //actualizar aux apuntando al dato siguiente
        cout <<endl;
    }
}//Complejidad O(n)

//método para imprimir a la inversa
template<class T>
void DoubleLinkedList<T>::printReverse(){
    cout<<"Nueva Lista: ";
	Node<T>* aux = head; //crear una variable auxiliar donde de almacena head
	for (int i=0; i<size; i++){ //recorrer size veces
		cout << (aux -> data); //imprimir el dato aux
        aux = aux -> prev; //actualizar aux apuntando al dato siguiente
        cout <<endl;
    }
}//Complejidad O(n)

//checar si la lista està vacía
template<class T>
bool DoubleLinkedList<T>::isEmpty(){
	if (size == 0){
		return true;
	}else{ 
		return false;
	}
}//Complejidad: O(N)

template<class T>
int DoubleLinkedList<T>::getSize(){
	return size;
}//Complejidad: O(N)

template<class T>
void DoubleLinkedList<T>::addFirst(T data){
	if(isEmpty()){//si es el primer elemento que se añade
        head = new Node<T>(data, head); //crear un nodo que apunta a head, y new será el nuevo head
        tail = head;
    }else if (size == 1) { // si solo hay un elemento
        Node<T> * aux = new Node<T>(data);
        aux->next = head;
        tail->prev = aux;
        head = aux;
    }else{//si hay mas de un elemento
        Node<T> * aux = new Node<T>(data, head);
        head->prev = aux;
        head = aux;
    }
	size ++; //incrementar el tamaño de la lista
} //Complejidad: O(N)


template<class T>
void DoubleLinkedList<T>::addLast(T data){
	if(isEmpty()){//si es el primer elemento que se añade
        head = new Node<T>(data, head); //crear un nodo que apunta a head, y new será el nuevo head
        tail = head;
    }else{//si hay elementos en la lista
        Node<T> * aux = new Node<T>(data, tail, tail);
        tail->next = aux;
        tail =aux;
    }
	size ++; //incrementar el tamaño de la lista
}//Complejidad: O(N)

template<class T>
void DoubleLinkedList<T>::insertAt(int index, T newData){
    if(index == size){//si la lista no está vacia
        Node<T> *aux = new Node<T>(newData);
        Node<T> *aux0 = tail->prev;
        aux0 -> next = aux;
        aux ->next = tail;
        aux->prev = aux0;
        tail->prev = aux;
        size++;
    }else if (index <= 1){//si la lista esta vacia
        addFirst(newData);// entonces agregar un primer elemento a la lista
    }else if ((index < size) && (index > 1)){
        Node<T> *aux1 = head;
        Node<T> *aux = new Node<T>(newData);
        for(int i=1; i<index; i++){
            aux1 = aux1->next;
        }
        Node<T> *aux0 = aux1->prev;
        aux0 -> next = aux;
        aux->next = aux1;
        aux -> prev = aux0;
        aux1->prev = aux;
        size++;
    }else{
        cout <<"Indice invalido"<<endl;
    }
}

template< class T>
void DoubleLinkedList<T>::removeHead(){
    if(size >= 2){//si la lista tiene mas de un elemento
        Node<T> *aux = head;
        head = head-> next;
        head->prev =NULL;
        aux-> next = NULL;
        size --;
    }else if(size ==1){//si tiene un solo elemento
        clear();
    }else{//si la lista esta vacia
        cout<<"No se puede eliminar el elemento, la lista esta vacia"<<endl;
    }    
}

template< class T>
void DoubleLinkedList<T>::removeTail(){
    if(size >= 2){//si la lista tiene mas de un elemento
        Node<T> *aux = tail;
        tail = tail-> prev;
        tail->next =NULL;
        aux-> prev = NULL;
        size --;
    }else if(size ==1){//si tiene un solo elemento
        clear();
    }else{//si la lista esta vacia
        cout<<"No se puede eliminar el elemento, la lista esta vacia"<<endl;
    }    
}

template<class T>
void DoubleLinkedList<T>::deleteAt(int index){
    if(!isEmpty()){
        if( (index > 0) && (index <=size) ){
            if(index == 1){//si es el primer elemento
                removeHead();
            }else if(index == size){ //si es el ultimo elemento
                removeTail();
            }else{
                Node<T> *aux1 = head;
                for(int i =1; i<index; i++){//recorrer la lista hasta el elemento indicado
                    aux1 = aux1->next;//actualizar variable aux
                }
                Node<T> *aux0 = aux1->prev; //auxiliar previa
                aux0->next = aux1->next; // conectar la previa con la postsiguiente
                aux1 = aux1->next;//actualizar aux a la siguiente
                aux1->prev = aux0; //conectar el apuntador previo a la anterior
                size--;//decrementar el tamano
            }
        }else{
            cout <<"Indice invalido" <<endl;
        }
    }else{ //Si la lista esta vacia
        throw runtime_error("No hay elementos, la lista esta vacia");
    }
}//Complejidad: O(N)

template<class T>
void DoubleLinkedList<T>::deleteData(T data){
    if(!isEmpty()){ //si la lista no está vacia - busca
        int index = findData(data); //buscar la pos de ese dato
        if(index!=-1){        
            deleteAt(index);
        }else{
            cout<<"No se encontro el dato que se estaba buscando"<<endl;
        }
    }else{//si la lista esta vacia
        cout<<"No se puede eliminar un elemento de una lista vacia"<<endl;
    }
}//Complejidad: O(N)	


template<class T>
T DoubleLinkedList<T>::getData(int index){
    if( (!isEmpty()) && (index <= size) && (index >0) ){ //si no esta vacia
        if(index ==1 ){
            return head->data;
        }else if (index == size){
            return tail->data;
        }else{
            Node<T>* aux = head; //crear una variable auxiliar que empieza en head
            for (int i=1; i<index; i++){
                aux = aux->next; //ir recorriendo los elementos de la lista
            }
            return (aux->data);
        }
    }
    else{
        throw runtime_error("No hay elementos, la lista esta vacia");
    }
}//Complejidad: O(N)

template<class T>
bool DoubleLinkedList<T>::updateAt(int index, T newData){
    if(!isEmpty()){//si la lista no está vacia
        if( (index <= size) && (index >0) ) {//checar si el indice es valido
            if(index == 1){ //si el indice es el primer elemento
                head->data = newData;
            }else if(index == size){//si el indice es el ultimo elemento
                tail->data = newData;
            }else{ //si el indice es diferente del primer o ultimo elemento
                Node<T>* aux = head;//crear una variable auxiliar que empieza en head
                for(int i=1; i<index; i++){
                    aux = aux -> next;//ir recorriendo los elementos de la lista
                }
                aux->data = newData;
            }    
        }else{
            throw runtime_error("Indice invalido");
        }
        return false;
    }else{
        return true;
    }
}////Complejidad: O(N)

template< class T>
void DoubleLinkedList<T>::clear(){
    if(!isEmpty()){//si la lista no está vacia
        head = NULL; //el primer dato apunta a elemento vacia
        tail = head;
        cout <<"lista vaciada con exito"<<endl;
        size = 0;
    }else{ //si la lista ya esta vacia
        cout<<"La lista ya esta vacia" <<endl;
    }
}

template<class T>
int DoubleLinkedList<T>::findData(T data){
    if(!isEmpty()){//si la lista no está vacia
        if(data == head->data){//si el dato buscado es igual al primer dato
            return 1;
        }else if (data == tail->data){
            return size;
        }else{//si no es ni el primero ni el ultimo
            bool found = false;
            int cont = 1; 
            Node<T>* aux = head->next;//crear una variable auxiliar que empieza en head
            while( (!found) && (cont<size) ){
                if(aux->data == data){
                    found = true;
                }else{
                    aux = aux -> next;//ir recorriendo los elementos de la lista
                }
                cont ++;
            }
            if(found){
                return(cont);
            }else{
                return(-1);
            }
        }
    }else{
        throw runtime_error("Lista vacia, elemento no encontrado");
    }
    
}//Complejidad: O(N)

template<class T>
int DoubleLinkedList<T>::binarySearch(T dataKey){;
    int low, high, mid;
    int result = -2;
    low = 1; // El primer elemento de la DoubleLinkedList 
    high = size; // El ultimo elemento del vector

    while( (low <= high)){ //mientras no se haya encontrado el elemento o se llegue al final de las particiones de búsqueda
        mid = (high + low)/2; //la posicion de la mitad sera el promedio entre el menor y el mayor
        
        if ( (dataKey <= getData(mid)) && (dataKey > getData(mid-1)) ){ //si la clave en la mitad es menor o igual a la buscada y la anterior es menor
            result = mid; // retornar la posición de la mitad como rango superior
            break; //se ha encontrado elemento, entonces se puede salir
        }else if ( (dataKey > getData(mid)) && (dataKey>getData(mid-1))){// si tanto el elemento de la mitad es menor como el anterior, entonces establecer mitad como nuevo low
            low = mid +1; // el elemento siguiente de la mitad será el nuevo menor
        }else{ //si tanto el elemento de la mitad es mayor como el anterior, entonces establecer mitad como nuevo low
            high = mid -1;//entonces el anterior al de la mitad será el nuevo mayor 
        }
    }
    return result;
    //Complejidad: O(log(n))
}

template<class T>
bool DoubleLinkedList<T>::updateData(T data, T newData){
    int pos = findData(data);
    return (updateAt(pos, newData));
}//Complejidad: O(N)

template<class T>
void DoubleLinkedList<T>::merge(int beg, int mid, int end){
    Queue<T> izq;
    Queue<T> der;
    int pos, tamizq, tamder, contDer, contIzq;
    pos = beg;
    tamizq = mid - beg + 1;
    tamder = end - mid;

    //construir las 2 listas
    for (contIzq = 1; contIzq<=tamizq; contIzq++){
        izq.enqueue(getData(beg+contIzq-1));
    }

    for(contDer=1;contDer<=tamder;contDer++){
        der.enqueue(getData(mid+1+contDer-1));
    }

    contIzq=1;
    contDer=1;
    // comparar los elementos de las listas
    while(contIzq<=tamizq && contDer<=tamder){

        if((izq.front()) <= (der.front()) ){
            updateAt(pos, izq.dequeue());
            contIzq++;
        }else{
            updateAt(pos,der.dequeue());
            contDer++;
        }
        pos ++;
    }
    //si hay elementos faltantes
    while(contIzq <= tamizq){
        updateAt(pos, izq.dequeue());
        contIzq++;
        pos++;
    }
    
    while(contDer <= tamder){
        updateAt(pos, der.dequeue());
        contDer++;
        pos++;
    }
}

template<class T>
void DoubleLinkedList<T>::mergeSort(int beg, int end){
    //metodo de intercambio
    if (beg < end){
        int mid = (beg + end) /2;
        mergeSort(beg, mid);
        mergeSort(mid+1, end);
        merge(beg, mid, end);
    }
}//Complejidad: O(nlog(n))

template<class T>
void DoubleLinkedList<T>::sort(){
    mergeSort(1,size);
}


template< class T>
void DoubleLinkedList<T>::reverse(){
    if(!isEmpty()){
        if(size>=2){
            Node<T> * aux = head;
            head = tail;
            tail = aux;
        }
    }else{ //si la lista esta vacia
        cout <<"No se puede invertir una lista vacia" <<endl;
    }
}

#endif
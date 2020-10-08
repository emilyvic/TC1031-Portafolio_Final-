//Autor: Emilia Victoria Jácome Iñiguez
//estructura nodo
#pragma once //para que lo agregue una sola vez en el caso de que encuentre otro con el mismo nombre

template<class T>
struct Node{
    //atributos
    Node<T> * next; //apuntador a siguiente elemento
    Node<T> * prev; //apuntador a elemento anterior
   	T data;
	//métodos
    Node( T data);
    Node(T data, Node<T>* next);
    Node(T data, Node<T>* next, Node<T>* prev);
};

//nivel logico

//constructor con un parámetro, para los primeros datos
template<class T> 
Node<T>::Node(T data){//crear un nuevo nodo
    this -> data = data;
	this-> next = NULL;
    this-> prev = NULL;
}

template<class T> 
Node<T>::Node(T data, Node<T> *next){
    this -> data = data;
    this -> next = next;
}

 //constructor con dos parámetros
template<class T> 
Node<T>::Node(T data, Node<T> *next, Node<T> *prev){
    this -> data = data;
    this -> next = NULL;
    this -> prev = prev;
}
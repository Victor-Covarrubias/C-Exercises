//insertar en cualquier lugar circular y simple enlazada

n->sig=aux->sig;
aux->sig=n;

//doble enlazada
//insertar si esta vacia
if(prim==null){
	malloc
	n->sig=null;
	n>ant=null;
	prim=n;
	ult=n;
}
//insertar al final
ult->sig=n;
n->ant=ult;
n->sig=null;
ult=n;
//insertar al inicio
n->sig=prim;
prim->ant=n;
n->ant=null;
prim=n;
//insertar en cualquier lugar
despues de cual?????????????????????????????????????
bandera=true;
aux=prim;
aux2=aux->sig;
while(bandera){
	if(dato que busco!=dato en la lista){
		aux2=aux2->sig;
		aux=aux->sig;
		bandera=false;
	}
}
aux2->ant=n;
aux->sig=n;



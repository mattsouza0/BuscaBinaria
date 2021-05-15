#include <iostream>

using namespace std;

int buscaBinaria(int elemento, int vetor[], int qtd){
	int pos = -1;
	if(qtd == 0){
		return pos;
	}else{
		int inicio=0 , fim=qtd-1;
		do{
			pos = (inicio+fim)/2;
			if(elemento < vetor[pos]){
				fim = pos-1;
			}else{
				inicio=pos+1;
			}
		}while(elemento!=vetor[pos] && inicio <=fim);
	}
	if(elemento==vetor[pos]){
		return pos;
	}else{
		return -1;
	}
}


// Dividi o vetor em dois vetores
//um a esquerda vet[esquerda..Meio] e o outro o da direita vet[M=1...direita]
void merge(int vet[],int esquerda, int M, int direita){
    int i, j, k;
    int n1 = M - esquerda + 1;
    int n2 = direita - M;
//vetores temporarios
    int Etemp[n1], Dtemp[n2];
//copia os dados para os temp
    for(i = 0 ; i < n1 ; i++){
        Etemp[i] = vet[esquerda + i];
    }
    for(j = 0 ; j < n2 ; j++){
        Dtemp[j] = vet[M+1 + j];
    }
//intercalar
    i=j=0;// Índice inicial do primeiro e do segundo subarray
    k=esquerda;//indice inicial do subvetor merged

    while(i < n1 && j < n2){
        if(Etemp[i] <= Dtemp[j]){
            vet[k] = Etemp[i];
            i++;
        }else{
            vet[k] = Dtemp[j];
            j++;
        }
        k++;
    }
    
//Copia os elementos restantes do Etemp[], se houver algum
    while(i < n1){
        vet[k] = Etemp[i];
        i++;
        k++;
    }

//Copia os elementos restantes do Dtemp[], se houver algum
    while(j < n2){
        vet[k] = Dtemp[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int esquerda, int direita){
    if(esquerda < direita)
    {
        int M = (esquerda+direita)/2;
        
        mergeSort(vetor,esquerda,M);
        mergeSort(vetor,M+1,direita);
        
        merge(vetor,esquerda,M,direita);
    }
}

void bubbleSort(int *vetor, int n){
    int aux;
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
    }
}

int main(){
    int QtdVET=0, vet[100], num, ele;

    cout<<"\nDigite valores para inserir no vetor\nPara finalizar a insercao digite 0\n";
    cin>>num;

    while(num!=0){
        if(QtdVET <= 99){
            vet[QtdVET]=num;
            QtdVET++;
            cout<<"\nDigite um numero para inserir no vetor\nPara finalizar a insercao digite 0\n";
            cin>>num; 
        }else {
            num = 0;
        }       
    }

    //bubbleSort(vet,QtdVET);
    mergeSort(vet,0,QtdVET-1);

    cout<<"\nDigite o elemento para ser pesquisado\n";
    cin>>ele;
    cout<<endl;

    //mostrar todo o vetor
    for(int i=0;i<QtdVET;i++){
        cout<<"Vetor["<<i<<"] = "<<vet[i]<<endl;
    }

    //pesquisar o valor informado
    if(buscaBinaria(ele,vet,QtdVET) == -1){
        cout<<"\nElemento nao encontrado"<<endl;
    }else
    {
        cout<<"\nElemento encontrado na posicao ";
        cout<<buscaBinaria(ele,vet,QtdVET)<<endl;
    }

}
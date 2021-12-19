#include<bits/stdc++.h>

#define vint vector<int>

using namespace std;


int graph[100][100] = {0};
int *ds = NULL;
int top = -1;
int head = 0;
int size = 0;

void grin(){
    int n,e;
    for(;;){
        cout<<"enter node"<<endl;
        cin>>n;
        cout<<"enter edge"<<endl;
        cin>>e;
        graph[n][e] = 1;
        if(n<0 || e<0) break;



    }

}


void push(int a){

    if(ds == NULL){
        ds = ( int*)malloc(sizeof(int));
        top++;
        ds[top] = a;
        size++;


    }
    else{
        size++;
        ds = (int*)realloc(ds,size*sizeof(int));
        top++;
        ds[top] = a;

    }

}


void pop(){
    cout<< ds[top];
    top--;
    size--;
    

}


void dequeue(){

    cout<<ds[head];
    head++;


}

void printstk(){
    for(int i= 0;i<size;i++) cout<<ds[i];

}

void printq(){
    for(int i= head;i<size;i++) cout<<ds[i];

}


void bfs(){
    



}
    


int main(){
    
    push(10);push(20);push(66);
    pop();
    
}

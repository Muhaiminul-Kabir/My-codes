#include<iostream>


#define null NULL

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data, struct Node* next) {
        this->data = data;
        this->next = next;
    }
};

typedef struct Node* node;

node head = null;
node rear = null;
node tail = null;
node trash = null;


node create_node(int data) {
    node new_node = null;
    // new_node = (node)malloc(sizeof(struct Node));
    new_node = new Node(data,null);
    if(head == NULL) {
        head = new_node;

    } else {
        node p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
    return head;

}


void del_FIFO() {

    node temp = head;
    if(head != null) {
        head = temp ->next;

    }
    else {
        cout<<endl<<"underflow";
    }


}



void print(node x) {
    node current_node = x;
    if(current_node == NULL) {
        cout<<endl<<"null";
    }
    while ( current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

}

node get_rear() {

    node temp = head;
    while(temp -> next!= null) {
        temp = temp->next;

    }
    return temp;

}

void del_LIFO() {

    node temp = head;

    if(temp ==  null) {
        cout<<endl<<"underflow";
        return ;
    }

    if(temp->next == null) {
        trash = temp ;
        head = null;
        cout<<endl<<"empty"<<endl;
    }
    while(temp->next != null) {


        if(temp->next == rear) {
            // cout<<endl<<"hi";
            trash = temp->next;
           // cout<<trash->next;
            temp->next = null;
            rear = temp;
            break;
        }
        temp = temp->next;

    }

}


bool emp(node head){
    return head==null;

}


int graph[5][5]={0};
int i= 0;
int j=0;
int x,y;

void graphs(){
string t ;
    for(;;){
        cout<<"vertices ";
        cin>>x;
        cout<<" edge";
        cin>>y;
        cin>>t;
        graph[x][y]=1;
        graph[y][x]=1;
        if(t=="t"){
            
            break;
        }
        
    }
    for(i = 0;i<=x;i++){
        
        for(j = 0;j<=y;j++){
            cout<<" "<<graph[i][j]<<" ";
            
        }
        cout<<endl ;
    }



}


void BFS(int start){

    bool vist[x] ={false};
    head = create_node(start);
    vist[start]=true;
    int vis;
    while(!emp(head)){
        vis = head->data;
        cout<<vis<<endl ;
        del_FIFO(); 
        
        for(int i = 0; i<=y; i++){
            if(graph[vis][i] == 1 && !(vist[i])){
            
                head = create_node(i);            
                vist[i] = true;
            
            }
        
        }
        
        
        
    }




}


int main() {
    graphs();
    BFS(0);
    
}
    

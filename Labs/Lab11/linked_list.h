#include <iostream>
#include <vector>
void mergesort(int a[], int ulimit, int llimit = 0){
    if(ulimit-llimit<2){return;}
    if(ulimit-llimit==2){
        if(a[llimit]>a[llimit+1]){
            int temp = a[llimit];
            a[llimit] = a[llimit+1];
            a[llimit+1] = temp;
        }
        return;
    }
    mergesort(a, (ulimit+llimit)/2, llimit);
    mergesort(a, ulimit, (ulimit+llimit)/2);
    int b[ulimit-llimit], k_l = llimit, k_u = (ulimit+llimit)/2;
    for(int i = 0; i<ulimit-llimit; ++i){
        if(k_l < (ulimit+llimit)/2 && k_u < ulimit){
            if(a[k_l]<=a[k_u]){b[i] = a[k_l]; ++k_l;}
            else{b[i] = a[k_u]; ++k_u;}
        }
        else if(k_l == (ulimit+llimit)/2){b[i] = a[k_u]; ++k_u;}
        else{
            b[i] = a[k_l]; ++k_l;
        }
    }
    for(int i = 0; i<ulimit-llimit; ++i){
        a[llimit+i] = b[i];
    }
    return;
}
struct Node{
    int data;
    Node* next;
};
bool Binary_search(int to_find, std::vector<Node>& v, int ulimit, int llimit){
    if(ulimit==llimit){return false;}
    if(ulimit-llimit == 1){
        return (v[llimit].data==to_find);
    }
    if(v[(ulimit+llimit)/2].data > to_find){
        return Binary_search(to_find, v, (ulimit+llimit)/2, llimit);
    }
    return Binary_search(to_find, v, ulimit, (ulimit+llimit)/2);
}
class LinkedList{
    private:
        int numnodes;
        Node head;
        std::vector<Node> nodes;
    public:
        LinkedList(){
            numnodes = 0;
            nodes = {head};
        }
        LinkedList(int arr[], int n){
            numnodes = n;
            mergesort(arr, n);
            nodes = {head};
            for(int i = 0; i<n; ++i){
                Node to_push;
                to_push.data = arr[i];
                nodes.push_back(to_push);
                nodes[i].next = &nodes[i+1];
            }
            nodes[n].next = NULL;
        }
        Node* getHead(){
            return nodes[0].next;
        }
        Node getElement(int i){
            return nodes[i+1];
        }
        void print(){
            for(int i = 1; i<=numnodes; ++i){
                std::cout << nodes[i].data << ((i==numnodes)? "":" ");
            }
            std::cout << std::endl;
            return;
        }
        int length(){
            return numnodes;
        }
        bool find(int val){
            return Binary_search(val, nodes, numnodes+1, 1);
        }
        void insert(int val){
            if(find(val)){return;}
            int to_insert;
            for(to_insert = 1; to_insert<=numnodes; ++to_insert){
                if(nodes[to_insert].data > val){break;}
            }
            if(to_insert == (1+numnodes)){
                Node toInsert = {val, NULL};
                nodes.push_back(toInsert);
                nodes[numnodes].next = &nodes[numnodes+1];
                ++numnodes;
                return;
            }
            Node toInsert = {val, &nodes[to_insert]};
            nodes.insert(nodes.begin()+to_insert, toInsert);
            nodes[to_insert - 1].next = &nodes[to_insert];
            ++numnodes;
            return;
        }
        void merge(LinkedList &list){
            for(int i = 0; i<list.length(); ++i){
                insert(list.getElement(i).data);
            }
            return;
        }
        void delete_node(int val){
            if(!find(val)){return;}
            for(int i = 1; i<=numnodes; ++i){
                if(nodes[i].data==val){
                    nodes[i-1].next = nodes[i].next;
                    nodes.erase(nodes.begin()+i);
                    --numnodes;
                    return;
                }
            }
            return;
        }
};

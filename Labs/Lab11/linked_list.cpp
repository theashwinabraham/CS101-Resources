#include <iostream>
#include "linked_list.h"
using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    int arr1[n], arr2[m], queries[q];
    
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    for(int i=0; i<q; i++){
        cin >> queries[i];
    }

    int insert_val;
    cin >> insert_val;

    int delete_val;
    cin >>  delete_val;

    LinkedList l1;
    LinkedList l2;

    for(int i = 0; i < n; i++){
        l1.insert(arr1[i]);
    }

    for(int i = 0; i < m; i++){
        l2.insert(arr2[i]);
    }


    Node *h1 = l1.getHead();
    Node *h2 = l2.getHead();

    cout << "List1: ";
    l1.print();
    cout << "List2: ";
    l2.print();


    cout << "Len of List1: " << l1.length() << endl;
    cout << "Len of List2: " << l2.length() << endl;

    for(int i=0; i<q; i++){
        int to_find = queries[i];
        cout << "List1 contains " << to_find << ": " << l1.find(to_find) << endl;
        cout << "List2 contains " << to_find << ": " << l2.find(to_find) << endl;
    }


    l1.insert(insert_val);
    cout << "List1 after insert: ";
    l1.print();

    l1.merge(l2);
    cout << "List1 after merge: ";
    l1.print();
    

    l1.delete_node(delete_val);
    cout << "List1 after delete: ";
    l1.print();
}
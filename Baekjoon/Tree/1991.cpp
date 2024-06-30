#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct Node{
    string my_name;
    string left;
    string right;
};

vector<Node> v;
map<string, int> m;

string first_str = "";
string second_str = "";
string third_str = "";

void first(Node curr){
    first_str += curr.my_name;

    if (curr.left != "."){
        string left = curr.left;
        int index = m[left];
        first(v[index]);
    }
    
    if (curr.right != "."){
        string right = curr.right;
        int index = m[right];
        first(v[index]);
    }
}

void second(Node curr){
    if (curr.left != "."){
        string left = curr.left;
        int index = m[left];
        second(v[index]);
    }

    second_str += curr.my_name;

    if (curr.right != "."){
        string right = curr.right;
        int index = m[right];
        second(v[index]);
    }
}

void third(Node curr){
    if (curr.left != "."){
        string left = curr.left;
        int index = m[left];
        third(v[index]);
    }

    if (curr.right != "."){
        string right = curr.right;
        int index = m[right];
        third(v[index]);
    }

    third_str += curr.my_name;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int no_of_nodes;
    cin >> no_of_nodes;

    for (int i = 0; i < no_of_nodes; i++){
        string my_name, left, right;
        cin >> my_name >> left >> right;
        Node n;
        n.my_name = my_name;
        n.left = left;
        n.right = right;
        v.push_back(n);
        m[my_name] = i;
    }

    int index_of_A = m["A"];
    Node A = v[index_of_A];
    first(A);
    second(A);
    third(A);

    cout << first_str << "\n";
    cout << second_str << "\n";
    cout << third_str << "\n";

    return 0;
}

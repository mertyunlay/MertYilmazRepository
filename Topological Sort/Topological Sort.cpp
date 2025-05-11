#include <iostream>            
#include <vector>             
#include <stack>                
#include <unordered_map>        
#include <set>                 
#include <string>    

using namespace std;      

// DFS fonksiyonu: Derinlik öncelikli arama yaparak, topolojik sıralama için düğümleri yığına ekler
void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, stack<int>& st) {
    visited[node] = true;  // Şu anki düğümü ziyaret ettik olarak işaretle
    for (int neighbor : adj[node]) {
        // Eğer komşu düğüm daha önce ziyaret edilmemişse, rekürsif olarak DFS çağır
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);  // Tüm komşuları ziyaret ettikten sonra bu düğümü yığına ekle
}

int main() {
    unordered_map<int, vector<int>> adj;
    set<int> nodes;                       
    string input;                          
    int edgeCount = 1;                     

    cout << "Topolojik siralama icin kenarlari girin (ornek: 2 3)\n";  
    cout << "Girisi bitirmek icin 'bitir' yazin.\n";                   
    while (true) {
        cout << edgeCount << ". kenari girin: ";
        cin >> input;
        if (input == "bitir") break;

        int u = stoi(input);  // Stringi integer tipine dönüştürür
        int v;
        cin >> v;

        adj[u].push_back(v);  // u düğümünden v düğümüne bir yönlü kenar ekle
        nodes.insert(u);  // u düğümünü düğümler kümesine ekle
        nodes.insert(v);  // v düğümünü düğümler kümesine ekle
        edgeCount++;
    }

    unordered_map<int, bool> visited;  // Hangi düğümlerin ziyaret edildiğini saklamak için bir map
    // Tüm düğümleri ziyaret edilmemiş olarak işaretle
    for (int node : nodes) {
        visited[node] = false;
    }

    stack<int> st;
    // Her düğüm üzerinde DFS çağrısı yap
    for (int node : nodes) {
        if (!visited[node]) {  // Eğer düğüm henüz ziyaret edilmediyse
            dfs(node, adj, visited, st);  // DFS ile bu düğümü ve onun komşularını işle
        }
    }

    // Yığındaki düğümleri çıkararak topolojik sıralamayı yazdır
    cout << "Topolojik Siralama: ";
    while (!st.empty()) {  // Yığın boşalana kadar
        cout << st.top() << " ";  // Yığının tepe elemanını yazdır
        st.pop();  // Tepe elemanı çıkar
    }
    cout << endl;

    return 0;
}

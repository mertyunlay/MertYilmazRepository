#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// DFS (Derinlik Öncelikli Arama) ile Topolojik Sıralama için yardımcı fonksiyon
void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, stack<int>& st) {
    visited[node] = true;

    // Bu düğüme komşu olan tüm düğümleri dolaş
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    // Tüm komşuları ziyaret ettikten sonra bu düğümü yığına ekle
    st.push(node);
}

// BFS (Kahn’s Algorithm) ile Topolojik Sıralama
void kahnTopologicalSort(unordered_map<int, vector<int>>& adj, set<int>& nodes) {
    unordered_map<int, int> in_degree; // Her düğümün giriş derecesini tut

    // Başlangıçta tüm düğümlerin giriş derecesi sıfır olarak ayarlanır
    for (int node : nodes) {
        in_degree[node] = 0;
    }

    // Giriş derecelerini hesapla
    for (auto& pair : adj) {
        for (int neighbor : pair.second) {
            in_degree[neighbor]++;
        }
    }

    queue<int> q;
    // Giriş derecesi 0 olan düğümleri kuyruğa ekle
    for (int node : nodes) {
        if (in_degree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> result; // Topolojik sıralama sonucu

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        // Bu düğümden çıkan tüm kenarları işleyerek komşuların giriş derecesini azalt
        for (int neighbor : adj[current]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Eğer sıralanan düğüm sayısı, toplam düğüm sayısına eşit değilse, graf döngü içeriyordur
    if (result.size() != nodes.size()) {
        cout << "HATA: Graf dongu (cycle) iceriyor, topolojik siralama yapilamaz.\n";
        return;
    }

    // Sıralamayı yazdır
    cout << "Topolojik Siralama (BFS - Kahn): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    unordered_map<int, vector<int>> adj; // Komşuluk listesi
    set<int> nodes;                      // Tüm düğümleri saklayan küme
    string line;
    int edgeCount = 1;

    // Kullanıcıdan kenar girişleri alınıyor
    cout << "Topolojik siralama icin kenarlari girin (ornek: 2 3)\n";
    cout << "Girisi bitirmek icin 'bitir' yazin.\n";

    while (true) {
        cout << edgeCount << ". kenari girin: ";
        getline(cin, line);

        if (line == "bitir") break;

        stringstream ss(line);
        int u, v;

        if (!(ss >> u >> v)) {
            cout << "Hatalı format. Ornek giris: 2 3\n";
            continue;
        }

        // Kenarı ekle
        adj[u].push_back(v);
        nodes.insert(u);
        nodes.insert(v);
        edgeCount++;
    }

    // DFS ile Topolojik Sıralama
    unordered_map<int, bool> visited;
    for (int node : nodes)
        visited[node] = false;

    stack<int> st;

    for (int node : nodes) {
        if (!visited[node]) {
            dfs(node, adj, visited, st);
        }
    }

    cout << "Topolojik Siralama (DFS): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    // Kahn (BFS) algoritmasını çalıştır
    kahnTopologicalSort(adj, nodes);

    return 0;
}

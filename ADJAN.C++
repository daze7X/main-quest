#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graf {
    unordered_map<char, list<char>> daftarAdj;

public:
    // Fungsi untuk menambahkan sisi ke graf
    void tambahSisi(char u, char v) {
        daftarAdj[u].push_back(v);
        daftarAdj[v].push_back(u); // Karena graf tidak terarah
    }

    // Fungsi untuk menampilkan graf dengan akar tertentu
    void tampilkanDenganAkar(char akar) {
        unordered_map<char, bool> visited;
        queue<char> q;

        q.push(akar);
        visited[akar] = true;

        while (!q.empty()) {
            char node = q.front();
            q.pop();

            cout << node << " -> ";
            bool adaTetangga = false;

            for (char tetangga : daftarAdj[node]) {
                if (!visited[tetangga]) {
                    q.push(tetangga);
                    visited[tetangga] = true;
                    adaTetangga = true;
                }
                cout << tetangga << " ";
            }

            if (!adaTetangga) {
                cout << "Tidak ada tetangga ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graf g;

    // Menambahkan sisi berdasarkan nama "pangestu"
    g.tambahSisi('p', 'a');
    g.tambahSisi('a', 'n');
    g.tambahSisi('n', 'g');
    g.tambahSisi('g', 'e');
    g.tambahSisi('e', 's');
    g.tambahSisi('s', 't');
    g.tambahSisi('t', 'u');

    // Tampilkan graf dengan 'p' sebagai akar
    g.tampilkanDenganAkar('p');

    return 0;
}

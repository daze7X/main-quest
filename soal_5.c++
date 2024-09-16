#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Fungsi untuk mencari indeks pertama kali elemen ditemukan dalam array integer
int cariElemen(const vector<int>& arr, int elemen) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == elemen) {
            return i;
        }
    }
    return -1; // Mengembalikan -1 kalo elemen tidak ditemukan
}

// Fungsi  mencari nilai terkecil dalam array integer
int nilaiTerkecil(const vector<int>& arr) {
    int minNilai = INT_MAX;
    for (int elemen : arr) {
        if (elemen < minNilai) {
            minNilai = elemen;
        }
    }
    return minNilai;
}

// Fungsi untuk mencari elemen terbesar ke-2 dalam array integer
int elemenTerbesarKedua(const vector<int>& arr) {
    int maxElemen = INT_MIN;
    int maxElemenKedua = INT_MIN;
    for (int elemen : arr) {
        if (elemen > maxElemen) {
            maxElemenKedua = maxElemen;
            maxElemen = elemen;
        } else if (elemen > maxElemenKedua && elemen < maxElemen) {
            maxElemenKedua = elemen;
        }
    }
    return maxElemenKedua;
}

int main() {
    vector<int> arr = {5, 8, 2, 10, 3, 8};

    // Cari indeks pertama kali elemen 10 ditemukan
    int indeks = cariElemen(arr, 10);
    if (indeks != -1) {
        cout << "Elemen 10 ditemukan pada indeks: " << indeks << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    // mencari nilai terkecil dalam array
    int minNilai = nilaiTerkecil(arr);
    cout << "Nilai terkecil dalam array: " << minNilai << endl;

    // Cari elemen terbesar kedua dalam array
    int maxElemenKedua = elemenTerbesarKedua(arr);
    cout << "Elemen terbesar kedua dalam array: " << maxElemenKedua << endl;

    return 0;
}

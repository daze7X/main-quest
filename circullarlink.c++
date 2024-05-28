#include <iostream>
using namespace std;

struct Mahasiswa {
    string npm, nama, jurusan;
    Mahasiswa* next;
};

Mahasiswa* head, * tail, * newNode, * cur, * del;

void createCircularSingleLinkedList(string dataBaru[]) {
    head = new Mahasiswa();
    head->npm = dataBaru[0];
    head->nama = dataBaru[1];
    head->jurusan = dataBaru[2];
    tail = head;
    tail->next = head;
}
//tambah node baru di awalan node sebelumnya jadi ke-2
void addFirst(string data[]) {
    newNode = new Mahasiswa;
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}
//tambah node baru tapi diakhir
void addlast(string data[]) {
    newNode = new Mahasiswa;
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}
//menghapus node pertama
void removefirst(){
    del = head;
    head = head->next;
    tail->next= head;
    delete del;
}
//menghapus node diakhir
void removelast(){
    del = tail;
    cur = head;
    while (cur->next !=tail)
    {
        cur=cur->next;
    }
    tail = cur;
    tail->next=head;
    delete del;
    
}
//mencetak circular
void printCircular() {
    cout << "\t\t\tData Mahasiswa" << endl;
    cout << "-----------------------------------------------------------------\n";
    cout << "| NPM\t\t|\t Nama\t\t\t|\tJurusan\t|" << endl;
    cout << "-----------------------------------------------------------------\n";
    cur = head;
    do {
        cout << "| " << cur->npm << "\t| " << cur->nama << "\t\t\t| " << cur->jurusan << "\t\t|" << endl;
        cur = cur->next;
    } while (cur != head);
}

int main() {
    string dataBaru[3] = { "7326171841", "Pangestu Aji Nugroho", "Teknik Informatika" };
    createCircularSingleLinkedList(dataBaru);
    printCircular();

    string data[3] = { "7326171855", "Alexandro Mcfly", "Teknik Informatika" };
    addFirst(data);
    printCircular();

    string data2[3] = { "7326171835", "mac wazowsky", "Teknik Informatika" };
    addlast(data2);
    printCircular();

    removefirst();
    printCircular();

    removelast();
    printCircular();

}
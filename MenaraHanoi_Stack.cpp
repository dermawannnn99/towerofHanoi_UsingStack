#include <iostream>    
#include <string>     
#include <vector>       
using namespace std;

//struct node
struct Node {
    int data;       
    Node* next;       
};

//struct stack dengan linkedlist
struct Stack {
    Node* top;          
    string nama;       

    //konstruktor stack: nama diset dari parameter, top diset ke null
    Stack(string n) : top(nullptr), nama(n) {}

    //func menambahkan batu keatas stack
    void push(int nilai) {
        Node* baru = new Node{nilai, top};  
        top = baru;                      
    }

    //func utk menghapus dan mengembalikan elemen paling atas dari stack
    int pop() {
        if (top == nullptr) return -1;    
        Node* hapus = top; //simpan pointer ke elemen yg akn dihapus              
        top = top->next;                   
        int nilai = hapus->data;       
        delete hapus;                      
        return nilai;                      
    }

    //mwngembalikan isi stack dalam bentuk vector<int>, dari atas ke bawah
    vector<int> getIsi() const {
        vector<int> isi;                
        Node* current = top;               
        while (current) { //selama belum mencapai akhir stack
            isi.push_back(current->data); //tambahkan data ke vector
            current = current->next; //pindah ke node berikutnya (di bawahnya)
        }
        return isi;
    }
};

//func untuk mencetak isi dari sebuah vector (utk menampilkan isi stack)
void cetakIsi(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];               
        if (i < v.size() - 1) {
            cout << " "; //tambahkan spasi jika belum elemen terakhir
        }
    }
}

//func untuk menampilkan isi ketiga menara (A, B, C)
void tampilkan(Stack* A, Stack* B, Stack* C) {
    cout << "A: "; cetakIsi(A->getIsi()); cout << endl;  
    cout << "B: "; cetakIsi(B->getIsi()); cout << endl; 
    cout << "C: "; cetakIsi(C->getIsi()); cout << "\n" << endl; 
}

//func rekursif
void hanoi(int jumlah, Stack* asal, Stack* bantu, Stack* tujuan, Stack* A, Stack* B, Stack* C) {
    if (jumlah == 1) {
        int batu = asal->pop(); //ambil satu batu dari atack awal
        tujuan->push(batu); //pindahkan ke stack tujuan (dgn dipush)
        cout << "Pindahkan batu " << batu << " dari " << asal->nama << " ke " << tujuan->nama << endl;
        tampilkan(A, B, C); //tampilakan kondisi
        return;
    }

    //rekursi pertama: pindahkan n-1 batu ke menara bantu
    hanoi(jumlah - 1, asal, tujuan, bantu, A, B, C);

    //pindahkan 1 batu yang tersisa dari asal ke tujuan
    int batu = asal->pop();  
    tujuan->push(batu);      
    cout << "Pindahkan batu " << batu << " dari " << asal->nama << " ke " << tujuan->nama << endl;
    tampilkan(A, B, C);                           

    //rekursi kedua: pindahkan n-1 batu dari bantu ke tujuan
    hanoi(jumlah - 1, bantu, asal, tujuan, A, B, C);
}

int main() {
    Stack menara_A("A"), menara_B("B"), menara_C("C"); 
  
    menara_A.push(30); 
    menara_A.push(20);
    menara_A.push(10);

    //cetak kondisi awal sebelum di pindahkan
    cout << "---------------------------" << endl;
    cout << "|      KONDISI AWAL       |" << endl;
    cout << "---------------------------" << endl;
    tampilkan(&menara_A, &menara_B, &menara_C); 

    //panggill func hanoi untuk memindahkan 3 batu dari A ke C
    hanoi(3, &menara_A, &menara_B, &menara_C, &menara_A, &menara_B, &menara_C);

    //cetak kondisi akhir setelah di pindahkan
    cout << "---------------------------" << endl;
    cout << "|      KONDISI AKHIR       |" << endl;
    cout << "---------------------------" << endl;
    tampilkan(&menara_A, &menara_B, &menara_C);

    cout << "Terima Kasih :)" << endl << endl << endl;
    return 0;  // Program selesai
}

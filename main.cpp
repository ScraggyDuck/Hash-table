#include <iostream>
#define M 100
using namespace std;

int hashFunction(int key){
	return key % M;
}

struct Data
{
	int key;
	int value;
};

struct Node {
	Data info;
	Node *next;
};

struct List {
	Node *pHead;
	Node *pTail;
};

void init(List &l) {
	l.pHead = l.pTail = NULL;
}

bool isEmpty(List l) {
	if (l.pHead == NULL)
        return true;
	return false;
}

Node *creatNode(int key, int value) {
	Node *p = new Node;
	p->info.key = key;
	p->info.value = value;
	p->next = NULL;
	return p;
}

void Push(List &l, int key, int value){
	Node *p = creatNode(key, value);
	if (isEmpty(l) == true)
        l.pHead = l.pTail = p;
	else {
		p->next = l.pHead;
		l.pHead = p;
	}
}

bool search(List l, int key, int value) {
	if (isEmpty(l) == false)
		for (Node* p = l.pHead; p != NULL; p = p->next)
			if(p->info.key == key && p->info.value == value)
				return true;
	return false;
}

void deleteX(List &l, int key, int value){
	Node *q = new Node;
	if(isEmpty(l) == false){
		if (l.pHead->info.key == key && l.pHead->info.value == value){
			q = l.pHead;
			if (l.pHead == l.pTail)
                l.pHead = l.pTail = NULL;
            else
                l.pHead = l.pHead->next;
			delete q;
			return;
		}
		for (Node *p = l.pHead; p != NULL; p = p->next){
			if (p->info.key == key && p->info.value == value){
				if (p == l.pTail){
					l.pTail = q;
					delete p;
					return;
				}
				q->next = p->next;
				delete p;
			}
			q = p;
		}
	}
	return;
}

int main(){
	int key, value;
	List HASHTABLE[M];
	//Init Hash Table
	for (int i = 0; i < M; i++)
		init(HASHTABLE[i]);
	while (true){
		system("cls");
		cout << "=====================HASH TABLE=====================";
		cout << "\n1.Them gia tri ";
		cout << "\n2.Tim kiem";
		cout << "\n3.Xoa";
		cout << "\n0.Thoat";
		cout << "\n====================================================\n";
		int lc;
		cout << "Nhap lua chon ";
		cin >> lc;
		switch(lc){
            case 1:
                cout << "Nhap lan luot key va value: ";
                cin >> key >> value;
                Push(HASHTABLE[hashFunction(key)], key, value);
                break;
            case 2:
                cout << "Nhap lan luot key va value can tim: ";
                cin >> key >> value;
                if (search(HASHTABLE[hashFunction(key)], key, value) == true)
                    cout << "Tim thay!" << endl;
                else
                    cout << "Khong tim thay!" << endl;
                system("pause");
                break;
            case 3:
                cout << "Nhap lan luot key va value can xoa: ";
                cin >> key >> value;
                deleteX(HASHTABLE[hashFunction(key)], key, value);
                break;
            case 0:
                break;
        }
    }
    return 0;
}



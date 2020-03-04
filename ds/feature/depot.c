// depot.c ���a�ӤH�ܮw
// �D�n�ΨӦs���j�ƨ��b
// Ver 1.0 -Tmr 2007/04/29

// �̦h
#define MAX_DEPOT 200
#include <ansi.h>
#include <dbase.h>

string *items = ({});

//////////////////////////////////////////////////////////////////
int getDepotSize() {
        return sizeof(items);
}

string* getAllDepotItems() {
        return items;
}

void depotItem(string path) {
        items += ({path});
}

string getDepotItem(int idx) {
        return items[idx];
}

void deleteDepotItem(int idx) {
        // �[�W�B�~�r��A�~��y�X�ߤ@id
        items[idx] += "DELETED";        
        items -= ({ items[idx] });
}

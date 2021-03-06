// depot.c 玩家個人倉庫
// 主要用來存取強化卷軸
// Ver 1.0 -Tmr 2007/04/29

// 最多
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
        // 加上額外字串，才能造出唯一id
        items[idx] += "DELETED";        
        items -= ({ items[idx] });
}

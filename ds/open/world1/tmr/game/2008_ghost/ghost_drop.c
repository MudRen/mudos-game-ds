#include <ansi.h>

int isDrop(int lv) {
        return random(100) < 50 + lv;
}

void createStock(object corpse, int lv) {
        string file;
        if( random(100)<30 ) {
                switch(random(3)) {
                        case 0: file = "stock3.c"; break;
                        case 1: file = "stock4.c"; break;
                        case 2: file = "stock5.c"; break;
                }
        } else  {
                switch(random(3)) {
                        case 0: file = "stock2.c"; break;
                                default: file = "stock1.c"; break;
                }
        }
        
        new("/open/world1/tmr/game/2008_ghost/" + file )->move(corpse);
        
        if( random(100)==1 ) {
           // 1%  �����v�����A���P
           new("/open/world1/tmr/game/2008_ghost/extra1" )->move(corpse);
        } 
        if( random(100)==1 ) {
           // 1%  �����v��������
           new("/open/world1/tmr/game/2008_ghost/stock6" )->move(corpse);
        } 
}

void createXiang(object corpse, int lv) {
        string file;
                if( random(100)<30 ) {
                        file = "xiang3.c";
        } else  {
                switch(random(3)) {
                        case 0: file = "xiang2.c"; break;
                                default: file = "xiang1.c"; break;
                }
        }
        
        new("/open/world1/tmr/game/2008_ghost/" + file )->move(corpse);
}


void create(object corpse, int lv) {
        if(!isDrop(lv)) return;         
        
        // ���~����e�q��
        createStock(corpse, lv);        // ���~
        if(lv>=30 && random(100) > 50)   // lv 30 �H�Wnpc �A�i�H�A�h���@��
              createStock(corpse, lv);  // ���~
        if(lv>=50 && random(100) > 50)   // lv 50 �H�Wnpc �A�i�H�A�h���@��
              createStock(corpse, lv);  // ���~
        if( lv>=45 && random(100) < 1 ) {
           // lv 45 �H�Wnpc ��1%����j������
           new("/open/world1/tmr/game/2008_ghost/boat2" )->move(corpse);
        } 

        if( random(100)<60 )
                createXiang(corpse, lv);        // ����
}


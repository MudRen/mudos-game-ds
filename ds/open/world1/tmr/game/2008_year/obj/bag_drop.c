#include <ansi.h>

int isDrop(int happiness, int lv) {
        // �������v
        int rang;
        // �ﺡ�M�ˡA�i�H�h20%�����v
        rang = lv*lv + happiness*5;

        return rang > random(4000);
}
object createBag(int happiness, int lv) {
        int rang, bonus;
        int r5, r4, r3, r2;
        string file;
                if( random(100)==1 ) {
                // 1%  �����v������U
            file = "bad_bag.c";
        } 
        else if( happiness > random(1300) && lv >= 40 && random(100)==1 ) {
                // �S��ֳU
                 file = "bag6.c";
        } else  {
                bonus = lv*lv + happiness*10;

                r5 = 10 + bonus/4;
                r4 = 100 + r5 + bonus/2;
                r3 = 500 + r4 + bonus/2;
                r2 = 4000 + r3;
                rang = random(15000);
                
                if( rang < r5 ) {
                        file = "bag5.c";
                } else if( rang < r4 ) {
                        file = "bag4.c";
                } else if( rang < r3 ) { // 
                        file = "bag3.c";
                } else if( rang < r2 ) { 
                        file = "bag2.c";
                } else {
                        file = "bag1.c";
                }
        }
        
        return new("/open/world1/tmr/game/2008_year/obj/" + file );
}



#include <room.h>
inherit ROOM;
void create()
{
 set("short","副堂主寢室");
 set("long",@LONG
雖然向雲堂主平時是很平易近人, 但是就算是和副堂主
的寢室也是隔個兩個大廳的距離, 應該不難曉得堂主並不是
很外向. 副堂主房間的牆掛了張匾, 上面寫著「如雷貫耳」
四個大字, 但沒有寫是誰題的, 也沒有什麼特殊的修飾, 就
只有這四個陽春的金字, 不知道有什麼含意.
LONG
    );
 set("exits",([ "south":__DIR__"inroom40",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

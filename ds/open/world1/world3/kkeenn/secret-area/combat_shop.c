#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Combat Shop");
        set("long", @LONG
這裡就是未來世界(Future World)排名第三名的特殊道具店了！在網
路上有介紹過它，因為保有一些科學家費盡心思所想出來神奇法寶，所以
特別有名，這家店絕無分店，只有在者裡能買的到歐 。
[ [0;1;36m�[1m�[1m�[1mC[1m�[1m�[1m [0m]:         [0;1;31mL[1mi[1ms[1mt[0m,
[ [0;1;36m�[1mR[1m�[1mD[1m�[1m�[0m ]:          [0;1;31mB[1mu[1my[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec11.c",
     
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/item.c" :1,
]));

        setup();
        replace_program(ROOM);

}

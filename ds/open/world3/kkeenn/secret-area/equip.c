#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Equip Shop");
        set("long", @LONG
這裡就是未來世界(Future World)排名前五名的防具店了！有歷史的
見證 -這家店之所以能撐下去，定然有它的不凡之處，原來阿！正因為這
裡是歷史古城，所以當年被列管為禁品的防具，這裡還保有一些呢！？
[ [0;1;36m�[1m�[1m�[1mC[1m�[1m�[0m ]:         [0;1;31mL[1mi[1ms[1mt[0m,
[ [0;1;36m�[1mR[1m�[1m�[1m�[1m�[0m ]:          [0;1;31mB[1mu[1my[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec9.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/equip.c"   :1,
]));

        setup();
        replace_program(ROOM);

}

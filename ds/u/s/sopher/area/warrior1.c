
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"超龍軍團第一分部"NOR);
        set ("long", @LONG
這裡就是第一分部了迎面而來的是兩位和藹可
親的衛兵，他們對你愉快的微笑著，你似乎也感受
到歡樂的氣氛！你仔細向裡面望了望，並沒有什麼
特殊發現，並沒有想像中那樣的軍容浩大。
LONG);  
        
        set("exits", ([
        "west": __DIR__"warrior2",
        "east": __DIR__"dragon9",
         ]) );
        set("objects", ([
        __DIR__"npc/guard" : 2,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG 
這裡似乎蠻安靜地，往右邊就沒有路了。但是一樣是有怪物
在跑來跑去，而且地面還持續搖晃著，讓人感覺十分不安，會不
會走到一半突然整個洞垮下來••
LONG
    );

       set("exits",([      
       "west":__DIR__"s7",   
       "south":__DIR__"s14",             ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}


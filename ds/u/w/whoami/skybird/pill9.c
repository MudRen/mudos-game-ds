#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"寢房"NOR);

set("long",@LONG
這裡是掌門人和教主夫人的寢房, 你發現這裡和正廳一樣, 
都是以青石砌牆, 可是這裡卻多了一些溫馨的氣息, 想來是因
為這裡也住著教主夫人吧?
LONG
    );
 set("exits",([ "south":__DIR__"pill7",
    ]));
set("objects", ([__DIR__"npc/master_walf" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}

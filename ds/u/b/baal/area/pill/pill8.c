#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
從這裡往南走可以到天梟針灸一派的針灸室, 往北則可以
回到大廳的中央部份, 不過這裡依然可以見到那根大大的柱子, 
一股燒焦味瀰漫在空中, 不過這股令人作嘔的味道仍阻止不了
你的好奇心...
LONG
    );
 set("exits",([ "northwest":__DIR__"pill6",
                "northeast":__DIR__"pill12",
                "south":__DIR__"pill10",
    ]));
 set("item_desc",([
        "柱子" : "一根大大的柱子\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}

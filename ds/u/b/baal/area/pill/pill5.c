#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡一樣是隨著柱子而建築的, 但是你發現這根柱子其實
並沒有支撐天花板的作用, 因為那上面似乎有著可以容下一個
人的空隙, 不知道上面是不是有什麼.....
LONG
    );
 set("exits",([ "south":__DIR__"pill4",
                "northeast":__DIR__"pill7",
    ]));
 set("item_desc",([
        "柱子":"一根大大的柱子, 從這個角度看不出有什麼異常.\n"
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}

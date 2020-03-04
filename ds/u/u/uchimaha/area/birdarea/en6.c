#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你現在來到東北澤林的深處, 四周一片陰暗, 空氣
中有一股溼溼的感覺, 令人十分的不舒服, 你望了望四
周, 樹木多到數不清, 你隱隱約約的看到這條路往東北
方延伸下去。
LONG
    );
 
 set("exits",(["west":__DIR__"en5",
               "south":__DIR__"en4",
               "northeast":__DIR__"en7",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           

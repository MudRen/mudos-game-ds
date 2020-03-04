#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟教"NOR"大堂");

 set("long",@LONG 
你現在進入大堂, 你看了看四周, 只見左右各有一排的天梟
石像, 每一個石像都是不同的動作, 而且栩栩如生, 你不由的讚
嘆起來, 北邊和南邊都是給信徒住的客房, 而東邊通往走廊。
LONG
    );
 
 set("exits",(["east":__DIR__"bird18",
               "west":__DIR__"bird14",
               "south":__DIR__"bird16",
               "north":__DIR__"bird17",
     ]));
 
 set("no_clean_up", 0);
 setup();
 set("light",1);
 replace_program(ROOM);
}           


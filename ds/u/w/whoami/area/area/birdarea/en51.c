#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
你帶著不安情緒往前走了數十步, 沼氣幾乎已經讓你失去了
前面的視線, 同時也發現地上有些許泥土. 在這裡你看到一個非
常殘破的告示牌, 也許是經過此地的探險家所立的.
LONG);
 set("item_desc",([
        "告示牌":"再往裡面走就是東北澤林的黑暗地帶了。\n",
     ]));
 set("exits",(["east":__DIR__"en50",
               "south":__DIR__"en53",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        


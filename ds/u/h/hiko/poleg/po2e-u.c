#include <room.h>
inherit ROOM;

void create()
{
        set("short", "廚房");
        set("long", @LONG
這裡海產店內部的一個專門給人自製料理的廚房，外面不時一些談
話的聲音，這裡面還算乾淨，至少不會過於骯髒，前方的火爐看起來十
分特殊，也讓人感覺有點興奮，可以自己動手作料理了，不過似乎有點
悶熱，看來火爐溫度極高，想必不是凡品。
LONG
        );
set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"po2e",
]));
        set("objects",([
  __DIR__"npc/item/fire-furnace":1,
]));
        set("item_desc",([
  "木材" : "一堆被火正燃燒著的木材，還劈劈啪啪的在響。\n",
]));
        set("light", 1);
        set("no_clean_up", 0);
        set("no_recall","吃飯皇帝大，神也無法擋....");        
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="down" )return ::valid_leave(me, dir);

        if( dir=="down" && me->query_temp("cook") >= 1)
         me->add_temp("cook",-1);
        return ::valid_leave(me, dir);
}




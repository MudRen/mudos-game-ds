#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中茅廬");
set("long",@LONG
你來到茅廬中的其中一間房間，這裡看來似乎是屬於孩童
的房間，可以見到幾樣小童玩和一些孩子用的器具，想來該是
這家人的孩童住的地方。
LONG
    );
 set("exits",([
"east":__DIR__"yu_home",
]));
 set("item_desc", ([
  "童玩" : "用木頭和一些繩子製成，是孩童愛玩的小玩藝。\n",
 ])); set("no_clean_up",0);
 set("light",1);
 setup();
}             





#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中茅廬");
set("long",@LONG
這裡是在深山中得一間簡樸茅廬，你剛踏進來便覺得佈置
極為簡單，而且一切的東西都是自然取得的，可想而知這裡的
人不經常和外界交流，牆面上放著一些捕獸的器具，地上也有
些獸皮等等的。
LONG
    );
 set("exits",([
"east":__DIR__"home_1",
"north" : __DIR__"home_3",
"west" : __DIR__"home_2",
"out" : __DIR__"mu13",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             





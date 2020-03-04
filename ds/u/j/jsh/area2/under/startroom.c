#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
這裡是古墓的地下密室，說陰森又有點乾燥，在這裡無任何光源
，伸手不見五指，遠看近看都找不到一個人，只聽到蟲獸的廝廝叫聲
，往前面好像還有路，往上是回到古墓的大廳。

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room1", 
  //"down" : __DIR__"shiro-door",
  "out" : "/open/world1/moonhide/area/room4",
])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


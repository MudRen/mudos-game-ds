// Room: /u/l/luky/room/pearl_33.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIY"天道道場"NOR);
set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
);
set("exits", ([ /* sizeof() == 1 */
 "east" : __DIR__"pearl_10",
]));
set("no_clean_up", 0);
set("light",1);
setup();
create_door("east","紅色大門","west",DOOR_LOCKED,"red_key");
}

// Room: /u/l/luky/room/pearl_33.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIY"�ѹD�D��"NOR);
set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
);
set("exits", ([ /* sizeof() == 1 */
 "east" : __DIR__"pearl_10",
]));
set("no_clean_up", 0);
set("light",1);
setup();
create_door("east","����j��","west",DOOR_LOCKED,"red_key");
}

// This is a room made by roommaker.
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
一條由青石所鋪成的街道，這裡的人煙稀少，街旁的房舍也都較為
破舊。東邊有一間茅草編成的房舍，其門前堆放了一堆稻草，大概是農
家正在收割曬穀吧。
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road10",
  "east" : __DIR__"road14",
]));
	create_door("east", "木門", "west", DOOR_CLOSED);
	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

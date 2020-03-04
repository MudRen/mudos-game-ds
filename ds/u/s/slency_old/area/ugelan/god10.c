// Room: /u/s/slency/area/ugelan/god10.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "房間");
	set("long", @LONG
這間房間裡的佈置相當樸素, 一洗教堂豔麗的氣息, 牆上掛了許多
耶穌基督的畫像, 雖然是處在一間裝飾簡單的房間裡, 卻令人感覺到與
神更為接近了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"god9",
]));
	create_door("south", "木門", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}

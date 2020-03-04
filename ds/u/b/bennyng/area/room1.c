// Room: /u/b/bennyng/area/room1.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "教皇臥室");
	set("long", @LONG
一進來，你就被教皇強大的力量嚇到。當你心定來的時候，環顧四周
，發現這裡金光閃閃的擺設，整理得井井有條。而教皇就一個人坐在窗戶
的旁邊，若有所思的望向出面．．．．．．
LONG
	);
        set("light",1);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room2",
]));
        create_door("south","木門","north",DOOR_CLOSED);
        set("outdoors","land");
        set("objects", ([
  __DIR__"npc/Gemini.c":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

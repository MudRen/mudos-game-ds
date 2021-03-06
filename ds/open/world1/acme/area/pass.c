// Room: /u/a/acme/area/pass.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "山路");
	set("long", @LONG
這裡是位於天山的至高點，四周盡是山林，高聳穿雲，往北遙望可看
見瀑布，往南可通往天城。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pass1",
  "south" : __DIR__"ndoor",
  "southwest" : __DIR__"lea15",
]));
	set("no_clean_up", 0);
    set("no_map",1);
     set("outdoors","land");

	setup();
        create_door("south","北城門","north",DOOR_OPENED,"nokey");
}

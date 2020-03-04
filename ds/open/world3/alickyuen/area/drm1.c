// Room: /u/a/alickyuen/area/drm1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Door＠Secret"NOR);
	set("long", @LONG
進入了這裡後，你發現這裡非常暗，這條通道不知是通往那裡的。但
你隱約間看見一個守衛正在虎視眈眈的看著你。趕快逃命吧！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dpy2",
]));
            set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/protector.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

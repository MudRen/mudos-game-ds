#include <ansi.h>
#define BBLU ESC+"[44m"
inherit ROOM;
void create()
{
	set("short", "護城河");
	set("long",
NOR"\n"BBLU"　　　　　　　　　　　　　　　　　　　　　　　　　　 　　　"NOR"\n"NOR
BBLU""HIW"　　　﹏\﹏\﹏\﹏\﹏\﹏\　　　﹋﹋﹋﹋﹋　　　　　　　　 　　　　"NOR"\n"
BBLU""HIW"　　　﹋﹋﹋﹋﹋﹋﹏\ ﹏\ ﹏\　﹏\ ﹏\　　　　　　　　　　　　　"NOR"\n"
BBLU""HIW"﹏\  ﹏\ 　　　　　　﹋﹋﹋﹋　﹋﹋﹋　　　　　　　　　　　　"NOR"\n"
BBLU""HIW"﹋﹋﹋﹋　　　　﹏\﹏\﹏\﹏\﹏\　　　　　　　﹏\﹏\﹏\ 　　　　　　"NOR"\n"
BBLU""HIW"　　　　　　　　﹋﹋﹋﹋﹋　　　　　　　﹋﹋﹋　　　　　 　"NOR"\n"NOR"\n"
NOR""
"這裡是步靈城西邊外護城河，在這裡有許\多小動物。\n"
	);
	set("exits", ([
  "south" : __DIR__"river7.c",
  "north" : __DIR__"river5.c",
  "enter"  : __DIR__"bdoor3.c",
  "west"  : __DIR__"fgo.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "往某個地方的路上");
    set("long",HIG"你現正騎在馬上面騎往你所要的地方！！！\n"NOR);
	set("outdoors","land");
	set("no_clean_up", 0);
	set("light",1);
	setup();
}

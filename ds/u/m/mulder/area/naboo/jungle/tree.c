#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"樹頂"NOR);
	set("long", @LONG
這是棵神秘大樹的頂部，由這兒望出去，可以一覽整個森林。這兒有
一個神秘的年青人不知為何事已煩惱。
LONG);
	setup();
	replace_program(ROOM);
}

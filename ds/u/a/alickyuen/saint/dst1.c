#include <ansi.h>
//updated 26/12
inherit ROOM;
void create()
{
	set("short", HIC"ST�CRoad�ISouth"NOR);
	set("long", @LONG
�����Q�⪺�m�O�A�v�g�ۧA���e���@�y�j�����T�ֳ��ҡС�DPY�A��
�O�{�ɦ~���H���񰲨쪺�����a�I�A���OSaint�̳̦���y�P���a��A�O
�A�����T�Q�i�h�ݬݡC
LONG
	);
 set("exits",([ 
"north":__DIR__"dst2.c",
"in":__DIR__"dpy1.c",
"south":__DIR__"dst4.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

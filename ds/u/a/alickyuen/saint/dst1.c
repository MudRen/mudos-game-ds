#include <ansi.h>
//updated 26/12
inherit ROOM;
void create()
{
	set("short", HIC"ST。Road＠South"NOR);
	set("long", @LONG
五光十色的彩燈，影射著你眼前的一座大型的娛樂場所－－DPY，都
是現時年輕人的放假到的熱門地點，都是Saint裡最有潮流感的地方，令
你都不禁想進去看看。
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

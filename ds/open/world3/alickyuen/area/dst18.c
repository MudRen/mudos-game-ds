#include <ansi.h>
//updated 28/12
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠Path"NOR);
	set("long", @LONG
這裡是一條熱鬧的街道，四周的人們擠得水洩不通，看來這裡像個市
場。在這裡往北可到本市的政府總部，但你隱約聽到那邊有很多人在大叫
大嚷，似乎是在請願了，過去可能有危險...往南可以回到你剛來的市中心。
LONG
);
 set("exits",([ 
"north":__DIR__"rd1.c",
"south":__DIR__"dst10.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	setup();
	replace_program(ROOM);
}

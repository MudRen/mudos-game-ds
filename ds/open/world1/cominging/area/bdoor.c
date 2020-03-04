#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "步靈城南門");
	set("long",
"\n"
"◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣\n"
"██　　██　　██　　██　　██　　██　　██　　██\n"
HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"███"HIC"※步靈城南門※"HIR"██"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"███▇"HIR"▇▇▇▇"HIW"▇▇██"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"████"HIW"　　　　"HIR"　███"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"████"HIR"　　　　"HIW"　███"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"████"HIW"　　　　"HIR"　███"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"████"HIR"　　　　"HIW"　███"HIR"████"HIW"████"HIR"██\n"
HIR"◥███"HIW"████"HIR"████"HIW"　　　　"HIR"　███"HIW"████"HIR"████"HIW"█◤\n\n"NOR
	);
	set("exits", ([
  "north" : __DIR__"bsouth4.c",
  "out" : __DIR__"river.c",
]));
	set("objects",([
  __DIR__"npc/gateguard.c": 3,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
        if( dir== "out" && !userp(me))
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me,dir);
}

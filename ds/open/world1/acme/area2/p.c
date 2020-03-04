// Room: /u/a/acme/area3/p.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "朱漆大門");
	set("long", @LONG
這裡是施家大宅，在門口上方有個巨大黑木匾，上頭寫著「施府」
，在朱漆大門的二側各站了二個家丁，在大宅四周種植著許多蒼松，濃
蔭參天。
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p2",
"out" : ACME_PAST"area/street4",
]));
     set("objects",([
        __DIR__"npc/guard" : 2,
     ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="out" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

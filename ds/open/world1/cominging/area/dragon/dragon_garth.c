#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"狂龍幫"HIM"－"HIY"中庭"NOR);
	set("long", @LONG
    你經過狂龍之門，踏著由青石鋪成的路慢慢走進去。
放眼望去，四周環境清幽，令人頓時感覺到自己置身於仙境之中。
你隱約聽潺潺之聲，原來狂龍幫山上有一道山澗流經這�堙A
澗水中的小魚不時躍上水面，替周圍寂靜的環境加上一下又一下的清脆水聲。
你慢慢的向前行，望著大廳前被巨大龍形雕刻圍繞著，刻有【狂龍】的牌扁。
而花崗石石門前有數名幫眾把守著。
LONG

	);
	set("exits",([
  "out" : __DIR__"dragon_door.c",
  "north" : __DIR__"dragon.c",
]));
        set("objects",([
                "/open/world1/npc/goldman.c" : 10,
        ]));
	set("item_desc",([

]));
	set("light",1);
set("no_goto",1);
	setup();
}

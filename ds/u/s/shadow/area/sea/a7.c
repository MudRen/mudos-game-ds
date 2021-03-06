/**
 * Shadow's area [湖底世界 - 湖底通道 - a7]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"湖底通道"NOR);
	set("long",@LONG
通道兩旁的石壁同樣燃燒著淡淡的青色火焰(fire)，牆上的複雜
壁畫同樣讓你摸不著頭緒。周圍的海水微微地震動著，似乎有巨大的
生物在此附近活動，青色的火焰也隨著水流的變化而顯得詭譎多變。
於是你催促著自己盡快游開這個鬼地方。
LONG
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a8",
		"south" : __DIR__"a5",
	]));
	set("item_desc", (["fire" : HIG"隨著水流強度變化大小的奇怪火焰...。\n"NOR]));

	setup();
	replace_program(ROOM);
}


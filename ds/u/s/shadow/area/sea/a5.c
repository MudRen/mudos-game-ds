/**
 * Shadow's area [湖底世界 - 湖底通道 - a5]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"湖底通道"NOR);
	set("long",@LONG
你進入了深藍幽暗的一條通道，通道的兩旁盡是石壁，石壁上燃
燒著淡淡的青色火焰(fire)，牆上還畫著一些複雜的壁畫，前方有一
點微弱的光線，再往前游去或許能找到出口也說不定，於是你催促著
自己盡快游開這個鬼地方。
LONG
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a6",
		"north" : __DIR__"a7",
		"leave" : __DIR__"a4",
	]));
	set("item_desc", (["fire" : HIG"隨著水流強度變化大小的奇怪火焰...。\n"NOR]));

	setup();
	replace_program(ROOM);
}


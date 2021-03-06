/**
 * Shadow's area [湖底世界 - 湖底監牢 - a11]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"湖底監牢"NOR);
	set("long",@LONG
天然的石壁，但是有人工刻鑿的痕跡。海水在此處異常地平靜，
似乎沒有任何外力可以干擾這兒..。漆黑的監牢內隨處可見監禁囚犯
用的刑具，各種奇形怪狀的囚具看得你膽戰心寒，心中一陣不安。
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a12",
		"south" : __DIR__"a9",
	]));

	setup();
	replace_program(ROOM);
}


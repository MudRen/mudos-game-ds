/**
 * Shadow's area [湖底世界 - 湖底監牢 - a9]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"湖底監牢"NOR);
	set("long",@LONG
天然的石壁，但是有人工刻鑿的痕跡。海水在此處異常地平靜，
似乎沒有任何外力可以干擾這兒..。這兒擺設著一張桌子以及三張椅
子，桌上還擺著尚未用完的新鮮食物，看來應是管理此湖底監牢的獄
守所有。
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"north" : __DIR__"a12",
		"west" : __DIR__"a9",
	]));

	setup();
	replace_program(ROOM);
}


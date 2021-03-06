/**
 * Shadow's area [湖底世界 - 淺灘 - a2]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"淺灘"NOR);
	set("long",@LONG
這裡的水位不深不淺，但也已到了腰際。這兒的魚蝦似乎都不怕
人，一群一群地圍繞在你的身邊，彷彿在歡迎你的到來。四周的湖水
依舊看不到邊際，遠處的水氣更泛漫成迷霧，讓你有如置身於仙境之
中，久久不能自己。
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits",([
		"west" : __DIR__"a1",
		"north" : __DIR__"a4",
	]));

	setup();
}

int room_effect(object me)
{
	switch(random(8))
	{ 
		case 1:
			message_vision("一陣霧飄來，沾濕了你的頭髮。\n", me);
			return 1;
		default:
			return 1;
	}	
}


// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼門關" NOR);
	set("long", 
		"這裡就是著名的陰間入口「鬼門關」﹐在你面前矗立著一座高大的\n"
		"黑色城樓﹐許\多亡魂正哭哭啼啼地列隊前進﹐因為一進鬼門關就無法再\n"
		"回陽間了。\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
	setup();
	replace_program(ROOM);
}

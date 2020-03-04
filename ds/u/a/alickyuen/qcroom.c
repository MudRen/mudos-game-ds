#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "QC工作室");
	set("long", @LONG
這裡是Alickyuen QC 東西時工作的地方。

QC室功能:		new [dir] 一次clone一個dir的的obj/npc到room上


LONG);
	set("hide_exits", ([
		"out" : __DIR__"workroom",
	]));
	setup();
}

void init()
{
	add_action("do_new", "new");
}

int do_new(string arg)
{
	mixed *file;
	int i;

	file = get_dir(arg, -1); 
	for(i=0;i<sizeof(file);i++)
	{
		if( file[i][1] != -2 )
                new(arg+file[i][0])->move(this_object()); 
	}
	return 1;
}

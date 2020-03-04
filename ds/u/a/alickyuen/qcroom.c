#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "QC�u�@��");
	set("long", @LONG
�o�̬OAlickyuen QC �F��ɤu�@���a��C

QC�ǥ\��:		new [dir] �@��clone�@��dir����obj/npc��room�W


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

// Room: /d/gumu/shishi3.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"�۫�"NOR);
	set("long", @LONG
�j�Ӥ����I���۫ǡA�uť�������ǨӧA�}�B���^���A�ſ������Pı
�ϧA�ߤ��u�����ߡA�ƦܧѰO�t�W�C�A�������B��a�A�|�P�p�����¤@
���A�u��a�N���e��C
LONG	);
	set("exits", ([
		"east"  : __DIR__"shishi"+(1+random(3)),
		"west"  : __DIR__"shishi"+(1+random(3)),
		"south" : __DIR__"shishi"+(1+random(3)),
		"north" : __DIR__"shishi"+(1+random(3)),
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", -40);
	set("coor/z", 80);
	setup();
}

void init()
{
	object me = this_player();
	if(userp(me) && me->query("ap") < 100)
	{
		me->move(__DIR__"shishi0"); 
		message("vision", me->name()+"�����I�I�a���F�L�ӡC\n",environment(me), ({me}));
		write(HIR"�A�C�C�o�{�ۤv��O����.....\n"NOR);
		if(userp(me) && me->query("ap") < 30)
			me->unconcious();
	}
	if(!me->query_temp("steps") && userp(me))
		me->set_temp("steps", keys(query("exits"))[random(sizeof(query("exits")))]);
}

int valid_leave(object me, string dir)
{
	if( dir != "up")
	me->receive_damage("ap", 10 + random(10));
	if( dir != me->query_temp("steps")) me->set_temp("step", 0);
	else me->add_temp("step", 1);
	if( me->query_temp("step") > 3 + random(3) )
	{
		me->move(__DIR__"shishi5");
		me->delete_temp("step");
		me->delete_temp("steps");
		me->start_busy(2);
		return notify_fail("�A�ֱo�b���A�ש�o�{�e�観�@�D���G�C\n");
	}
	return ::valid_leave(me,dir);
}


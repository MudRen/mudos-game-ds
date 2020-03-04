// Room: /d/gumu/chucangshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"�x�ë�"NOR);
	set("long", @LONG
    �j�ӥͬ��ƬO�M�W�A�x�ëǰ�ۨǤ�`�Ϋ~�A�����������b��
�}(search ��})�A�ݨӸg�`���j�ӧ̤l�e�ӥ����A��l�O�L�L���C
LONG	);

	set("exits", ([
		"east" : __DIR__"mudao22",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	::init();
	add_action("do_search","search");
}

int do_search(string arg)
{
	object ob, me = this_player();


	if ( arg == "��}")
	{
		if ( me->query_temp("fire") < 3 )
		{
			if(objectp(ob = present("fire", me)))
                  { write("�A�w�g���L����F�C\n"); return 1; }


			me->add_temp("fire", 1);
            message_vision(YEL "$N�b��}�����~�悔½��½�h����]�S��ۡC\n"NOR, me);
			return 1;
		}
		message_vision("$N�b��}�����~�悔�A½��½�h��X�@�����C\n",me);
		me->delete_temp("fire");
     new(__DIR__"obj/fire")->move(me);
		return 1;
	}
	return notify_fail("�A�n�䤰��H\n");
}

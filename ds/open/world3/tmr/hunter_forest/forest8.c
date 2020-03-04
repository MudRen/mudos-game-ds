// Room: /tmr/future/hunter_forest/forest8.c

inherit ROOM;

void create()
{
	set("short", "�ȳs��e");
	set("long", @LONG
�A�����b�@�ʤj�ȳs��e�A�ȳs�𬰤@�h�~���ý����Ӫ��A�A�i�H��
�M���a�ݨ�ȳs�𪺾�K�W�����F�ƥH�ʭp���ý��A��ͪ��o�o�򰷥��B
�c�Z�A��b�O�ܤ֨����۵M���ҡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"forest4",
	]));
	set("item_desc",([
        "�ý�":"�ȳs���ý��Ѧ��۷�j���ǤO�A���M���ʪ����n��÷���C\n�ý����M������ޡA�����G�i�H�ԧ誺(pull)�U�ӡC\n",
	]) );
	set("no_clean_up", 0);
	set("world", "future");
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_pull","pull");
}

int do_pull(string arg)
{
	object me,ob;
	me=this_player();

	if(!arg || arg!="�ý�" )
		return 0;
	if(me->is_busy() || me->is_fighting() )
		return notify_fail("�A������...\n");

	message_vision("$N�a��F�ȳs��A�B������}�l�ԧ�@���ý��C\n",me);
	me->start_busy(1);
	if(query_temp("pull_ok") )
		message_vision("$N�ԧ�F�n�@�|��A�٬O�褣�ӡC\n",me);
	else {
		message_vision("$N�ԧ�F�n�@�|��A�ש��U�@���ý��C\n",me);
		ob=new(__DIR__"obj/yalen_cirri");
		ob->move(me);
		set_temp("pull_ok",1);
	}
	return 1;
}

void reset()
{
	if(query_temp("pull_ok" ) )
		delete_temp("pull_ok");
}



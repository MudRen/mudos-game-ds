// Room: /d/gumu/jingxiu.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short",HIC"�۫�"NOR);
	set("long", @LONG
���a�ѦU�̤l�����R�פ��ΡC�a�W�Ȧ��X�ӻZ�ΡA�X�ӥj�ӧ̤l��
�b���ػ⮩�C����������(wall)�W��ۤ��֤�r, �J�Ӥ@�ݡA��ӳ���
���ۥ|�Ѥ��g���j�y�A�Ψӵ��j�ӧ̤l�����׾i�C
LONG	);

	set("exits", ([
		"south" : __DIR__"mudao21",
	]));
	set("item_desc", ([
		"wall" : "�٤W�g���F�U�إj�y��r�C\n",
	]));
	setup();
}

void init()
{ 
	::init();
	add_action("do_think", "think");
	add_action("do_think", "lingwu");
}

int do_think(string arg)
{
	mapping fam;
	object me = this_player();

	if ( !living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("�A�����ۭ��I\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "�j�Ӭ�")
          return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");
	if (arg == "qiang" || arg == "wall")
	{
		if ((int)me->query("jing") < 20 )
			return notify_fail("�Aı�o�n��,�n�Q��ı�C\n");
		if ( me->query_skill("literate", 1) > 140)
			return notify_fail("�A�w�g����Ū���F�٤W����r�C\n");
		if ( me->query_skill("literate", 1) > 10 &&
			me->query_skill("literate", 1) > me->query("combat_exp")/1000)
			return notify_fail("�A���g�礣���A����Ū���٤W����r�C\n");
		if (me->query("potential", 1) - me->query("learned_points") < 1)
			return notify_fail("�A�S���F�A����A�~��ײߤF�C\n");
		me->add("learned_points", 1);
		me->receive_damage("jing", 5 + random(10));
		me->improve_skill("literate", random(me->query_int()));
		write("�A��ۥ۾��A��򦳩һ⮩�C\n");
		return 1;
	}
      return notify_fail("�A�Q�n�⮩����H\n");
}


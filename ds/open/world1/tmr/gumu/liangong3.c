// Room: /d/gumu/liangong3.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIR"�m�\\��"NOR);
	set("long", @LONG
�����S�O�@�ǡA�o�M���@���B�B��١A�ӤS�B�B�ۤϡA�D�O�_���n
�e�A���F���A�ǳ��]�O�躡�F�L�ƲŸ��C���B�D�O�j�Ӭ����v�L�­^
���Z�\�����C
LONG	);      
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/stake" : 2, // ���H
        ]));
	setup();
}

void init()
{
	add_action("do_xiulian", "xiulian");
	add_action("do_tui", "tui");
	add_action("do_tui", "push");
}

int do_xiulian(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	if ( !arg ) 
		return notify_fail("�A�n�ѷӭ����ӭ׷ҡH\n");

	// add by tmr 2006/10/23	
	return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");

	c_exp=me->query("combat_exp");
	if (!(fam = me->query("family")) || fam["family_name"] != "�j�Ӭ�")
	return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("�A�����ۭ��I\n");
	if (me->query("jing") < 20)
		return notify_fail("�A��O���ධ���A�h�y�@�����a�C\n");
	if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("�A���r���Ѥ@�Y���A�L�k������F��C\n");
	if (arg == "top")
	{
		if ((int)me->query_skill("sword", 1) < 20)
			return notify_fail("�A�򥻼C�k�Ӯt�A�L�k��ߥɤk�C�k�C\n"); 
		if (me->query_skill("yunv-jian", 1) >= 1)
			return notify_fail("�A�w�g�Ƿ|�ɤk�C�k�A�ۤv�n�n�m�a�C\n");      
		write("�A�����ǳ����ϯ��A�ߤ������ɤk�C�k���맮���B�C\n");
		me->receive_damage("jing", 5);
		me->improve_skill("yunv-jian", 2);
		return 1;
	}
	if (arg == "southwall")
	{
		write("�A���x�A�V�n��۾��A���@�n�Q�_�h�ƨB�A���u�@�}�ĳ¡C\n");
		c_skill=(int)me->query_skill("strike", 1);
		if (c_skill < 50)
			return notify_fail("�A�ݤF�b�ѥuı�������`�A����]�S���Ƿ|�C\n");
		if (c_skill > 100)
			return notify_fail("�A�x�O�����A���ӦA���m�Z�O�F�C\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
//			me->improve_skill("strike", random(me->query("int")));
			me->improve_skill("unarmed", random(me->query("int")));
		return 1;
	}
	if (arg == "northwall")
	{
		write("�A���������_���A�ۯ��|�q�A�A�]�Q�ۤv���r�l�_�h�ƨB�C\n");
		c_skill=(int)me->query_skill("unarmed", 1);
		if (c_skill < 50)
			return notify_fail("�A�ݤF�b�ѥuı�������`�A����]�S���Ƿ|�C\n");
		if (c_skill > 100)
			return notify_fail("�A���O�w��r�L��A�o�L�ƩۼơC\n");
		me->receive_damage("ap",5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("unarmed", random(me->query("int")));
		return 1;
	}
	if (arg == "eastwall")
	{
		write("�A¶�F���۾���ۼC�B�A�Τߴ������W�C�k����C\n");
		c_skill=(int)me->query_skill("sword", 1);
		if (c_skill < 50)
			return notify_fail("�A�ݤF�b�ѥuı�������`�A����]�S���Ƿ|�C\n");
		if (c_skill > 100)
			return notify_fail("�A��۾��W�ҭz�C�k�w���M�x���A�L���A�O�O�F�C\n");
		me->receive_damage("ap", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("sword", random(me->query("int")));
		return 1;
	}
	if (arg == "westwall")
	{
		write("�A������A����譱�۾��A�Ӥ߾޽m�t�������o��աC\n");
		c_skill=(int)me->query_skill("throwing", 1);
		if (c_skill < 50)
			return notify_fail("�A�ݤF�b�ѥuı�������`�A����]�S���Ƿ|�C\n");
		if (c_skill > 100)
			return notify_fail("�A�t�����o�H�ߡA�A���ണ���_���C\n");
		me->receive_damage("ap", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("throwing", random(me->query("int")));
		return 1;
	}
	return notify_fail("�S���o�Ӧa��i�H���A�ѷӭ׷ҡC\n");
}

int do_tui(string arg)
{	
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�A�����ۭ��I\n");
	if ( arg == "westwall")
	{
		message_vision(YEL "$N�����b�ꪺ�������F�X�U�A�@���j�۽w�w���}�A�{�X�@���}���C\n"NOR,me);
		set("exits/out", __DIR__"liangong2");
          me->receive_damage("ap", 30);
		remove_call_out("close");
		call_out("close", 5, this_object());    
		return 1;
	}
	return notify_fail("�A�n������H\n");
}

void close(object room)
{
	message("vision",HIY"�j�ۺC�C�h�^�F���A�S�צ�F�X�f�C\n"NOR, room);
	room->delete("exits/out");
}


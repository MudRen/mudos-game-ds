// Room: /d/gumu/shishi0.c
// Last Modifyed by Winder on Jan. 14 2002
 
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"�۫�"NOR);
	set("long", @LONG
�Y�����۾� (wall)�S��_�F�쪬�A�A�o�{�ۤv�m���_�@�����I��
�۫Ǥ��A�ſ������Pı�ϧA�ߤ��u�����ߡA�ƦܧѰO�t�W�C�A�������B
��a�A�|�P�p�����¤@���A�u��a�N���e��C
LONG	);
	set("item_desc", ([
		"wall": "�۾���_�F�쪬�A�P�P��k�X�a�Ѧ�L�_�A�A���ѷP�Ĩ䰪�W�y�ڡC\n"NOR,
	]));
	set("exits", ([
		"out" : __DIR__"shishi1",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_tui", "push");
}

int do_tui(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�A�����ۭ��I\n");
	if (arg =="wall")
	{
		message_vision(YEL "$N�����۾��ΤO�V�W���h�A���s�s�@�n�A�۾��w�w���}�C\n"NOR,me);
		set("exits/up", __DIR__"woshi");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
	return notify_fail("�A�n������H\n");
}

void close(object room)
{
	message("vision",HIY"�۾��C�C���F�^�ӡA��_�F�쪬�C\n"NOR, room);
	room->delete("exits/up");
}

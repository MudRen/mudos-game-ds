#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�L�礧�X-�ӹD���Y");
	set("long", @LONG
�A���b���L����骺�a�U�ӹD���A�ӥޫͮ�X�ʦ~�����y�ʡA�A
�u�l�J�X�f�N�wı�o�Y�����ȡA�u�Q�n�������}�o�Ӧa��C�ӹD���S
�S���@�����u�A�R�q����^�����M�a�ӵ��檺���߷P�C�A�w�g�����
�D�����Y�F�A��b�A���e���O�D�観�j�r���Ӫ��C
LONG
	);
	set("item_desc", ([
		"�Ӫ�": "�Ӫ��W��ۤW�j�ɴ�����r�A�A�b�Ӧr�]�{���o�C�A�`�N��Ӫ����G�i�H����(push)\n"NOR,
	]));

	set("exits", ([ /* sizeof() == 2 */
	 "south" : __DIR__"g2",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

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
	if (arg !="�Ӫ�")
		return notify_fail("�A�n������H\n");
		
	message_vision(GRN "$N������}�Ӫ��A���s�s�T�_�A�Ӫ��w�w���}�C\n"NOR,me);
        set("exits/enter", "/open/world1/tmr/unquiet_manor/b1/map_1_6");
	remove_call_out("close");
	call_out("close", 5);
	return 1;
}

void close( )
{
	tell_room(this_object(), GRN"�Ӫ��C�C���F�^�ӡA��_�F�쪬�C\n"NOR);
	delete("exits/enter");
}

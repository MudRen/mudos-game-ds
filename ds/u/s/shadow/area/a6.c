/**
 * Shadow's area [��o���� - a6]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�B��"NOR);
	set("long",@LONG
�o�y�B���O�H�ϥ֮��n�����A�Q�W�C�˫س]�Ӧ��A�A�p���l�l�a
��W�h�A�@���ˤl�����o�X�������n���A���o����C�}�B�A�`�Ȥ@��
�{���N�^�F�U�h�C�C�A�w�F�w�߮}�B�e��A�`�V�H�v�A���F�����
�b���䪺�@�Ӧ~���H�A�u���~���H���Y�`��A�`��ӪŬ}����������
���a��۴�ߡC
LONG
	);
	set("light",1);
	set("outdoors", "land");
	set("exits",([
		"west": __DIR__"a4",
	]));
	set("objects",([
	__DIR__"npc/youngman":1,
	]));

	setup();

}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
	if (arg != "down")	return 0;
	else {
		message_vision("$N�����U���U�h�I\n", me);
		me->move(__DIR__"sea/a1");
		return 1;
	}
}

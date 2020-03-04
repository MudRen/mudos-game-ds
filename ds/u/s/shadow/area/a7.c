/**
 * Shadow's area [��o���� - a7]
 */
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"�H�۹D"NOR);
	set("long",
"�A���W�@���Q���F�H�۪��p�|�A���g�H�ۧ����䤤�A�������O�|\n"
"�}�A�������Фg���A�X�G�C���}�����ӥJ���[��|�P�����ҡC�p����\n"
"�ǦP�ˬO�����O�͡A�����K�g���D�䶡�C�E�ݤ��U���G�O���S���H��\n"
"���ϸz�p�|�A�������������Q�T�S��"HIW"�j�D"NOR"�A�A�¥_��h�A�b��������\n"
"�ݧϩ������p�p���T�Χ����b���Y�A�V�e�I�I�B��]�\\�|�J���H�O�I\n"
	);
	set("outdoors","land");
	set("light",1);
	set("exits",([
		"north": __DIR__"a8",
		"south": __DIR__"a3",
	]));
  
  set("item_desc",(["�j�D": "�@���I�S�b����襤���p���A���G�]�[���樫�ӯ�o�C\n"]));
  
	setup();
}

void init()
{
  add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();
	if(arg != "�j�D")
		return 0;
	else {
		message_vision("$N"NOR"���}�F�����O�����䪺�j�D�N���ӥh�C\n", me);
		me->move(__DIR__"oldway1");
		return 1;
	}
}


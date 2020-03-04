/**
 * Shadow's area [�򩳥@�� - �򩳳q�D���Y - a8]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

int push_time;

void create()
{
	set("short",HIC"�򩳳q�D���Y"NOR);
	set("long",@LONG
���B�����y�̰ʦa�D�`�F�`�A�q�D���۾��ϩ��H�ɷ|�˶�U�Ӥ@
�ˡC�ⰼ���C����K�]���������A��W�[�F�X�\���ƪ���^�A�@���p
�ꪺ�۪���ߦb�A�����e�A�ݨӫe����G�w�g�S�����i�H�e�i...
LONG
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"west" : __DIR__"a7",
		"south" : __DIR__"a6",
	]));
	set("item_desc", (["�۪�" : "�@���p�����۪��A�]�\\�i�H�յ۱�(push)�ݬݡC\n"]));

	setup();

}

void init()
{
	push_time = 0;
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me = this_player();
	
	if ( query("wasfound") )	return notify_fail("�۪��w�g�Q�H���}�F�I\n");
	
	if (arg != "�۪�")
		message_vision("�S���ؼЦb���Ӭƻ�l�O�H\n", me);
	else {
		push_time ++;
		if (push_time == 1)	{
			me->start_busy(1);
			message_vision("�A�⤺�O��`�����x�A�Ϯ|���۪��@��...�C\n�۪��孷���ʡC\n", me);
		}	else if (push_time == 2)	{
			me->start_busy(1);
			message_vision("�A�⤺�O��`�����x�A�Ϯ|���۪��@��...�C\n�۪����G���ʤF�@�ǡC\n", me);
		}	else if (push_time == 3)	{
			me->start_busy(1);
			message_vision("�A�⤺�O��`�����x�A�Ϯ|���۪��@��...�C\n�۪��C�C�a�Q$N���}�F�A�S�X�@�ӥi�ѤH�檺�_�ءC\n", me);
		} else if (push_time == 4)	{
			me->start_busy(1);
			message_vision("�A�⤺�O��`�����x�A�Ϯ|���۪��@��...�C\n�۪��w�g�������}�F�I\n", me);
			set("exits",([
				"west" : __DIR__"a7",
				"south" : __DIR__"a6",
				"northeast" : __DIR__"a9",
			]));
			set("wasfound", 1);
		}
	}
	return 1;
}

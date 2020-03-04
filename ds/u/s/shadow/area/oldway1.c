/**
 * Shadow's area [��o���� - �j�D - oldway1]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"�j�D"NOR);
	set("long",@LONG
�A�i�J�F�@���շt�����p�|�A�p����Ǫ�����P�ӻ����A�|�P��
�a�a���۴X�ʴˤѤj��A���u�]�Q�o�X�ʤj��B�h�j�b�A���|�P����
�^��o���ǩǲ��I�|�ر�h�A���ʨ������G�]�ݤ�����A�u����
�䦳�@����[�Z�K���˪L�A�u���H�S�ݸӤ����~�򨫤U�h�I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"a7",
		"west": __DIR__"oldway2",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(11))
	{               
		case 4:
		case 3:
			message_vision("��I�� �|�P�j�Ӱ}�}�D���C\n", me);
			return 1;
		case 2:
			message_vision("��ǡ�ǡ� $N��M�Q���}�I�R���Q�~�n�~�F�@���C\n", me);
			me->receive_damage("mp",random(5)+1);
			return 1;
		case 1:
		case 0:
			message_vision("$N��M�P��@�}�H�N�A�o�S�����X�ӭ��̤���l�C\n",me);
			return 1;
		default:
			return 1;
	}
}

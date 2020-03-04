/**
 * Shadow's area [��o���� - �j�D - oldway2]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"�j�D"NOR);
	set("long",@LONG
�u�ۥj�D�A���i�F�@�����`�Z�K���˪L�A���q�J�����j�𧹥��B
�\��~�ɪ����u�A�Y�S����a�ө��]�Ʃw�|���⤣�������C�a�W�k��
�����H�p�ƪ��ý��A�Q���O�o�����Ѥ骺�������ҩҼv�T�A�A�J�Ӥ@
�ݻ��M�o�{�ý��Ҩ̪������O�H����d�U���e���I�`���ý��ͪ���V
��h�A��o�{�~�M���X�y���j���X�ӡC���A���T�b�M����I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"oldway1",
		"north": __DIR__"graveyard1",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(9))
	{               
		case 4:
		case 3:
			message_vision("��I��I�� ��M�|�P�����}�}�C\n", me);
			return 1;
		case 2:
		case 1:
			message_vision("��n��n��n�� $N��Mť��X�Ӥ��ǨӺV�����n�T�I�C\n", me);
			return 1;
		case 0:
			message_vision("$N��M�Y�֤@�}�o�¡A�����ӫe�i�άO��h�I\n",me);
			return 1;
		default:
			return 1;
	}
}

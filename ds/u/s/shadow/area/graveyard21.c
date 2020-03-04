/**
 * Shadow's area [��o���� - �q�� - graveyard21]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
��L�F�@�y�S�@�y���X�ӡA�|�P���X�ӫo�ϩ��L��L�ڦ��a�A�l
�׬ݤ�����Y�C���Y�ݵۤѪŸ��Ԧh�ܪ��C��A�A�~���M�o�{�q��J
�o�q����A�@�ɧϩ����ܤF���C��A���t�H�e����^���o�A���߱���
�[�H���A���G���@���p�ߴN�|�Q�o�Ӯ����T�S���Pı�I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard31",
		"west": __DIR__"graveyard41",
		"south": __DIR__"graveyard2",
		"north": __DIR__"graveyard22",
	]));
 
	setup();	
}

int room_effect(object me)
{
	switch(random(6))
	{ 
		case 1:
			message_vision("�� �n �� �n �� �A���Gť��|�P�X�Ӥ��ǨӰ}�}���V���n�I\n", me);
			return 1;
		default:
			return 1;
	}
}

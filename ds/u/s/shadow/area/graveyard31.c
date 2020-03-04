/**
 * Shadow's area [��o���� - �q�� - graveyard31]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�o����G�O�q���F������t�a�a�A�ªF��h�u�������K�L�A�ݼ�
�l�O���i��q�����X���C�_����¬O�Ƥ��M���Ӧa�A�u���H��߬O
�_�|�g���b�o�s�j���q�������C�]�\�O�a��q����t�����Y�A�o�઺
���}�l�j�F�_�ӡA�A�[�W�쥻���˱�t���Ӧa��^�A���A����ı�a�Y
���@�ΡI
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"west": __DIR__"graveyard21",	
		"south": __DIR__"graveyard3",
		"north": __DIR__"graveyard32",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(3))
	{ 
		case 1:
			message_vision("�A���G�Pı������N�F�N�A���}�I\n", me);
			return 1;
		default:
			return 1;
	}
}

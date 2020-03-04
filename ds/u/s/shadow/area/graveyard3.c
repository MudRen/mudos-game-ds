/**
 * Shadow's area [��o���� - �q�� - graveyard3]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�o����G�O�q���F�n������t�a�a�A�n��S���X���i�h�A�ӴªF
��h��u�������K�L�A�P�˵L�k�q�����X���C�_��@�ˬO�L�k�p��
���Ӧa�A�ݼˤl�Y���w���Y�֨��U�h�O���i��|���X���F�I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"west": __DIR__"graveyard2",	
		"north": __DIR__"graveyard31",
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

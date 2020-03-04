/**
 * Shadow's area [��o���� - �q�� - graveyard42]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�o��O�q������_���A�u���@�y�p�p���D�F�y���b���A�Q���O��
�e�Ӳ������H��ͤ��ΡC�D�F�W���۴ȤT�ӡA�M�ӫo�w�M�G�C�a�A��
�ӧA�Y�ϷQ�b�۴ȤW�����]�����ơC
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard22",
		"south": __DIR__"graveyard41",
	]));
  
	setup();
	replace_program(ROOM);
}

/**
 * Shadow's area [��o���� - �q�� - graveyard41]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�A����q���谼����t�A�譱�����s�ݨ��I�m�L��A�U�A�٬O��
���F�k�n�����Y�C��ӱ�h���O��o�w�[���X�ӡA�ݯd�b�a�W���I��
�P�߯Ⱥɤw���ǡA�Y���J���[��w�L�k��{�O���󪫡A���˴˪���^
�ϧA�_�F���֪��D�A�|�P���G�����_�Ǫ��n�T�A���o�L�q��O�ӷ��C
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard21",	
		"south": __DIR__"graveyard4",
		"north": __DIR__"graveyard42",
	]));
  
	setup();
	replace_program(ROOM);
}


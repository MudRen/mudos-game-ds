/**
 * Shadow's area [��o���� - �q�� - graveyard2]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�o�̪��X�Ӧ��G�󬰭�áA�����}�H�����e�|�B�����A�a�W���G
�۱K�K�³¤����X�O�ʪ��٬O�H�������}�L�C�a��A�}�䪺�Y�\����
�F�@�Ӥj�}�A�ݼˤl���̨��e�������w��G�L��A�u�Q���z�b�o�I��
�q�����s���X�F�ƻ��ܬG�I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east": __DIR__"graveyard2",
		"north": __DIR__"graveyard41",
	]));

	/*
	set("objects",([
	__DIR__"npc/dog1": 8+random(3),
	]));  
	*/
  
	setup();
	replace_program(ROOM);
}


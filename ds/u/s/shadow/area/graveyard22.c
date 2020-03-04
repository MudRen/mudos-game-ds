/**
 * Shadow's area [��o���� - �q�� - graveyard22]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
������L�F�h�֮y�e�H���X�ӡA�F��ⰼ���¬O���H�p�ƪ��j�p
�X�ӡA�n�ת��ӸO�V�ӶV�O�H���H�ӷX�A��۳o�����A�Y�ֵo�ª��X
�Ӹs�A�A�u�Ʊ����I���}�o�Ӱ��a��C���n�_��w�g�i�ݨ즳�ɥ�
�q�t���ؿv���A�]�\���N�O�ӥi�H���}���a��]�����w�I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard32",
		"west": __DIR__"graveyard42",
		"south": __DIR__"graveyard21",
		"north": __DIR__"graveyard23",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(7))
	{ 
		case 3:
		case 2:
			message_vision(HIG"�@�������q�A���e�T�T�ƹL�I\n"NOR, me);
			return 1;
		case 1:
			message_vision("�� �T �� �s�� �Ať����Ҥ��_�쥶���Y���n���I\n", me);
			return 1;
		default:
			return 1;
	}
}

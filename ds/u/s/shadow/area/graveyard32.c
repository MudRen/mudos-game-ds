/**
 * Shadow's area [��o���� - �q�� - graveyard32]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�o����G�O�q���F�_������t�a�a�A�F�䪺�K�L���A�����F�q�F
�����h�����Y�A�_�䪺�������פF�A���h���I�ݤF�ݳ�¶�ۧA����
��A�A������P�n��A�X�G���O�d�g�@�ߪ����F���󪺼X�ӡA����
���Фg���A��[�߯B��ļ�A�뤣�o���W�ͻH�����o���a��I
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"west": __DIR__"graveyard22",
		"south": __DIR__"graveyard31",
	]));
  
	setup();
	replace_program(ROOM);
}

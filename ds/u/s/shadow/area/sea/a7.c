/**
 * Shadow's area [�򩳥@�� - �򩳳q�D - a7]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�򩳳q�D"NOR);
	set("long",@LONG
�q�D��Ǫ��۾��P�˿U�N�۲H�H���C����K(fire)�A��W������
���e�P�����A�N�����Y���C�P�򪺮����L�L�a�_�ʵۡA���G�����j��
�ͪ��b�����񬡰ʡA�C�⪺���K�]�H�ۤ��y���ܤƦ���o���Ԧh�ܡC
��O�A�ʫP�ۦۤv�ɧִ�}�o�Ӱ��a��C
LONG
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a8",
		"south" : __DIR__"a5",
	]));
	set("item_desc", (["fire" : HIG"�H�ۤ��y�j���ܤƤj�p���_�Ǥ��K...�C\n"NOR]));

	setup();
	replace_program(ROOM);
}


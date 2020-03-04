/**
 * Shadow's area [�򩳥@�� - �򩳳q�D - a5]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�򩳳q�D"NOR);
	set("long",@LONG
�A�i�J�F�`�ūշt���@���q�D�A�q�D����ǺɬO�۾��A�۾��W�U
�N�۲H�H���C����K(fire)�A��W�ٵe�ۤ@�ǽ��������e�A�e�観�@
�I�L�z�����u�A�A���e��h�γ\����X�f�]�����w�A��O�A�ʫP��
�ۤv�ɧִ�}�o�Ӱ��a��C
LONG
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a6",
		"north" : __DIR__"a7",
		"leave" : __DIR__"a4",
	]));
	set("item_desc", (["fire" : HIG"�H�ۤ��y�j���ܤƤj�p���_�Ǥ��K...�C\n"NOR]));

	setup();
	replace_program(ROOM);
}


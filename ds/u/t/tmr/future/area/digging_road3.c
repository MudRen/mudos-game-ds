// Room: /future/area/digging_road3.c

inherit ROOM;

void create()
{
	set("short", "�q�ϹD��");
	set("long", @LONG
�A�����b�@���q�Ϫ��D���A�D����ǬO�ƴɤC�ܤK�h�Ӱ����K���X��
���ؿv���A�ѩ���ΫB�O�����Y�A�x�����a�A�����q�Ϫ��q�u�ҩ~���a
��A���F�`�۹D�����U�h��h��`�J��v�ϡA���訫�h�i��F�x�ަ��Ϸ�
�K�Ʃy���u�t�C
LONG
	);
	set("world", "future");
	set("outdoors","desert");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"digging_road2",
	  "east" : __DIR__"digging_street1",
	]));

	setup();
	replace_program(ROOM);
}

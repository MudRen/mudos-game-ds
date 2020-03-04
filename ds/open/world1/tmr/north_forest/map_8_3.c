// Room: /u/l/lestia/area/map_8_3.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�j�����U");
	set("long", @LONG

�o�̬O�F�۱Фj�U��Ǫ��U��A�M�������q�Ю{�ήȫȷ������a��A�\
�]���`�������@�������A�X�Ө���զ�l�˪��Ю{�����b�Ȥl�W��ѡA�@�i
���q����l�W�\�ۯ����A�A�p�G���F�i�H�ˤ@�M�ӳܡC

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_7_3",
  "west" : __DIR__"map_8_2",
]));
   set("objects", ([ 
__DIR__"obj/tea":1,
]));

	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

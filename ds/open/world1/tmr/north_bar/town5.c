// Room: /open/world1/tmr/north_bar/town5.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�b�o�̥i�Hť�컷��ǨӪ��s���n�A���ӬO�o���񪺰ө���
�u�c�a�C���L�A�o�̪��Ů��b�Ӱ���F�A���A�Ԥ���}�lı�o
�f���A�u���e�����@�f�j���C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town4",
  "east" : __DIR__"town11",
  "north" : __DIR__"town6",
  "west" : __DIR__"town10",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

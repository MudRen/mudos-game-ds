// Room: /open/world1/tmr/north_bar/town4.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
����o�̡A����X�G���O��a�~������v�C�e��]���@�ǥ�
���B�ө����A�Q�����x�C���O�o�̪��a�O�o�����O���g�V��
�ۨǤp�ۤl�Q�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town3",
  "north" : __DIR__"town5",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

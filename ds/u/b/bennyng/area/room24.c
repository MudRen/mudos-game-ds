// Room: /u/b/bennyng/area/room24.c

inherit ROOM;

void create()
{
	set("short", "�_�~�c");
	set("long", @LONG
�o�̥ե��@���A�|�P���������A��B�z�X�H��A�ϧA���餣�����o�_
�A�}�l���˭����Pı�D�A�u�Q��ǫO�x���窫���A�M�ӳo�O���i�઺��
�]���|�P���I�@���A�䤣�X����ƪ��D
LONG
	);
    set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"room27",
  "south" : __DIR__"room26",
  "north" : __DIR__"room22",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

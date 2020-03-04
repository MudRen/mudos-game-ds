// Room: /open/world1/tmr/north_bar/town9.c

inherit ROOM;

void create()
{
	set("short", "�_�Z��-�۾��D��");
	set("long", @LONG
�o�̧j�۱j�P�����A���Aı�o�}�l�N�F�A�[�W���������j�n
�A���H���T�}�l��i�_�ӡA�����D�O�n���^���A�٬O�~��e�i�C
�p���A���e�I�����s�D�A�J�f�S��[�U���A�����]�����Ӯg����
�F�A���w���Pı�o�M�ӥ͡C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town8",
  "east" : __DIR__"town28",
]));
	set("no_clean_up", 0);
	set("shrot", "�_�Z��-�۾��D��");
	set("outdoors", "land");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}

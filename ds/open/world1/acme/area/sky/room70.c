// Room: /open/world1/acme/area/sky/room70.c

inherit ROOM;

void create()
{
	set("short", "�i�Z�K��j");
	set("long", @LONG
�o��O�Ѧa�|�����Z�Ф���A���M�M���Pı���_�a��A�ߩ��_�_
�ӡA�A�ݵۥ|�P���ɹ��A���ѦۥD���Q���Y�ª������Ҿ_��A������
��a�A��~���ż����Pı�]�H���H���h�C�A�߯��@�����o�{�e�観�@
������������A�۫H���N�O���Z�Ф���"���Z�u��"�F�C
LONG
	);
	set("light", "1");
	set("current_light", 3);
	set("objects", ([ /* sizeof() == 1 */
  "/open/world1/npc/goldman7" : 9,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/world1/manto/sky2_1f/map_7_13.c",
  "south" : __DIR__"room15",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/l/lestia/area/sn13.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG

�A���e���N����ǻ����F�۱Ъ��Ҧb�a�F�A�A�ݤ��X�ӳo�̦��ۤ����
�Y���u�Ʃ����H�`�Ȫ��a��A�A�l�׷Q���z������i�J���H�`�O���h�L�X�A
�A���F�����A�n�_���ߡA�ݵM�����e�~�򨫥h�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/dog":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn12",
  "south" : __DIR__"sn14",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
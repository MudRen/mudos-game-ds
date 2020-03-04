// Room: /u/l/lestia/area/sn14.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG
�V���j�˪L�������A�N�V�a���F�۩v���Ҧb�a�A���M�o����S�������
�Y���u�ơA����y�˪L�z�S�X�@�Ѥ��i�_�Ǫ��𮧡C�t�~�A�A�l�׷Q���z��
����j�Ѭ۶ǡA�C�Ӷi�J�˪L���B���H�A�`�S���H�@�ӦA�^�ӡC
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn15",
  "north" : __DIR__"sn13",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

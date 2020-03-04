// Room: /u/l/lestia/area/sn13.c

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
        set("objects", ([ 
                __DIR__"npc/troll": 3,
                __DIR__"npc/dog": 1,
        ]));

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn12",
  "south" : __DIR__"sn14",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

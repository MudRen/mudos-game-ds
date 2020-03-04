// Room: /u/l/lestia/area/map_5_4.c

inherit ROOM;

void create()
{
	set("short", "�F�۩v����-�Z�D��");
	set("long", @LONG
�o�̬O���Ѭ��F���F�۩v���{���Ӧa��i�H�i�m�ۤv���\�O�A�ӯS�O����
�t�d�س]���H���إߪ��Z�D���A��K���{�ۧڿi�m�C
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_5_5",
  "south" : __DIR__"map_6_4",
]));
   set("objects", ([ 
__DIR__"npc/giautoo":3,
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

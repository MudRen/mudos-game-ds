// Room: /u/l/lestia/area/map_8_5.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�Z�D��");
	set("long", @LONG

�o�̬O���Ѭ��F���F�۱Ю{���Ӧa��i�H�i�m�ۤv���\�O�A�ӯS�O����
�t�d�س]���H���إߪ��Z�D���A��K�Ю{�i�m���ե\�O�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"map_7_5",
  "west" : __DIR__"map_8_4",
  "south" : __DIR__"map_9_5",
]));
   set("objects", ([ 
__DIR__"npc/giautoo":3,
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

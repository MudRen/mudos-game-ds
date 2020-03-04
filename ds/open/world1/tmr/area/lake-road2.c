// Room: /u/t/tmr/area/lake-road2.c

inherit ROOM;

void create()
{
	set("short", "�զ�۶�");
	set("long", @LONG
�A�����b�@���d��T�򪺥۶��A���F�n��O�@���A�񪺦˪L�A�n�褣
���B���y�D�F�A�O���ѵ��L���ȫȤp�͡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"lake-road3",
  "south" : __DIR__"arbour",
  "westdown" : __DIR__"lake-road1",
]));
	set("outdoors","land");
	set("no_clean_up", 0);
	set("no_map",1);
	setup();
	replace_program(ROOM);
}

// Room: /u/a/alickyuen/area/dr22.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ISickroom");
	set("long", @LONG
�A�ݨ�@�ӭӯf�H�צb�f�ɤW�A���I�߶ˡD�D�D�D�D�D�o�̬O�@�봶
�q���f�СA���ץ���H�]��J��A�D�`�����C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dr17",
]));
set("objects", ([
__DIR__"npc/patient" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/a/alickyuen/area/dr20.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ISickroom");
	set("long", @LONG
�o�̬O�Y���f�СA�G����N�O�����H�a�~��o�_���a��A�A�o�{�쨭
�䪺�H����A�������H�A�S�X�F�@��D�`���ƪ������A���Q��A������
���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dr19",
]));
set("objects", ([
__DIR__"npc/woman" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

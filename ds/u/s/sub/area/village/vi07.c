// Room: /u/s/sub/area/village/vi07.c

inherit ROOM;

void create()
{
	set("short", "�H�ۤp��");
	set("long", @LONG
�o�O�@���e��p�������n�_�V�D���C�ѩ󱵪�������X�f�F�A�ҥH�o
�̪��H�]�֤F�ܦh�C�F�䦳�@���Ȧ�A���_�䨫�N�i�H���}�����F�C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"bank",
  "north" : __DIR__"vi08",
  "south" : __DIR__"vi06",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/a/alickyuen/area/dr5.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ISignplace");
	set("long", @LONG
�o�جO�@�Ӫ��j�󪺽��ԳB�A�A�ݨ��@���@��������H�s���b�ƶ���
�w�A�A�i�H�b�o���w��A�e����|�G�Ӫ����E������ͪv�f�C
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr4",
  "north" : __DIR__"dr6",
]));
set("objects", ([
__DIR__"npc/nurse" : 1,
]));
set("light",1);
set("world","future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

// Room: /u/a/alickyuen/area/dr3.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IDoor");
	set("long", @LONG
�b�o�����Y�A�A�ਣ��@�ӹq�l��ܪO�A��|������j�p�Ʊ��ηQ�d
�ߤJ�|�W��]�i�H�q�o�ݨ�C���_�K�O��|���Ӫ��j��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr4",
  "out" : __DIR__"dr2",
]));
set("objects", ([
__DIR__"obj/board.c" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}

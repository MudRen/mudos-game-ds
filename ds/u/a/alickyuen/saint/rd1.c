// Room: /u/a/alickyuen/area/rd1.c

inherit ROOM;

void create()
{
	set("short", "ST�CRoad�IPath");
	set("long", @LONG
�o�جOSAINT�~���q�D�A�i�H�q���@�ǯS�O�س]�C�A���ɤ]��ı��g�`
���@�Ǳ��@�����g�A�ݨӪ�����|�D�`�Ц��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rd2",
  "south" : __DIR__"dst18",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

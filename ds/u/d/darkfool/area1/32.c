// Room: /u/d/darkfool/area1/32.c

inherit ROOM;

void create()
{
	set("short", "��D�ਤ");
	set("long", @LONG
�A���n�観���p�p���ø��A���l�ؿv�������������b�������Y�A
�D�n�D���~��V�۪F���A�o�̪��~���ݨӤ���֤@�ǡA���ظ����N�M
���Pı�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"33",
  "west" : __DIR__"31",
  "south" : __DIR__"l1",
]));

	setup();
	replace_program(ROOM);
}

// �����s�ĤG�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�b�A�e�����O�@��諸���Y�A��n�b���䩹�W�����W�A���G�̪�`
���s�Y���{�H���͡A�n�S�O���p�ߤ@�I�A�o�̩��W�����W���I�S�O���~
�k�A�@�U�_��ܤj�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"3f1.c",
  "southwest" : __DIR__"2f2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

// Room: /open/world1/tmr/goat_maze/stairway1.c

inherit ROOM;

void create()
{
	set("short", "�Ϩk���g�c - �a������");
	set("long", @LONG
�A���b���@�����Y�Q�����a������A���褣���a���U�����A�b�·t
���{�p���Ǧ���s�C�A��b����W���n�T�A�@�n�n�a�j���b��ӪŶ��A
���K�X���޲�����m�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"maze15",
  "down" : __DIR__"stairway2",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

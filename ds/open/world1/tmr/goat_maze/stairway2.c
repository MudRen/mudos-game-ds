// Room: /open/world1/tmr/goat_maze/stairway2.c

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
  "up" : __DIR__"stairway1",
  "down" : __DIR__"stairway3",
]));
	set("current_light", 2);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /open/world1/tmr/north_bar/town17.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Ш��㩱");
	set("long", @LONG
�Ө�o�̡A��Ǫ�����W���۳\�h����A�����{�{�A�e���N
�O�d�i�A���󥿯��b���̡A�p�G�A�ʤ֨��㪺�ܡA�N�R�X����
�a�A���L�u�Q�n�[��]�O�i�H���C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"town16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

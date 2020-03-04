// Room: /tmr/future/hunter_forest/hole2.c

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A���B�b�@�Ӥs�}�̡A���⤣���������·t�A�ϱo�A�u�o��N�����
��樫�A�A�uı�o�A�{�b�ҳB���q�D���i�j�j���ۦ樫�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole5",
  "southeast" : __DIR__"hole1",
]));
	set("light", 1);
	set("world", "future");

	setup();
	replace_program(ROOM);
}

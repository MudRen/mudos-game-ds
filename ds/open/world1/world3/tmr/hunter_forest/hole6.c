// Room: /tmr/future/hunter_forest/hole6.c

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A���B�b�@�Ӥs�}�̡A���⤣���������·t�A�ϱo�A�u�o��N�����
��樫�A�|�P�V�ӶV�ª��·t�A�H�βV�B���Ů����Aı�o�z���L��ӡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"hole5",
	  "east" : __DIR__"hole7",
	]));
	set("no_clean_up", 0);
	set("world", "future");
	set("light",1);
	setup();
	replace_program(ROOM);
}

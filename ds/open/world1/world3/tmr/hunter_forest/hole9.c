// Room: /tmr/future/hunter_forest/hole9.c

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A���B�b�@�Ӥs�}�̡A���⤣���������·t�A�ϱo�A�u�o��N�����
��樫�A�A�uı�o�A�{�b�ҳB���q�D�ᬰ�s�͡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"hole8",
	  "south" : __DIR__"hole4",
	]));
	set("no_clean_up", 0);
	set("world", "future");
	set("light",1);
	setup();
	replace_program(ROOM);
}

// Room: /tmr/future/hunter_forest/hole5.c

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A���B�b�@�Ӥs�}�̡A���⤣���������·t�A�ϱo�A�u�o��N�����
��樫�A�A�uı�o�A�{�b�ҳB���q�D�ᬰ�s�͡C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole6",
  "south" : __DIR__"hole2",
]));
	set("light", 1);
	set("world", "future");

	setup();
	replace_program(ROOM);
}

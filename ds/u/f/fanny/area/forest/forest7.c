// Room: /u/f/fanny/area/forest/forest7.c

inherit ROOM;

void create()
{
	set("short", "�Q��L");
	set("long", @LONG
��診���s�|�u��������o�̡A�ݨӾ��ҭ̳̲`�J���a��]���L
��o��Ӥw�C�n�䤣�����a�観�Ӥp�F�l�A�֤F���ܥi�H�쨺�̥�
�𮧡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest8",
  "west" : __DIR__"forest6",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

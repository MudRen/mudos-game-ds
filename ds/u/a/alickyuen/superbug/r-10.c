// Room: /u/s/superbug/train/r-10.c

inherit ROOM;

void create()
{
	set("short", "�K��");
	set("long", @LONG
�A���M���U�F�}�B�A��ı�i�D�A���e���G�S�����i���F�A�A����@�N
�A��ӫe�����a���Y��F�A�u�ѤU�K�y���۳s�ۡA�]�\�A�ݭn��ӥ�q�u
��~��q�L�A�ثe�A�u�n�u���K�y���^���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r-9.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

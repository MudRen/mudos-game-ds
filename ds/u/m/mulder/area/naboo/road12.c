// Room: /u/s/sonicct/area/road12.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̶}�l�N�i�J�F�O�L���d��C�A�i�H�D�o��@�ǥ��O�L��
�󪺭����Mť��@�ǳ��઺�s�n�A�O�A���T���b�o�̪Y��o�Ǥj
�۵M�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road11",
  "west" : __DIR__"gate4",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/z/zorg/area/12.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 13 */
  "0" : __DIR__"laboratory",
  "1" : __DIR__"1",
  "2" : __DIR__"2",
  "12" : __DIR__"12",
  "3" : __DIR__"3",
  "4" : __DIR__"4",
  "10" : __DIR__"10",
  "5" : __DIR__"5",
  "6" : __DIR__"6",
  "7" : __DIR__"7",
  "8" : __DIR__"8",
  "9" : __DIR__"9",
  "11" : __DIR__"11",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

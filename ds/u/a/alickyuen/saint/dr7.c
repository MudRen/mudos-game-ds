// Room: /u/a/alickyuen/area/dr7.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ILiftdoor");
	set("long", @LONG
�A�Ө�j�󪺥_���A�o�جO�ǰe�����J�f�A�A����ϥζǰe���ө���
�|�U�h�Τ@�ǭ��n�a��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr6",
  "enter" : __DIR__"dr8",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/a/alickyuen/area/dr12.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ILiftdoor");
	set("long", @LONG
�o�جO�T�ӥ_�������Y�A�H�y�K���A�O�ǰe�����J�f�A�A����ϥζ�
�e���ө���|�U�h�Τ@�ǭ��n�a��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr15",
  "enter" : __DIR__"dr10",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/s/slency/area/ugelan/road5.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�վB���j�D[2;37;0m");
	set("long", @LONG
�o�̬O�o��y���������I�A�s���c�ʻP�������ߦa�ϡA�o�̤]�O
�U�ئ�~���������ߡA���_�K�O�q���Ӯc�������Q���A�Ѧ����F���@��
�а�A����i�H��վB�����~�����ϡA���n�h�O�@�y�j���s���C
LONG
	);
	set("outdoors", "land");	
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road13",
  "north" : __DIR__"pontlevis",
  "east" : __DIR__"road6",
  "south" : __DIR__"road18",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

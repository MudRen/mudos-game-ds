// Room: /u/s/sonicct/area/road10.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̬ONaboo�̪��j��A�b�_���i�H�h�쨾�㩱�A�i�H�ۥ���
�R�Q�n���f�~�C�ӪF���q�hNaboo�����ߡA�譱�h�i�H���O�L�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"middle",
  "north" : __DIR__"shop3",
  "west" : __DIR__"road11",
  ]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

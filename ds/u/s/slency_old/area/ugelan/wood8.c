// Room: /u/s/slency/area/ugelan/wood8.c

inherit ROOM;

void create()
{
	set("short", "�L���p�|");
	set("long", @LONG
�o�̬O�˪L�����ϸz�p�|�A�Pı�Q���M�D�A���ɦ��L���j�ӡA�Aı
�o�n���i�F�P�Ҥ@�몺�ΪA�A���n���A��b�O�@�ӥ@�~���ڡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wood2",
  "north" : __DIR__"wood9",
]));
	set("outdoors", "forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

// Room: /u/b/bennyng/area/room49.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O�s�ϩx�M�g��c����׳B�A�|�B��@���A�����������D
LONG
	);
      set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room50",
  "southup" : __DIR__"room48",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

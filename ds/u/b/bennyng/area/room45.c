// Room: /u/b/bennyng/area/room45.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O�s�ϩx�M�g��c����׳B�A�|�B��@���A�����������D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room46",
  "northup" : __DIR__"room44",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

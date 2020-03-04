// Room: /u/a/acme/area3/p3.c

inherit ROOM;

void create()
{
	set("short", "�a�Q�U");
	set("long", @LONG
�A�����b�a�Q�U�A�b�a�Q�k�䪺�j�K�F�A���Q�۵��ĵ��C�������H�A
�\�h�p�Ħb���^�����x�A�b�A���F��i�ݨ��@�y�p�����C
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"p4",
  "east" : __DIR__"p6",
  "west" : __DIR__"p18",
  "south" : __DIR__"p2",
]));
     set("objects",([
        __DIR__"npc/child" : 3,
     ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

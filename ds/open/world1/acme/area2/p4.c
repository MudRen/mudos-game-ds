// Room: /u/a/acme/area3/p4.c

inherit ROOM;

void create()
{
	set("short", "�x�|");
	set("long", @LONG
�A�����b���j���x�|�A�b�x�|�̦��\�h�ĵ��b���A�A�b�A���_�観�@
�Ӥj�U�A�n��h���@���j�_��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"p5",
  "south" : __DIR__"p3",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

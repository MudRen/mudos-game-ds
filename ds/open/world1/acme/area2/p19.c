// Room: /u/a/acme/area3/p19.c

inherit ROOM;

void create()
{
	set("short", "�I���ש�");
	set("long", @LONG
�o�̴N�O�I�����שФF�A���Y�M�s���A�ä����O�j��H�a�A�o�̪�
�\�]�۷�²��A�@�i����A�X�i�Ȥl�A�M�@�i�ɡA�N�L�O���F�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p18",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

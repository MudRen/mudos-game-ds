// Room: /u/a/acme/area3/p20.c

inherit ROOM;

void create()
{
	set("short", "�ȩ�");
	set("long", @LONG
�o�̬O�I�����ȩСA���Y�M�s���A�ä����O�j��H�a���@���A�o��
���\�]�۷�²��A�õL�S�O���B�C
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p18",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

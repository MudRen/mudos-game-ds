// Room: /u/a/acme/area3/p16.c

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�@����e�F�誺���Y�A���Y���\��F�\�h�p�֮�A�_��O�Ӽp��
�A�ǨӰ}�}�������A����i�q���x�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"p17",
  "west" : __DIR__"p12",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

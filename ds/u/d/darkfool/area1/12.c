// Room: /u/d/darkfool/area1/12.c

inherit ROOM;

void create()
{
	set("short", "��D�ਤ");
	set("long", @LONG
�o�̪���D�Ǧ����ਤ�A�q����_����v�ϡA�F�V����D�~��
�F�����F�@�p�q�Z���C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"13",
  "west" : __DIR__"11",
  "north" : __DIR__"14",
]));

	setup();
	replace_program(ROOM);
}

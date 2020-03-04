// Room: /u/a/acme/area/street3.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̬O�ѫ��F�䪺��D�A��������e��Ӥѫ��A����i�ݨ�ѫ���
�j�s���A���F����i�ݨ������C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"cloth",
  "west" : __DIR__"plaza3",
  "east" : __DIR__"street4",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}

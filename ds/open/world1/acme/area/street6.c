// Room: /u/a/acme/area/street6.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̬O���ѫ����_��A�o�̤H�鬤��A�\�h���C�ȭn�@�@�Ѵ�
�_���A�D������Ǧ��\�h�u�l�A�٦����������H�A���x�D�Z�A���_�i
��Ѧ��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pill",
  "south" : __DIR__"plaza4",
  "north" : __DIR__"pathway1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/acrobat" : 1,
  __DIR__"npc/strongman_15" : 1,
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}

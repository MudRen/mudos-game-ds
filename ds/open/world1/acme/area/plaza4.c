// Room: /u/a/acme/area/plaza4.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�ѫ����s���_��A�o�̤H�鬤��A�\�h���C�ȭn�@�@�Ѧ���
�_���A�D������Ǧ��\�h�u�l�A�٦����������H�A���x�D�Z�A���_�i
��Ѧ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"street6",
  "south" : __DIR__"plaza1",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}

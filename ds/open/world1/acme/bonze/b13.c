// Room: /open/world1/acme/bonze/b13.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�x��");
	set("long", @LONG
�o���q�D�O�ѥ۶��Һc���A�۶��P�۶������_�ؤ����@�Ǥp���
�X�ӡA�ⰼ���֮��������ܭZ���A�ݨӨ���ܦn�����U�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"b14",
  "south" : __DIR__"b12",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}

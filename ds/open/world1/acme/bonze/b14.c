// Room: /open/world1/acme/bonze/b14.c

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
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"b15",
  "west" : __DIR__"b17",
  "north" : __DIR__"b16",
  "south" : __DIR__"b13",
]));
set("objects",([
   __DIR__"npc/bonze" : 1,
   __DIR__"npc/bonze2" : 1,
]) );
        set("light",1);

	setup();
	replace_program(ROOM);
}

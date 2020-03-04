// Room: /u/t/truewind/Minetown/area/minetown7.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�o�̬O�q����t���@���Ŧa�A�@�D�]���q�����𩹫n�����ӥh�C
�����F�@�Ǽo�󪺾���C�_��ǨӪŤ������_���������n�A�X���a
�ԹB�騮���g�L���a�A�ǳƧ�f���B�컷�a�h�C
LONG
	);
	set("outdoors","land");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"plane-room",
  "east" : __DIR__"minetown6",
  "south" : __DIR__"minetown8",
]));
	set("no_clean_up", 0);
	set("current_light", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/s/sonicct/area/road2.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̦��ܦh�H�ѫn�����ӪŲ��W�_���������ߡA�Q����
���C�A�o�{�F�_�������Q�⪺�O���A�N���D�o�̴N�ONaboo������
��--���c�ت��a�ϡC
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road20",
  "north" : __DIR__"road3",
//  "west" : __DIR__"road13",
  "south" : __DIR__"road1",
]));
		 set("objects",([
  __DIR__"npc/citizen":1,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}

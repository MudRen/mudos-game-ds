inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�o�̬O���D�������A�b�A�����W�A�N�O���Ū��ѪŤF�A�����D����
��A�o�̳��M�ئ��o�Ӽˤl�A�����D�O�����]�A�u�ä������b���D�W
�r�ޡA���������ޡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path8",
  "west" : __DIR__"path5",
  "north" : __DIR__"path3",
  "south" : __DIR__"path1",
]));
	set("objects",([
  __DIR__"npc/guard" : 4,
]));
	set("light",1);
	setup();
	replace_program(ROOM);
}

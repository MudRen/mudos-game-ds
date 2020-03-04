// Room: /open/world1/faceoff/sky/ten17s.c

inherit ROOM;

void create()
{
	set("short", "�T��");
	set("long", @LONG
�A�{�b���b�]�a�����@���T�Τ��A�Τ��\�]²�氮�b�A
���M�y�L���Ǥ���B�ˤl�ҽs�����íѡA���O�Τ�����ݨ�
�۷�嶮�A�ݼˤl�o�Τl���D�H���۷����[�C
LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/meo-aunt" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ten17",
]));

	setup();
	replace_program(ROOM);
}

// Room: /open/world1/cominging/purple_sun/4f1.c

inherit ROOM;

void create()
{
	set("short", "�����s��");
	set("long", @LONG
�o�̬O�����s���s���W�A�o�̪��Ů��I�}���A�O�H���I�I�l�x��
�A�b�_�䦳�@���p�Ŧa�M�s�}�A�Ŧa�W�٦��Ǧ��G�O���~�}�x������A
�����D�O����F��C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"4f2.c",
  "south" : __DIR__"4fs",
  "down" : __DIR__"3f3.c",
]));
	set("no_clean_up", 0);
	set("world", "past");
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}

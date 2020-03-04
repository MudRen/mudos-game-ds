// Room: /open/world1/faceoff/sky/ten17.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�]�a�����D�n�s���A�ĵ���B�b�o�̼^���A�ڻ�
�]�a���۫ʫخɥN�ɴN�w�s�b�A�~����½�a�СA�o��o�l��
�p�@�A�ѩ�v�ڪ��O�q�A�]�a���@���b�Q�U�j�s���P�@�L��
���s�b�ۡA�b�s�������@�Ӥ����A���Ҳ֪��A�@�ݴN�P��f
���o....
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/pot.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"ten17s",
  "northwest" : __DIR__"ten18",
  "east" : __DIR__"ten12",
]));
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

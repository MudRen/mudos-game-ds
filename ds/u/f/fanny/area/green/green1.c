// Room: /u/f/fanny/area/green/green1.c

inherit ROOM;

void create()
{
	set("short", "�i���k���j�J�f");
	set("long", @LONG
�@��L�ڪ����A�񲴩ҤΪ����������O�@�ӼҤl�L�X�Ӫ��A�u
��ݻ��������Y���G���۸󤣹L�����s�A�@�������컻�����F��C��
��o��H�������A�A���ѦۥD����i�F�_�ӡA�ݨӳo���G�N�O����T
�j�I�a�������Сi���k���j�C
LONG
	);
	set("world", "undefine");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"green1",
  "north" : __DIR__"green1",
  "west" : __DIR__"green1",
  "east" : __DIR__"green2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

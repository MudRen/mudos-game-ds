// Room: /u/a/acme/area/plaza.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O���s��������A�u�������������j�۸O�A�����K�ذ��A�ƵM
�q�ߡA�W�Y�٥Φ���g�F�g�峹�A�r�񴳻�A�ݨӦ��G���v�w�۷�[���A
���F�i�q���s���������A����i�ݨ즳�@���ȴ̡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"st",
  "east" : __DIR__"plaza1",
]));
set("objects",([
//        __DIR__"npc/moon" : 1,
]) );
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}

// Room: /d/xiangyang/zhonglie.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���P��");
	set("long", @LONG
�o�̬O�����������P���A�Q�l�~�Ӭ��O���������묹���P
�h�򰩳��w���b�o�̡A�C�Ӧ��R��ߪ��n�~��o���|�Ӳ����@
�U����C
LONG );
	set("no_fight", 1);
	set("no_beg", 1);
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"eastroad2",
	]));
	set("coor/x", -470);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
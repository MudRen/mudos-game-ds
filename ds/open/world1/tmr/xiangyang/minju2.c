// Room: /d/xiangyang/minju2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���~");
	set("long", @LONG
�o�O�@�a��������H����СA�Фl�D�H���b�a�̦��o�����A
�ݨ��A�i�ӡA�榣���_���V�A���۩I�C
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"jiedao",
	]));
	set("coor/x", -490);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
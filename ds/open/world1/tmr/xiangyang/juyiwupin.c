// Room: /d/xiangyang/juyiwupin.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���~��");
	set("long", @LONG
�o�O�E�q�]�����U�ئU�˪��~���ж��C���t���G�̤l�Z
�פ奿�b�o��t�d�V�����Ȫ��s����o�U�ت��~�C
LONG );
	set("exits", ([
		"northwest" : __DIR__"juyihuayuan",
	]));
	set("objects", ([
		__DIR__"npc/wuxiuwen" : 1,
	]));
	set("coor/x", -525);
	set("coor/y", -504);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
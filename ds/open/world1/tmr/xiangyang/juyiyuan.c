// Room: /d/xiangyang/juyiyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�j�|");
	set("long", @LONG
�o�̬O�����w���ϫ��ӳ��t�B���T���N��ت��ΨӦw�m�U
�a�e�ӮĤO���q�h���a��C�n���O�@���������q�Y�A�F�����
�O�m�Z���C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"juyilianwu1",
		"west"  : __DIR__"juyilianwu2",
		"south" : __DIR__"juyilang",
		"north" : __DIR__"westjie2",
	]));
	set("objects", ([
		__DIR__"npc/zhuziliu" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -501);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/xiangyang/walle8.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�F���Y");
	set("long", @LONG
�o�̬O�������F���Y�C�@�ǧ��L���b���Y���ޡA�@�Ӥ��N
���b�o��t�d�����U�ئu�����ơA�@�Ǥ}�b�⥿���}�f�b��n
�۫��U�����R�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northwest" : __DIR__"walln7",
		"southdown" : __DIR__"walle6",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -450);
	set("coor/y", -460);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
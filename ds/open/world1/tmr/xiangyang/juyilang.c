// Room: /d/xiangyang/juyilang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���W���Y");
	set("long", @LONG
�o�O�@�����������Y�A�Y�U�O�@������C����M�۪�����
�h�A�Ѻ�M���A�A��ݨ��@�ǳ��b�C�ӹC�h�C�n���N�O�@�Ӥj
���A�餺�F��ⰼ�U���@�ƴ[�СC
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"juyihuayuan",
		"north" : __DIR__"juyiyuan",
	]));
	set("coor/x", -530);
	set("coor/y", -502);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/xiangyang/juyihuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�o�O�E�q�]���j���C�餺�صۦU�ئU�˪����A�M���j
�ӡA�A��D��ѪѪ᭻�C�餺�F��ⰼ�U���@�ƴ[�СA�_���O
�@������A���W�[�ۨ��Y�A���q��j��C�n���O�]���p�СA�F
�n��V���@�����~�СC
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"      : __DIR__"juyifemale",
		"west"      : __DIR__"juyimale",
		"south"     : __DIR__"juyichufang",
		"north"     : __DIR__"juyilang",
		"southeast" : __DIR__"juyiwupin",
	]));
	set("objects", ([
		__DIR__"npc/guofu" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -503);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("gender") != "�k��" && dir == "west") 
		return notify_fail("�k�k���O�A�Ш�ﭱ��I\n");

	if (me->query("gender") != "�k��" && dir == "east") 
		return notify_fail("�k�k���O�A�Ш�ﭱ��I\n");

	return ::valid_leave(me, dir);
}
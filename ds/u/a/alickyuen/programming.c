#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR"�{���Q�׫� "HIY"[Java 2 Version]"NOR);
	set("long", @long
�o�̳̭踨�����s�ж��A���F���{��̷s���]�ƥ~�A�٦��@����
�@�ɳ̱o�@�����W�s��޹q�l��ܪ��A�O�ΨӰO������{���g�@���Q
�פ峹�C��M�w��A�ӰQ�פδ��F�X�A�_�Q���N���C
long);
	set("light", 1);
	set("no_fight", 1);
	set("no_cast", 1);
	set("valid_startroom", 1);
	set("exits", ([
		"out" : __DIR__"workroom.c",
	]));

	setup();
        load_object("/obj/board/programming_b.c");
}

void init()
{
}

void test()
{
	write(""+save_variable(dbase));
}

// �s��(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�A���b�@�����۾Q�����p���W�A�p�����_���N�O��Z�������ݥx�A�n���O
��Z�����j���C�A�i�H(enter)�i�J��Z���C
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"gate",
	]));
	setup();
}

void init()
{
	add_action ("do_enter","enter");
}

int do_enter(string arg)
{
	object me=this_player();
	string mout=YEL ""+me->query("name")+"���i�F��Z���C\n" NOR;
	string min=YEL ""+me->query("name")+"���~���F�i�ӡC\n" NOR;

	message( "vision", mout, environment(me), ({me}) );
	me->move(__DIR__"kantai2");
	message( "vision", min, environment(me), ({me}) );
	return 1;
}

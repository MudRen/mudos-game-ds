// �s��(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�A���b�@�����۾Q�����p���W�A�p�����_���N�O��Z�������ݥx�A�n���O
��Z�����j���C
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"gate",
		"north":__DIR__"kantai",
	]));
	setup();
}
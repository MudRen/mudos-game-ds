// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"��ڤj�Ƭ�"NOR, ({ "moon board","board" }) );
	set("location", "/open/world1/acme/area/moon/room3");
	set("board_id", "moon_room3_b");
	set("long",
		"�o�O�@�Ӥ�ڤ��i�ڤ��j�ƥΪ��d���O�C\n" );
	setup();
	set("capacity", 99);
  set("master",({ "jawei" }));
}

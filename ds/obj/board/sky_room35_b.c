// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"�Ѧa�|�d��"NOR, ({ "chat board","board" }) );
	set("location", "/open/world1/acme/area/sky/room35");
	set("board_id", "sky_room35_b");
	set("long",
		"�o�O�@�ӤѦa�|���@��ʥγ~���d���O�C\n" );
	setup();
	set("capacity", 99);
}

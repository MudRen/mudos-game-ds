// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"�Ѧa�|�n�D�O"NOR, ({ "heaven board","board" }) );
        set("location", "/open/world1/manto/sky2_2f/map_9_12");
	set("board_id", "sky_room05_b");
	set("long",
		"�o�O�@�ӤѦa�|���i�|���j�ƥΪ��d���O�C\n" );
	setup();
	set("capacity", 99);
}
// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY"�Ѧa�|�����O"NOR, ({ "quest board", "board" }) );
       set("location", "/open/world1/manto/sky2_2f/map_9_4");
        set("board_id", "sky_secret_b");
	set("long",
	"�o�O�@�ӤѦa�|�����������d�o�O�C\n");
	setup();
	set("capacity", 99);
}

// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY"�Ѧa�|�����O"NOR, ({ "quest board", "board" }) );
        set("location", "/open/world1/acme/area/sky/secret");
        set("board_id", "sky_secret_b");
	set("long",
	"�o�O�@�ӤѦa�|�����������d�o�O�C\n");
	setup();
	set("capacity", 99);
}

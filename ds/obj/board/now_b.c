#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"現代小語"NOR, ({ "now board","board" }) );
	set("location","/open/world2/meetroom");
        set("board_id", "now_b");
        set("long",     "用來記東西的\n" );
        setup();
        set("capacity", 100);
        set("master",({ "eeman" }) );

}

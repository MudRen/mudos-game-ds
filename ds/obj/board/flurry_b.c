#include <path.h>
#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIB"疾風之板"NOR, ({ "board" }));
        set("location",COMINGING_PAST+"area/flurry3.c");
        set("board_id", "flurry_b");
	set("long","由疾風門內的弟子所捐贈的板子。\n");
        setup();
        set("capacity", 70);
        set("master",({ "cominging" }));
}
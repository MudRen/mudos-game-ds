#include <path.h>
#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIB"�e�����O"NOR, ({ "board" }));
        set("location",COMINGING_PAST+"area/flurry3.c");
        set("board_id", "flurry_b");
	set("long","�ѯe���������̤l�Ү��ت��O�l�C\n");
        setup();
        set("capacity", 70);
        set("master",({ "cominging" }));
}
#include <path.h>
#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIY"�����d����"NOR, ({ "board" }));
        set("location",COMINGING_PAST+"area/boo-lin.c");
        set("board_id", "boo-lin_b");
	set("long","�@�ӥѷ����W���l�K�����d�����C\n");
        setup();
        set("capacity", 60);
        set("master",({ "cominging" }));
}
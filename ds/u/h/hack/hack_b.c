#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name(RED"駭客"WHT"液晶"HIY"手寫板"NOR,({"hack board","board"}));
    set("location","/u/h/hack/workroom.c");
    set("board_id", "hack_b");
    set("long","這是一塊許多晶片所組合出來的高科技留言板。\n");
   set("master","hack");
	setup();
    set("capacity",50);
replace_program(BULLETIN_BOARD);
}

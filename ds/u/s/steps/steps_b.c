#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIB"留言之版"NOR,({"board"}));
set("location","/u/s/steps/workroom.c");
set("board_id", "steps_b");
set("long",HIY"隨便你寫什麼啦，或是找我\n"NOR);
setup();
set("capacity",100);
}

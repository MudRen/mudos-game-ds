#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIC"JSH Board"NOR,({"JSH board","board"}));
 set("location","/u/j/jsh/workroom");
 set("board_id", "jsh_workroom_b"); 
        set("long",
        "[0;5;34m�[5m�[5m�[5md[5m�[5m�[0m�C\n");
        setup(); 
        set("no_get",1);
        set("capacity",300);
set("master",({ "jsh"}));
 
} 


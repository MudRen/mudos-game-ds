#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"Moon's Board"NOR,({"board"}));
          set("location","/u/m/moon/workroom");
        set("board_id", "moon_workroom_b");
        set("long",
        "[0;5;34m�[5m�[5m�[5md[5m�[5m�[0m�C\n");
        setup();
        set("capacity",200);
  set("master",({ "moon"}));
 
}


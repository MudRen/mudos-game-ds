#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"�o�b�O����"NOR,({"idle board","board"}));
          set("location","/u/i/idle/workroom");
        set("board_id", "idle_b");
        set("long",
        HIC"�����o�b�ɶ����p�O���C\n"NOR);
        setup();
        set("capacity",100);
  set("master",({ "idle"}));

}

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"飛羽之記事"NOR,({"hiko-board","board"}));
        set("location","/u/h/hiko/workroom");
        set("board_id","hiko_workroom_b");
        set("long",
        "這是有關想跟"HIC"飛羽"HIW"聯絡以及指教的小地方，\n"NOR
        "如果有任何意見也請在此建議，"HIC"飛羽"HIW"會盡速\n"NOR
        "回覆並請多多灌水囉^^b。\n"
          );
        setup();
        set("capacity",100);
  set("master",({ "hiko"}));
 
        replace_program(BULLETIN_BOARD);
}



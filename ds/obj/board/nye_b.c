#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
 set_name(HIW+"ㄣ"+NOR+"的流言板",({"board"}));
set("location","/u/n/nye/workroom.c");
 set("board_id", "nye_b");
  set("long",
    "你看到ㄣㄣ的流言板，忍不住衝動馬上提起筆來塗塗抹抹。\n");
setup();
  set("capacity",100);
  set("master",({ "nye" }));
   replace_program(BULLETIN_BOARD);
}

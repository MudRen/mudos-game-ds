#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
 set_name("霂夢的小版版",({"board"}));
  set("location","/u/l/legend/workroom.c");
   set("board_id", "legend_b");
  set("long",
    "這是一個霂夢專用的小版版。\n你看到了之後馬上想在上面留言給小夢夢。\n");
setup();
  set("capacity",100);
   replace_program(BULLETIN_BOARD);
}

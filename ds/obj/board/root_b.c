#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
 set_name("根的筆記簿",({"root notebook","board" }));
set("location","/u/r/root/workroom.c");
 set("board_id", "root_b");
  set("long",
    "這一本root常用的notebook可以用來留言喔!!\n");
setup();
 set("master",({ "root" }) );
  set("capacity",100);

}


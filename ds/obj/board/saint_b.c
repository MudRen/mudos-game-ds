#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name("[1;37m  Π [1;33m米米爾石碑 [1;37mΠ [0m",({"mimir board","board"}));
  set("long",
"
      "HIC"一塊由"HIG"奇異光石"HIC"造成的石碑聳立在這裡，
  "HIC"奇怪的是，石碑表面竟然不斷浮現奇特的"HIW"光采"HIY"戎文(rune)
    "HIC"你定眼一看，這"HIY"戎文"HIC"竟自然轉換成你熟悉的文字!!?"NOR"

" );

set("location","/u/s/saint/workroom.c");

 set("board_id","saint_b");
setup();
  set("capacity",100);

}

#include <ansi2.h>            // 特卡如果要加顏色記得要包含 ansi.h 喔
inherit __DIR__"std_card.c";
void create()
{
  set("short",HBBLU+HIW"  Mr.MAGIC  "NOR);   // 有顏色的卡要補滿十二個半形
  set("pow", ({6,3,4,5}) );
  set("lv",4);
  set("ver",1);
  set("ver_n","α\版");
  set("num",30);
  set("long","紀念第一版發行的特別卡。\n老闆的名字叫小高。");
  set("magic-card/only_one","v1-30");   // 特卡專用(一個人最多拿到一張)
  setup();
}

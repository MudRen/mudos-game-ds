#include <ansi.h>
inherit NPC;
void create()
{
  set_name("洛亭雲", ({ "luo ting-yun","ting","yun","luo" }) );
  set("gender", "男性" );
  set("long",@LONG
洛家老二，性好酒，別號「一飲拼千鍾」，最愛春風樓陳年紹興酒，
每過春風樓，不醉不歸。他看起來似醉非醉，整個人酒氣燻的你都受
不了了。
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
}
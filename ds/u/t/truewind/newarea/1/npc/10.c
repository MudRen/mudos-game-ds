#include <ansi.h>
inherit NPC;
void create()
{
  set_name("祀九郎", ({ "si zou lung","lung","zou","si" }) );
  set("gender", "男性" );
  set("long",@LONG
他背上的兩條紫色帶子捆住兩根交錯的旗子，一身白色的衣服，面無
表情的喝著酒，偶而露出深不可測的笑意，誰也不知道他在笑什麼。
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
}
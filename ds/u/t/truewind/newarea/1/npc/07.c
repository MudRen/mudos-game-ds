#include <ansi.h>
inherit NPC;
void create()
{
  set_name("琴操", ({ "Qin-Cao","Cao","cao" }) );
  set("gender", "女性" );
  set("long",@LONG
琴操是春風樓名聞遐邇的名妓，琴棋書畫樣樣皆通，公孫輩個個皆曾
對她動過心。她穿著一件白底短襖，翠花滾邊長裙。此處人讚其「任
是無情也動人。」
LONG
);      
  set("age",20);
  set("level",16);
  set("race","human");
  setup();
}
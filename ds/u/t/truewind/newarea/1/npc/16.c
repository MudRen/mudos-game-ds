#include <ansi.h>
inherit NPC;
void create()
{
  set_name("老叟", ({ "aged man","man","aged" }) );
  set("gender", "男性" );
  set("long",@LONG
一個身形佝僂的老人。兩眼無神的看著你。
LONG
);      
  set("age",74);
  set("level",25);
  set("race","human");
  setup();
}
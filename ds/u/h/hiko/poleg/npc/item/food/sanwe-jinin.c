#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIY"�T���]��"NOR, ({ "sanwe jinin","jinin" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�ΤT�ؤ��P���h�հt���Ʋz�A�������ΡA�Y�_�ӤQ���A���C\n");
    set("unit","��");
    set("value",2000);
    set("heal_hp",50);
    set("heal_ap",80);
    set("food_remaining",15);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}






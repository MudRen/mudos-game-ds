#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIY"�������L"NOR, ({ "shugin pinpan","pinpan" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�إѨ�����P���ק@�����Ʋz�A���k��ӡA���D�۷����C\n");
    set("unit","�J");
    set("value",2000);
    set("heal_hp",60);
    set("heal_ap",40);
    set("food_remaining",15);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}







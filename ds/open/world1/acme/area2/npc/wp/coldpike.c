#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(HIC"寒鐵戟"NOR, ({ "cold iron halbert","halbert" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",30);
	       set("limit_skill",25);
	       set("limit_lv",15);
               set("unit", "把");
		set("long", "此戟之末有如鷹勾，勾彎之內角鑲有一層寒鐵鋒利無比，\n"
			   "寒鐵所傷之破口較一般鐵器砍中難以癒合。\n");
             set("value",3000);
	       set("volume",6);
               set("material","blacksteel");
	}
   set("weapon_prop/hit",-5);
   set("weapon_prop/dodge",-5);
   set("weapon_prop/dex",1);
   init_fork(55,TWO_HANDED);
   setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
  if(random(4)) return;
  message_vision("$N被寒鐵戟的刃面劃傷, 傷口突然無法癒合...!\n",victim);
  victim->apply_condition("blooding", victim->query_condition("blooding")+3);
  return;
}

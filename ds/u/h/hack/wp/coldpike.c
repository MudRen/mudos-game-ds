#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(HIC"�H�K�u"NOR, ({ "cold iron halbert","halbert" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",30);
	       set("limit_skill",25);
	       set("limit_lv",15);
               set("unit", "��");
		set("long", "���u�������p�N�ġA���s�������^���@�h�H�K�W�Q�L��A\n"
			   "�H�K�Ҷˤ��}�f���@���K���夤���H¡�X�C\n");
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
  if(!me || !victim || me->is_busy() ) return;
  if(random(4)) return;
  message_vision("$N�Q�H�K�u���b������, �ˤf��M�L�k¡�X...!\n",victim);
  victim->apply_condition("blooding", victim->query_condition("blooding")+3);
  return;
}

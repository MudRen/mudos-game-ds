#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("���ѮƲz", ({ "fail food","food" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�D���D���B�C��_�S�����ѮƲz�A�O�H�椧�ͬ�\n");    
    set("unit","��");
    set("heal_hp",-5);
    set("heal_ap",10);
    set("heal_mp",-5);
    set("food_remaining",1);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}








#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIG"�ï]�B�A��"NOR, ({ "jansu-fatre fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�حn�ΰ��W�������Ʋz�A�ӥB�t�W��u�u�����զ�ï]\n"
                "�H�λA���յ�@Ũ�A���O���K�O�H�����j�ʡA�O����\n"
                "�@�w�]�O���H�ɥΪ��W��C\n");
    set("unit","��");
    set("value",2000);
    set("heal_hp",75);
    set("heal_ap",75);
    set("heal_mp",30);
    set("food_remaining",16);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}









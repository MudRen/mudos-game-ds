#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIR"�c"HIR"��"HIY"��"HIY"��"NOR, ({ "gontinmi fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�o�O�ǻ��Ѯc�ʱs�p�y�X���B��Ӧ��A�ҥΧ��ƻ��椣��\n"
                "�Ө�ҥΪ��ը��覡��O�W�a�A�ҥH�����s�@���\\�A�]��\n"
                "�Y�n�Y��o�Ʋz�A�]���������n�������C\n");
    set("unit","��");
    set("value",3000);
    set("heal_hp",60);
    set("heal_ap",85);
    set("heal_mp",85);
    set("eat_msg","$N�Y�F�@�f$n�C");
    set("eff_msg",HIG "�A�P�쨭�W�ˤf�_��F�A�����κZ�C" NOR );
    set("food_remaining",24);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
 set("cure",([
         "head" : 7,
         "body" : 7,
         "right_arm" : 7,
         "left_leg" : 7,
            ]));
}














#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIY"��"HIW"��"HIY"��"HIR"��"NOR, ({ "wuces fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�D�\\���Q���ج����Ʋz�A�ΤF�Q�����h�����ƻs�@�Ӧ�\n"
                "�D��O�ΦU�⳽�بӽհt�A���ܦh�ˤơA�Pı�_�ӴN�O\n"
                "��m�Q���A�R�A���D��O���ΡC\n");
    set("unit","��");
    set("value",3000);
    set("heal_hp",55);
    set("heal_ap",40);
    set("heal_mp",90);
    set("eat_msg","$N�Y�U$n�C");
    set("eff_msg",HIG "�A�P�쨭�W�ˤf�_��F�A�����κZ�C" NOR );
    set("food_remaining",20);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
 set("cure",([
         "head" : 5,
         "body" : 5,
         "right_arm" : 5,
         "left_arm" : 5,
            ]));
}













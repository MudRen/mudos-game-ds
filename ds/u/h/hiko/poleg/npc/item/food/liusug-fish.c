#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIW"��"HIC"�t"HIY"��"HIW"��"NOR, ({ "liusug fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�D�\\�����ݵ��R���Ʋz�A�ΤF�ܦh�}�������ƻs�@�Ӧ�\n"
                "�ӥB�ҥ���ĬO�q�s�t���o�A�ҥH���D���A����ܲH�n\n"
                "�Pı�ܲM�D�A�]���|�o���C\n");
    set("unit","��");
    set("value",3000);
    set("heal_hp",70);
    set("heal_ap",70);
    set("heal_mp",70);
    set("eat_msg","$N�Y�F�@�f$n�C");
    set("eff_msg",HIG "�A�P�쨭�W�ˤf�_��F�A�����κZ�C" NOR );
    set("food_remaining",20);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
 set("cure",([
         "head" : 5,
         "body" : 5,
         "right_leg" : 5,
         "left_leg" : 5,
            ]));
}














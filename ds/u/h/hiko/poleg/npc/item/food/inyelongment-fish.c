#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIG"��"HIW"�V"HIC"�s"HIW"��"NOR, ({ "inyelong-ment fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�D�\\���Q���ج����Ʋz�A����t�W�J�������s�ι���\n"
                "�H�Φ��۫ܦh�����@�D��A���ܦh�ˤơA�Pı�_�ӴN�O\n"
                "�D�`��߮��ءA���D��O�@���C\n");
    set("unit","��");
    set("value",3000);
    set("heal_hp",55);
    set("heal_ap",90);
    set("heal_mp",40);
    set("eat_msg","$N�Y�F�@�f$n�C");
    set("eff_msg",HIG "�A�P�쨭�W���ˤf�C�C�_��F�A�����κZ�C" NOR );
    set("food_remaining",20);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
   set("cure",([
         "head" : 5,
         "body" : 5,
        ]));
}











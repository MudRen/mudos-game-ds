#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIR"�»�����"NOR, ({ "mala-in pan","pan" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�D��߮Ʋz�������A�Y�_�ӵۿ@�p�����A�o�S�f�P�Q��\n"
                "�����D�Z�A�O�ʶݻ������H���̷R�A�O�@�ة_�S���Ʋz�C\n");
    set("unit","��");
    set("value",2000);
    set("heal_hp",40);
    set("heal_ap",70);
    set("heal_mp",70);
    set("food_remaining",16);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}








#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIW"���S�B��"NOR, ({ "ice crystal","crystal" }));
  set("long",
      "���h�I�t�״I�q���誺�������Ӧ��A�n�Φ��p�o�����Y�j�p���B���A\n"
     +"�ݭn�����~���[�A�����H�������@�ص}�����ħ��C\n"
     );
  set_weight(100);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 1500);
  set("food_remaining",1);
  set("heal_hp",300);  
  set("heal_ap",200);  
  setup();
}

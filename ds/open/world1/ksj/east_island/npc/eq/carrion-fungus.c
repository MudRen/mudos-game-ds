#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(YEL"�ת�"NOR, ({ "carrion fungus","fungus" }));
  set("long",
      "�ͪ���G�פW�������A�@�����o����A���ĮĬ۷�n�A�O���ۤ��@�A\n"
     +"�B���۪ۡB��ۡB��ۡB�ߪۡC\n"
     );
  set_weight(700);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 3000);
  set("food_remaining",2);
  set("heal_hp",300);  
  set("heal_ap",300);
  set("heal_mp",300);    
  setup();
}

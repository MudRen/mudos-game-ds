#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIG"�����ɼY"NOR,({"pan necklace","necklace"}));
  set("long", @LONG  
�o�O�@�������ﮦ�Ҭ諸�ɼY�A�y�����۲�U�A���m���_���ܤۡC
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("value", 6000);
    set("material","gold");
  }
  set("limit_lv",25);
  set("armor_prop/armor", 8);
  set("armor_prop/shield", 8); 
  set("armor_prop/int", 2); 
  set("armor_prop/con", 1); 
  setup();
}



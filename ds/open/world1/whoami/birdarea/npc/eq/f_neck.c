#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(YEL"����"NOR"��",({"fox necklace","necklace"}));
  set("long", @LONG  
�@��Ϊ��W�����Ҧ걵�Ӧ�������A���Ǥ����٨S�˾���A�A�Q
����������_�Ӥ��ӵΪA���m�O�|�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",8+random(4));
  set("armor_prop/shield",8); 
  set("armor_prop/dex",-2);
  set("armor_prop/con",2); 
  set("armor_prop/str",2);
  setup();
}


#include <ansi.h>
#include <armor.h>
inherit WRISTS; 
void create()
{
  set_name(YEL"����"NOR"�ý�",({"fox wrists","wrists"}));
  set("long", @LONG
�@��Ϊ��W�����Y�˦����@�áA�b�@�äW�ٸˤW�F��A�[�j�F��
���O�E���m�O�B�����O�ҷ|�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",6000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/damage",7+random(4));
  set("armor_prop/armor",8+random(4));
  set("armor_prop/shield",6); 
  set("armor_prop/dex",-2); 
  set("armor_prop/str",1);
  setup();
}


#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIW+BLK"��"NOR+YEL"�s"NOR"����",({"crocodile teeth-necklace","necklace"}));
  set("long", @LONG
�@������]�s���������ꦨ������A�C�������O�X�������n�A
�o�إ��ܤѤu����k�u���O�@��H���쪺�E���������z�S�X
�����s�����O�q�E
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",30000);
    set("material","gold");
  }
  set("limit_lv",45);
  set("armor_prop/armor",15);
  set("armor_prop/shield",8); 
  set("armor_prop/dex",-2);
  set("armor_prop/con",2); 
  set("armor_prop/str",-2); 
  set("armor_prop/bar",1); 
  set("armor_prop/sou",-1); 
  setup();
}


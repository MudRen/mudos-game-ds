#include <ansi.h>
#include <armor.h>
inherit HANDS; 
void create()
{
  set_name(YEL"����"NOR"��M",({"fox gloves","gloves"}));
  set("long", @LONG 
�@��Ϊ��W�ְ��X�Ӫ���M�A�Q�����X�n�]�D�`���O�x�E���m�O
�B�����O�ҷ|�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/damage",1+random(4));
  set("armor_prop/armor",12+random(7));
  set("armor_prop/shield",10); 
  set("armor_prop/dex",-2); 
  set("armor_prop/str",1);
  set("armor_prop/con",2);
  setup();
}


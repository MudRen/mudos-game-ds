#include <ansi.h>
#include <armor.h>
inherit BOOTS; 
void create()
{
  set_name(YEL"����"NOR"�u",({"fox boots","boots"}));
  set("long", @LONG 
�@���Ϊ��W���֤򰵥X�Ӫ��u�l�A�N�_�ӤQ���X�n�E���m�O�|�]
�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",4800);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",13+random(6)); 
  set("armor_prop/shield",6+random(4));
  set("armor_prop/dex",2);
  set("armor_prop/int",-1);
  set("armor_prop/con",1);
  setup();
}


#include <ansi.h>
#include <armor.h>
inherit PANTS; 
void create()
{
  set_name(YEL"����"NOR"��",({"fox pants","pants"}));
  set("long", @LONG 
�@���Ϊ��W���֤򰵥X�Ӫ��Ǥl�A�N�_�ӤQ���X�n�E���m�O�|�]
�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1100);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",4500);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",7+random(6)); 
  set("armor_prop/shield",8+random(4));
  set("armor_prop/dex",1);
  set("armor_prop/int",-2);
  setup();
}


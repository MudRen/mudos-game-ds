#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
  set_name(YEL"����"NOR"��",({"fox cloth","cloth"}));
  set("long", @LONG 
�@��γ������W�֩ҧ@�����A���A�N�_�ӤQ�����X�n�A���m�O�|
�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",4000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",14+random(4));
  set("armor_prop/shield",7); 
  set("armor_prop/dex",2);
  setup();
}


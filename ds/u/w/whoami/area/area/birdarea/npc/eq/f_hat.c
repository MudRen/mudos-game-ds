#include <ansi.h>
#include <armor.h>
inherit HEAD;
void create()
{
  set_name(YEL"����"NOR"�U",({"fox hat","hat"}));
  set("long", @LONG
�@��γ������W�֩ҧ@�����U�l�A�N�_�ӤQ�����X�n�A���m�O�|
�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",7000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",7+random(4));
  set("armor_prop/shield",7); 
  set("armor_prop/con",1);
  setup();
}


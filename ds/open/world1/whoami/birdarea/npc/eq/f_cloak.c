#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
void create()
{
  set_name(YEL"����"NOR"�ܭ�",({"fox surcoat","surcoat"}));
  set("long", @LONG   
�@��γ������W�֩һs�����ܭ��A�N�_�ӤQ�����X�n�E���m�O�|
�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",15);
  set("armor_prop/armor",16+random(4));
  set("armor_prop/shield",10); 
  set("armor_prop/dex",2);
  setup();
}


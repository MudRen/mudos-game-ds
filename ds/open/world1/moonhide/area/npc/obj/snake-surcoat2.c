
#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
  set_name( "�j�e�D��" ,({ "hua surcoat","surcoat" }) );
  set("long","�ʦ~�j�D����֡A��w�p�K�A���O���Y�Ф�A�㦳���װj�ײv�P���ˤO�C\n");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("volume",5);
    set("material","golden");
    set("unit", "��" );
    set("value",4000);
  }  
  set("armor_prop/armor", 7); 
  set("armor_prop/dex",2);
  set("armor_prop/dodge",15); 
  setup();
}


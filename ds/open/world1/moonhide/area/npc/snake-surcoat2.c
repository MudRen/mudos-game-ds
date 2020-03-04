
#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
  set_name( "迴疾蛇皮" ,({ "hua surcoat","surcoat" }) );
  set("long","百年大蛇的體皮，堅硬如鐵，但是輕若羽毛，具有高度迴避率與殺傷力。\n");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("volume",5);
    set("material","golden");
    set("unit", "件" );
    set("value",4000);
  }  
  set("armor_prop/armor", 7); 
  set("armor_prop/dex",2);
  set("armor_prop/dodge",15); 
  setup();
}


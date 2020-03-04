#include <armor.h>
inherit SURCOAT;
void create()
{
  set_name("銀狼皮" ,({ "silver-wolf skin","skin" }) );
  set("long","這是從銀狼身上剝下來的皮，經過加工硝製之後，可作為披肩使用，質輕柔軟，是為上品。");
  set_weight(1500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "件");
    set("value",1000);
  }
  set("armor_prop/armor",8);
  set("armor_prop/dex",1);
  set("beast_armor_prop/armor",8);
  set("beast_armor_prop/dex",1);
  setup();
}

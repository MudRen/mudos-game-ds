#include <armor.h>

inherit CLOTH;

void create()
{
set_name("綠晶衣",({"green cloth","cloth"}));
set("long","這是一件淺綠色的精緻布衣。\n");
set_weight(4200);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "件");
set("value",4200);
//set("armor_prop/armor",10);
set("limit_lv",50);
 }
setup();
}

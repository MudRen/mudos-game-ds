#include <armor.h>
inherit CLOTH;
void create()
{
set_name("聖袍",({"holy robe","robe"}));
set("long","(Cloth) 這是一件高級神職人員所穿衣服。\n");
set_weight(7700);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "件");
set("value",7700);
//set("armor_prop/armor",10);
set("limit_lv",70);
 }
setup();
}

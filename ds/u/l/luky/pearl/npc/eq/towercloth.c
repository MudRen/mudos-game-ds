#include <armor.h>
inherit CLOTH;
void create()
{
set_name("瞭望隊制服",({"observer uniform","uniform"}));
set("long","(Cloth) 這是一件瞭望隊隊員執勤時所穿的制式上衣。\n");
set_weight(4400);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "件");
set("value",4400);
//set("armor_prop/armor",10);
set("limit_lv",42);
 }
setup();
}

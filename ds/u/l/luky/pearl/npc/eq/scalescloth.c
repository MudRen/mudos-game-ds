#include <armor.h>
inherit CLOTH;
void create()
{
set_name("蛇鱗背心",({"scales vest","vest"}));
set("long","(Cloth) 這是一件由許多海蛇鱗片所織成的一件背心。\n");
set_weight(3400);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "件");
set("value",4600);
//set("armor_prop/armor",10);
set("limit_lv",45);
 }
setup();
}

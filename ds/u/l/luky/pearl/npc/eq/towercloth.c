#include <armor.h>
inherit CLOTH;
void create()
{
set_name("�A�涤��A",({"observer uniform","uniform"}));
set("long","(Cloth) �o�O�@���A�涤�������ԮɩҬ諸��W��C\n");
set_weight(4400);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "��");
set("value",4400);
//set("armor_prop/armor",10);
set("limit_lv",42);
 }
setup();
}

#include <armor.h>

inherit CLOTH;

void create()
{
set_name("�񴹦�",({"green cloth","cloth"}));
set("long","�o�O�@��L��⪺��o����C\n");
set_weight(4200);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "��");
set("value",4200);
//set("armor_prop/armor",10);
set("limit_lv",50);
 }
setup();
}

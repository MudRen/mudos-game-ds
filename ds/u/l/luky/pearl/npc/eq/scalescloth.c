#include <armor.h>
inherit CLOTH;
void create()
{
set_name("�D��I��",({"scales vest","vest"}));
set("long","(Cloth) �o�O�@��ѳ\�h���D�����´�����@��I�ߡC\n");
set_weight(3400);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "��");
set("value",4600);
//set("armor_prop/armor",10);
set("limit_lv",45);
 }
setup();
}

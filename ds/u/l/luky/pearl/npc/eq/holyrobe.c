#include <armor.h>
inherit CLOTH;
void create()
{
set_name("�t�T",({"holy robe","robe"}));
set("long","(Cloth) �o�O�@�󰪯ů�¾�H���Ҭ��A�C\n");
set_weight(7700);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("material", "cloth");
set("unit", "��");
set("value",7700);
//set("armor_prop/armor",10);
set("limit_lv",70);
 }
setup();
}

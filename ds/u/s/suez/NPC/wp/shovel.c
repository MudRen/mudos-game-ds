#include <weapon.h>
inherit DAGGER;
void create()
{
set_name("小鏟子",({"small shovel","shovel"}));
set_weight(800);
if(clonep())
set_default_object(__FILE__);
set("long","這是專門用來整理盆栽與花草的鏟子。");
set("unit","把");
set("value",50);
set("material","iron");
setup();
init_dagger(1);
}

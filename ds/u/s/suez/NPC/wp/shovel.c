#include <weapon.h>
inherit DAGGER;
void create()
{
set_name("�p��l",({"small shovel","shovel"}));
set_weight(800);
if(clonep())
set_default_object(__FILE__);
set("long","�o�O�M���ΨӾ�z�֮�P�����l�C");
set("unit","��");
set("value",50);
set("material","iron");
setup();
init_dagger(1);
}

#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
    set_name("牛排叉",({"steak fork","fork"}));
    set("long","這把叉子是不鏽鋼做的，雖然很小但是用來叉人也是夠痛的。\n");
    set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
          set("material","steel");
        }
        set("value",210);
        set("weapon_prop/hit",5);
        init_fork(4);
        setup();

}
//可用來背刺
int can_stab()
{
	return 1; 
} 

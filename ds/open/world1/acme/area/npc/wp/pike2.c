#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
    set_name(HIG "錦衣槍"NOR,({"gin yi pike","pike"}));
    set("long","這把槍是朝廷裡尋常禁軍所使用的長槍，為精鋼所煉，威力無窮。\n");
     set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
       set("value",2250);
set("volume",4);
          set("material","iron");
        }
        set("limit_str",12);
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
        init_fork(36);
        setup();
}

#include <weapon.h>
inherit BLADE;

void create()
{
set_name("依賀忍者刀",({"bear blade","blade"}));
        set_weight(5000);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一把為了加快速度給忍者使用而做成的特製刀，比一般武士刀輕，
單手就可很容易舉起來。
LONG);
                set("unit", "把");
                set("material","blade");
        }
        init_blade(20);
        set("value",3000);
set("limit_dex",15);
setup();
}

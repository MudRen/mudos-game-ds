#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create() {
        set_name("鬼叉",({"ghost fork","fork"}));
        set("long",@LONG
透體通黑的鐵叉，是鬼差們喜歡使用的武器。
LONG
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",10);
        set("unit", "把");        
        set("value",200);
        set("volume",4);        
        set("material","iron");       
              }        
        set("weapon_prop/str",1);
        init_fork(40);
        setup();
}    


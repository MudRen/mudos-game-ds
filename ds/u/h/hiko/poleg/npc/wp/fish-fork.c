#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create() {
        set_name("魚叉",({"fish fork","fork"}));
        set("long",@LONG
前端尖銳的魚叉，是漁夫們喜歡使用的捕魚工具。
LONG
);
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",16);
        set("unit", "把");        
        set("value",5000);
        set("volume",4);        
        set("material","iron");       
              }        
        set("weapon_prop/str",2);
        init_fork(42);
        setup();
}


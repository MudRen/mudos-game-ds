#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"魔血"HIW"拳套"NOR,({"blood flame","flame","fist"}));
        set("long",@LONG
上面全都沾滿了惡天妖的血，使得你的殺意也隨之提升。
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",50);
        set("limit_level",26);
        set("unit", "雙");        
        set("value",50000);
        set("volume",2);        
        set("material","steel");       
              }        
        set("weapon_prop/con",1);
        set("weapon_prop/int",-2);
        init_fist(60);
        setup();
}    


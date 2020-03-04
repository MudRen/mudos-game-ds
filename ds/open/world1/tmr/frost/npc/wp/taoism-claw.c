#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit FIST;
inherit F_UNIQUE;

void create() {
        set_name(HIC"天圓"HIG"地方"HIW"爪"NOR,({"taoism claw","claw"}));
        set("long",@LONG
這是一個象徵天圓地方的武器，為寒澈派觀主莫月鼎的隨身武器。
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("unit", "雙");        
                set("value",8500);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/wit", 1);
        set("weapon_prop/int", 2);
        set("weapon_prop/bar", -1);
        set("weapon_prop/hit",10);
        set("beast_weapon_prop/damage",30);
        set("replica_ob",__DIR__"taoism-claw2");
        init_fist(60);
        setup();
}    


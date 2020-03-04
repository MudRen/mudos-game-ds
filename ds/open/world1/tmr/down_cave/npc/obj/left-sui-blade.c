#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("反碎刀", ({ "left sui blade" , "blade"}) );
        set_weight(4500);
        setup_blade( 2 , 8, 60, 6);

        if( !clonep() ) {
                set("wield_as", ({ "secondhand blade" }));
                set("unit", "把");
                set("value", 15000);
                set("rigidity", 60);
                set("long", @long
　　反碎刀的刀身較尋常來的厚實，也頗為沉重，看刀柄的設計是適
合給左手使用的，要是臂力較差的人，還真是很難使用這把重刀。
long
                );
        }
        setup();
}


#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("正嘮刀", ({ "right lao blade" , "blade"}) );
        set_weight(3500);
        setup_blade( 2 , 8, 60, 6);

        if( !clonep() ) {
                set("wield_as", ({ "blade" }));
                set("unit", "把");
                set("value", 15000);
                set("rigidity", 60);
                set("long", @long
　　這是一把造型特殊的單刀，柄上刻著一幅女人正張著嘴的圖案，
好似嘴巴正在不停的講述什麼。刀身刻磨的非常鋒利，隨手揮動數下
，就能聽到刀子畫破空氣的聲響，堪稱好刀一把。
long
                );
        }
        setup();
}


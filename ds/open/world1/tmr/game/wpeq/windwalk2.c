//掌上遊戲第一屆比賽 第五名 windwalk 獎品 -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
          set_name(HIC "風月脛甲" NOR ,({ "wind-moon leggings","leggings"}) );
          set("long",@long
掌上遊戲第一屆比賽 第五名 windwalk 獎品。
    這是用廣寒宮中的稀世珍寶--風晶--所打造而成的，
因此就像風一般的讓你感受不到重量，而且任何力量都無法傷它分毫。
long
);
          set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gem");
                set("unit", "件" );
                set("value",1000);
                set("valme",3);
                set("no_sac",1);
		set("wear_msg","$N穿上了風月脛甲，感到雙腿的移動更加的迅速自在了。\n");
		set("remove_msg","$N脫下了風月脛甲，雙腿又恢復到原本的速度。\n");
                set("armor_prop/armor", 5);
        }
        setup();
}

int query_autoload() { return 1; }

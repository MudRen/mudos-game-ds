//掌上遊戲第一屆比賽 第二名 hcc 獎品 -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIB "龍皇鎧" NOR ,({ "dragon king armor","armor"}) );
        set("long",@long
掌上遊戲第一屆比賽 第二名 hcc 獎品。
  這是一件從古代戰國皇陵所挖掘出來的寶甲。
long
);
            set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件" );
                set("value",1000);
                set("valme",4);
                set("no_sac",1);
                set("armor_prop/armor", 10);
		set("wear_msg","$N穿上一件龍皇鎧,頓時覺得自己彷彿一條龍般的威嚴。\n");
        }
        setup();
}

int query_autoload() { return 1; }

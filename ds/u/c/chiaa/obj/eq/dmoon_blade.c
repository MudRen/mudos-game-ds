//u/c/chiaa/obj/eq/dmoon_blade.c

#include <weapon.h>           //要先include 武器的函數
#include <ansi.h>             //定義色碼
inherit BLADE;

void create()
{
   set_name( CYN "宕" YEL "月" WHT "刀" NOR, ({"dmoon blade","blade"}));
        set_weight(7777);
        if( clonep() )     //系統的參數..設定....
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是傳說中的魔刀,持有他的人必須要
                    得到刀的認同,才能駕馭它。\n");
                set("value",6000);
                set("limit_int",25);  //限制悟性25
                set("material", "steel");  //材質 鋼
                set("wield_msg", "$N抽出一把繫在腰間的$n握在手中,
                    四周的氣氛頓時一沉。\n");
                set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
        }
        init_blade(333);
 set("weapon_prop/blade", 20);       //加 enable 技能10
 set("weapon_prop/force",10);        //加enable 技能 10
        setup();
}

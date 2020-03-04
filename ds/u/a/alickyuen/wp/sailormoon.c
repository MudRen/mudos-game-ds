#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name("變身器", ({ "dunno" }) );
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一個變身器。\n[可儲存裝備]\n");
                set("unit", "件");
                set("material", "silk");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("value",180);
        }
        //============以下片段開放區域勿用, 否則會大混亂===============
        //==    若開放區域要寫此種偽裝eq , 必定要設為 Only One EQ    ==
        set("armor_prop/id",({"sailormoon"}));
        set("armor_prop/name",({"美少女戰士"}));
        set("armor_prop/short",({"美少女戰士 (Sailormoon)"}));
        set("armor_prop/long",({"一個正義勇為的美少女。\n"}));
        //==============================================================
        set("armor_prop/shield",50);
        set("armor_prop/dodge",50);
        set("armor_prop/armor",50);
                set("wear_msg",HIR"$N大叫一聲【變身】, 頓時一股力場環繞$N周圍!突然你身邊出現了一位美少女....."NOR);
                set("remove_msg",GRN"$N突然轉了一圈, 身邊力場漸漸散去.."NOR);
        setup();
}

int query_autoload() { return 1; }

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIC"入雲龍"NOR, ({ "dragon dagger","dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "傳說中這是絕命雙煞的成名武器, 與泣心合稱
雙絕匕,但泣心已不見江湖多年, 剩下的這把入雲龍在匕界之中已可稱王, 你仔
細一看, 刀身微泛藍色, 隱隱帶有寒霜之氣,是一把極為高級的匕首.");
set("value", 30000);
                set("material", "steel");
        }
        init_dagger(40);
set("replica_ob", __DIR__"dagger.c");
 set("weapon_prop/int", 3);
 set("weapon_prop/dex", 2);
 set("weapon_prop/str", -2);
// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N單手握住$n, 霎時一陣寒氣直衝靈堂穴! 。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

// The setup() is required.

        setup();
}


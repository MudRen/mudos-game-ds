#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIR"獸王巨刀"NOR, ({ "animal huge blade","blade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把非常大的巨刀，傳聞為紫陽山頂邪惡領主不離身的寶刀，上頭還帶著一絲血痕。\n");
                set("material", "gold");
                    set("value",8000);
        }
    set("weapon_prop/wit",-1);
    set("weapon_prop/bar",1);
    set("weapon_prop/str",2);
    set("weapon_prop/con",2);
    set("weapon_prop/dex",-1);
    set("weapon_prop/int",-1);

        init_blade(55, TWO_HANDED);

        setup();
}



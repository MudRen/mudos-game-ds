#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("黑瞳死神劍", ({ "DeadGod sword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把散發死神劍氣的鋒利長劍,你不禁產生窒氣的感覺,\n"
                            "是一把天下無雙的寶劍,是黑瞳的專用武器。\n");
                set("value", 95000);
//              set("no_drop",1);
                set("no_sac",1);
                set("material", "steel");
        }
    set("weapon_prop/str",3);
    set("weapon_prop/parry",10);
    set("weapon_prop/hit",5);
    set("weapon_prop/bio",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",1);
    set("weapon_prop/wit",1);
    set("weapon_prop/sou",1);
    init_sword(10);
    setup();
}
int query_autoload() { return 1; }

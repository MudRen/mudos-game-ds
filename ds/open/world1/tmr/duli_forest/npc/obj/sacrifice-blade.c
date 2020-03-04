#include <weapon.h>
#include <ansi.h>

inherit F_BLADE;
inherit F_UNIQUE; // only one

void create()
{
        set_name(HIR "活祭" NOR, ({ "sacrifice blade","blade" }) );
        set_weight(10000);
        setup_blade(4, 11, 120, 10);

        if( !clonep() ) {
                set("wield_as", ({"twohanded blade"}));
                set("unit", "把");
                set("value",50000);
                set("rigidity", 120);
                set("long",@long
這是一把佈滿血跡的長刀，黯黝無光的刀鋒上不時流下一股鮮豔的血
流，而厚重的刀柄，更是被寫滿符文咒術的絲布緊緊包裹著。邪異而駭人
的氣氛正從整柄長刀往四周擴散開來。
long
        );
         set("replica_ob",__DIR__"long-blade");
         set("apply_weapon/twohanded blade", ([
                        "cps":2,
                        "cor":2,
                        "twohanded blade":10,
                        ]));

        }
        setup();
}


#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIW"�ؤ߹�"NOR, ({ "horsetail whisk", "whisk"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 150);
                set("material", "wood");
                set("wield_msg", "$N�u�����q�I���X$n�A���b��W�C\n");
                set("unwield_msg", "$N�N$n���^�I��C\n");
        }
        init_hammer(25);
        setup();
}

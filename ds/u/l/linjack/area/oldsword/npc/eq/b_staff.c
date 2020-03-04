#include <weapon.h>
#include <ansi.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
	set_name("黃銅長杖", ({ "brass cane","cane" }) );
	set_weight(18500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是佛教界最高武僧常常持的一種重型兵器, 十分笨重,\n"
                            "但是若力量夠大可以雙手揮舞此杖傷敵的話, 所造成的強大\n"
                            "傷害力恐怕是難以復元的。\n");
		set("value", 10000);
		set("material", "copper");
		set("limit_skill",50);
		set("limit_str",45);
		set("limit_con",25);
		set("replica_ob",__DIR__"staff");
        }
    set("weapon_prop/dex",-1);
    set("weapon_prop/str",2);
    init_staff(75,TWO_HANDED);
    setup();
}

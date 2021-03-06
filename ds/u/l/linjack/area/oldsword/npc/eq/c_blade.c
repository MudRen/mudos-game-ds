#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name("天刃•雲鋒", ({ "sky cloud blade","blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "此刀奇薄而輕, 但卻十分堅硬, 不知是何種金屬所鑄,\n"
                            "傳言是左宗平親手打造的刀。\n");
		set("value", 20000);
		set("material", "blacksteel");
		set("wield_msg",HIC"$N緩緩從刀鞘中拔出$n。\n"NOR);
		set("unwield_msg",CYN"$N將手中的$n收回刀鞘之中。\n"NOR);
		set("limit_skill",50);
		set("limit_int",15);
		set("limit_dex",25);
                set("replica_ob",__DIR__"c_fist");
	}
    set("weapon_prop/dex",2);
    set("weapon_prop/con",-2);
    set("weapon_prop/int",2);
    set("weapon_prop/str",-2);
    set("weapon_prop/hit",10);
    init_blade(65);
    setup();
}

#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name("白揚木長杖", ({ "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這支長杖是以高級白揚木所製成, 質地堅硬, 厚實耐用, \n"
                            "在攻擊人時有相當的傷害力。\n");
		set("value", 3000);
		set("material", "wood");
		set("limit_skill",30);
		set("limit_str",25);
		set("limit_con",15);
        }
    init_staff(35);
    setup();
}

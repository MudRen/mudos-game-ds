#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
    set_name(MAG"勇者恨無敵"NOR, ({ "Vicch","pike" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "這把爛爛的東西, 看來毫不起眼, 卻又發出令人不可直視的光芒。");
		set("value", 20000);
        set("no_drop",1);
		set("no_sac",1);
		set("material", "gold");
	}
      set("weapon_prop/str",100);
      set("weapon_prop/con",100);
      set("weapon_prop/bar",100);
      set("weapon_prop/hit",100);
      set("weapon_prop/dex",100);
    init_fork(100); 
    setup();
}

int query_autoload() { return 1; }

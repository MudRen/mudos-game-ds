#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("魂元邪刀", ({ "soul-evil blade","blade" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是一把隱藏在影爪魂身體內的邪刀，表面帶有一抹血紅的光澤，有股邪惡的氣息。\n");
                set("volume",10);
                set("value", 8000);
                set("material","iron");
	  }
      set("limit_skill", 40);
      set("weapon_prop/str", 1);
      set("weapon_prop/con", 1);
      init_blade(50);
      setup();
}


#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("無度刀" , ({ "wu do blade","blade" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("limit_str",10);
		set("volume",3);
               set("long", "這是一把全黑的大刀，相當鋒利，但頗為沉重。\n");
          set("value",2250);
               set("material", "iron");
              }
        init_blade(33);
        setup();
}

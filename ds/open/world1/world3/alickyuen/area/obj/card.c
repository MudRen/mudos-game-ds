//updated
inherit ITEM;

void create()
{
          set_name("磁卡", ({ "card" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
                          "一張磁卡，似乎是拿來開鎖用的。\n"
                        );
                set("value", 0);
        }
}

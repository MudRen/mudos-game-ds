#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"金絲漁網"NOR, ({ "gold tackle","tackle" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("value", 3000);
                set("long", "一張用金絲編成的漁網, 想必價值不菲");
                }
        setup();
}

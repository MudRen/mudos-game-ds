#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(HIR"龍"HIY"杖"NOR,({ "dragon staff" , "staff" }));
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", HIW"由古生物"HIM"狡龍點液"HIW"的角所打造出來的絕對利器\n"NOR);

               set("value",9000);
               set("limit_str",22);
               set("limit_con",22);
                set("volume",4);
               set("material", "gold");
        }
init_staff(60);
   setup();
}


#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( "鐵鋤"  ,({"iron hoe","hoe", "_IRON_HOE_"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long",@LONG
這是一把農家常見的鐵鋤，最常用來挖土。
LONG
);
               set("volume",6);
               set("value",100);
               set("material", "iron");
        }
      init_staff(15);
      setup();
}


#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIB"�¤�C"NOR , ({ "black hands sword","sword" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "N.Y.K.�M�νm�߼C�C
\n");
               set("value",1200);
               set("limit_int",3);
                set("volume",4);
               set("material", "gold");
        }
    init_sword(40);
   setup();
}

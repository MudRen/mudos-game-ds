#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "�W�]�C" NOR , ({ "ghost sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�ѤU���C���@�C
\n");
               set("value",1200);
               set("limit_int",3);
                set("volume",4);
               set("material", "copper");
        }
    init_sword(63);
   setup();
}

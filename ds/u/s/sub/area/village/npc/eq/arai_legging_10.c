#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("Arai�@��",({"arai kneecap","kneecap"}) );
        set("long",@LONG
�o�O�@��饻�i�fArai�@���A����۷���w�C
LONG
);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "plastic");
                set("unit", "��");
                set("limit_level",30);
        }
        set("armor_prop/armor",10);
        setup();
        set("value",14000);
        set("volume",6);
}
int query_autoload() { return 1; }

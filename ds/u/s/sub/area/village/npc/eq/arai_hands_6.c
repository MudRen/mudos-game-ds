#include <armor.h>
inherit HANDS;

void create()
{
        set_name("Arai��M",({"arai gloves","gloves"}));
        set("long",@LONG
�o�O�@���饻�i�f��Arai�ɥΤ�M�C
LONG);
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "skin");
                set("limit_level",30);
        }
        set("armor_prop/armor",6);
        setup();
        set("value",4000);
        set("volume", 2);
}
int query_autoload() { return 1; }

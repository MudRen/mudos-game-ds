#include <armor.h>
inherit SHIELD;
void create()
{
        set_name("Arai�@�y",({"arai elbow cap","cap","elbow"}) );
        set("long",@LONG
�o�O�@�Ƥ饻�i�f��Arai�@�y�A�i�H�O�@�ϥΪ̪���y���ܩ����ˡC
LONG);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","wood");
                set("unit", "��");
                set("limit_level",30);
             }
        set("armor_prop/armor",14);
        setup();
        set("value",1600);
        set("volume", 4);
}
int query_autoload() { return 1; }

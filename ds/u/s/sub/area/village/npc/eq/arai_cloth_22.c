#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("Arai�֦�" ,({ "arai cloth","cloth" }) );
        set("long",@LONG
�o�O�@��饻�i�f��Arai�֦�A�W�����U���٧U�Ӫ��ӼСA�D�`����N�C
LONG
);
        set_weight(1200);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material", "skin");
                set("unit", "��");
                set("limit_level",30);
        }
        set("armor_prop/armor",22);
        set("value",19000);
        set("volume",20);
        setup();
}
int query_autoload() { return 1; }

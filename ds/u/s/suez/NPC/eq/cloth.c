#include <armor.h>

inherit CLOTH;

void create()
{
set_name("����",({"cloth"}) );

set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�@�󴶳q������A�L�קA�A���ݡA�����M�u�O\n"
                "�󥬦�A�p�G�A�Q������٥��]�S���H�|�Ϲ諸�C\n"
 );
set("material", "cloth");
set("unit", "��");
set("value",100);

set("armor_prop/armor", 2);

        }
        setup();
}

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("��c" ,({ "shoe" }) );
        set("long","�o�O�@��Ī��s�s����c�A�h�O�X�a�׹D�H�Ҭ諸�C\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
               set("material", "plant");
               set("unit", "��" );
        }
        set("value",150);
        set("armor_prop/armor", 1);
        set("armor_prop/dodge", 2);
        setup();
}

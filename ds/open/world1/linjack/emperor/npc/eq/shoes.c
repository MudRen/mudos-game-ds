#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("���c" ,({ "shoes" }) );
        set("long","���q�H�Ҭ諸�c�l, ��_���ٺ�ξA�C\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,30);
                set("material","cloth");
        }
        set("armor_prop/armor", 1); 
        setup();
}

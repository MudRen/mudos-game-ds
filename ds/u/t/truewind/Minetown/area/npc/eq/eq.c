#include <armor.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name( "�}���A" ,({ "worn-out cloth","cloth" }) );
        set("long",
"�@��}�}���ꪺ��A�A�ݰ_��ż�D�_�ӯ�A�N�_���H�H���A\n"
"�̦n�O���n��...\n"
);
        set_weight(105);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "��" );
        set("value",0);
        set("armor_prop/armor",-5);
        set("armor_prop/dex",-5);
        }
        setup();
}

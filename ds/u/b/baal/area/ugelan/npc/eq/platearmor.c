#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("�Z��",({ "plate armor","armor" }) );
        set("long","�@��H�K���y�Ӧ����Z�ҡA�O�Ԥh�̷R�Ϊ��Գ��˳ơC\n");
        set_weight(20500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
        set("material", "iron");
                set("unit", "��" );
       set("value",2000);
                set("armor_prop/armor", 30);
                        set_temp("apply/armor",7);

        }
        setup();
}


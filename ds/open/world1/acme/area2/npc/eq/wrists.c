#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("�[�a�@��" ,({ "ground wrists","wrists" }) );
        set("long","�o�O���Z���@�k���@�[�a�N�Ҩ������@�áC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_int",10);
        set_weight(5000);
        set("material", "wrists");
        set("unit", "��" );
set("value",1700);
        set_temp("spell/shield",3);
        set("armor_prop/armor", 3);
        set_temp("spell/damage",10);
        set("armor_prop/int",1);
        set("armor_prop/str",-1);
        }
        setup();
}

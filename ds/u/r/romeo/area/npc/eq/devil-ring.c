#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIB "�]�P�C�m��"NOR ,({ "devil-ring","ring" }) );
        set("long","�o�O�@�u�|�I��g�Ϫ��٫��A�Q���G�R�C\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "jade");
        set("unit","�u");
        set("value",700);
        }
         set("armor_prop/armor", 1);
         set("armor_prop/int", 2);
        setup();
}


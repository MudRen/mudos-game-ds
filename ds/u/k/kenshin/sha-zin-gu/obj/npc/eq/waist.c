#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name("�L���y�a" ,({ "wu-shuang waist","waist" }) );
        set("long","�O�����H�a�F�ܵΪA���@�Ӹy�a�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(900);
        set("material", "skin");
        set("unit", "��" );
        set("value",600);
        set("armor_prop/armor",2);          
       set("armor_prop/con",1);
                }
        setup();
}


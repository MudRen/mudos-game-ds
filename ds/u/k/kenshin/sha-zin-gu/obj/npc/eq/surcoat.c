#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("�L���ܭ�" ,({ "wu-jiue surocat","surcoat" }) );
        set("long","�O�����H��F�ܵΪA���@�өܭ��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(900);
        set("material", "skin");
        set("unit", "��" );
        set("value",600);
        set("armor_prop/armor",13);          
        set("armor_prop/dex",1);
                }
        setup();
}


#include <armor.h>
#include <ansi.h>
inherit CLOTH; 
void create()
{
        set_name(HIW"��A"NOR,({ "mourning cloth","cloth" }) );
        set("long","�A��ɩҬ諸��A�A���̤W�_�F�@����Ϊ��ȳ¥��C\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "��" );
        set("value",500);
        set("armor_prop/armor", 2); 
        } 
        setup();
}  
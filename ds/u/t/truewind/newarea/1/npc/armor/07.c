#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name("�³T",({ "black suit","suit" }) );
        set("long","�D�`�K�����¦�T�l�A��۾԰��i�H��[�ӱ��C\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "��" );
        set("value",5000);
        set("armor_prop/armor", 7); 
        set("armor_prop/dex", 3);
        } 
        setup();
}
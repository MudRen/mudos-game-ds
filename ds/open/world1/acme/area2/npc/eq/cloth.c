#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�³T" ,({ "black cloth","cloth" }) );
        set("long","�o�O�@��������³T�A�ᬰ���¡C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("unit", "��");
        set("value",400);
		set("volume",3);
        set("armor_prop/armor", 2);
        }
        setup();
}

#include <armor.h>
#include <ansi2.h>
inherit HEAD;
void create()
{
        set_name("�`�����Y�y", ({"nice's hood","hood" }) );
        set("long", 
"�@����ż���Y�y�A�Y�y�����g�ۡy�`���z�A�W�����@�����������C\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value",100);
        set("material","cloth");
	}
	set("armor_prop/armor",2);
	set("volume",1);
        setup(); 
}
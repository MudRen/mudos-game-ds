#include <armor.h>
inherit HEAD;

void create()
{
	set_name("����",({"steel helmet","helmet"}) );
	set("long",@LONG
�o�������W�����۱K�K�³ª����A�ݰ_�Ӥw�g�ΤF�@�q�ɶ��F�C
LONG);
	set_weight(2970);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "��");
	}
        set("armor_prop/armor",10);
        setup();
        set("value",1800);
        set("volume", 4);
}
//int query_autoload() { return 1; }
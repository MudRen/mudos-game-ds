#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"���A�Ԧ�"NOR ,({ "viper cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
�o�O�ǻ����H���s���֩һs�����ԳT, �i�H���Ѭ۷�}�n�����m�O!
LONG
     );
                set("unit", "��");
	set("value",10000);
                set("material", "steel");
                set("armor_prop/shield",2);
            set("armor_prop/con",2);
                set("armor_prop/armor", 33);
        }
        setup();
}

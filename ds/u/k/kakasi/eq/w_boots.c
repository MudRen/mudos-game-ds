#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"��"HIW"��"HIC"��"NOR, ({ " tiger boots","boots" }) );
        set_weight(2100);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�Ϊ�֩һs���c�l�C");
                set("unit", "��");
        set("value",2100);
                set("material","fur");
         set("armor_prop/dex",3);
        set("armor_prop/con",2);


                set("armor_prop/armor", 6);
        }
        setup();
}

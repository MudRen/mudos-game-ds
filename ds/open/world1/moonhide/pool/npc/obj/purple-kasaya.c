#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIM"��ù�P��"NOR, ({ "purple kasaya","kasaya" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�Y�����ذe���n�c�L�����P��!\n");
                set("unit", "��");
        set("value",5000);
        set("material","fur");
        set("armor_prop/dex",1);
        set("armor_prop/int",1);
        set("armor_prop/dodge",4); 
        set("armor_prop/armor", 27); 
        set("limit_lv",25);
        set("limit_int",40);        }
        setup();
}



#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(GRN"�B���"NOR, ({ "H2 pants","pants" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���ѲB����զ�������Ǥl�C\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1100);          
                set("wear_msg", "��$N��$n��W���ɭ�, $N���ʧ@�n���S��Ǥl�@��\n");
           }
        set("armor_prop/dodge",5);
        set("armor_prop/armor",4);
        setup();
}


#include <armor.h>
#include <ansi.h>
inherit WAIST; 

void create()
{
        set_name(HIW"�ʧ���"NOR, ({ "evil mirror","mirror" }) );
        set_weight(200);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","\n�X�����F����A�]�i������a�P�X���g�����ΡC\n"NOR);
                set("unit", "��");
                set("value",1000);
                set("material","gold");
                set("armor_prop/str",-1);
                set("armor_prop/con",2);
                set("armor_prop/bio",1);
                set("armor_prop/armor", 6);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50); 
                set("limit_int",30);

                set("limit_dex",35);
        }

        setup(); 
}


#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�զ⥬��",({"white cloth","cloth"}) );
        set("long",@long
�@��¥զ⪺����A�ݨӤ�u�ᬰ���W�A���H�@�}�w�Ԫ�����C
long
);
        set_weight(1200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",2);
                set("unit", "��");
                 set("value",2000);
                set("max_lv",50);
                set("limit_lv",25);
                set("armor_prop/int",2);
                set("armor_prop/armor",5);
                set("armor_prop/show_damage",1);
        }
        setup();
}



#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(WHT"�ï]����"NOR,({"june-juw neck","neck"}) );
        set("long",@LONG
�ѳ\�h�����ï]�s��Ӧ�,�ݰ_�Ӭ��[�S�}�G,�S�����m�ĪG.
LONG
);
        set_weight(800); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_lv",20);               
                set("female_only",1);
                set("unit", "��");       
                set("value",4200);          
                set("volume", 4);                       
                set("material", "glass");   
        }
        set("armor_prop/armor",6);       
        set("armor_prop/con",1);
        set("armor_prop/int",1);
        setup();
}


#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("�ೣ�L�Ī����",({"matchless armor","armor"}) );
        set("long",@LONG
�@�������{�{�����ҡA�y�u�����y���A�`�`�l�ޤH���إ��A���L�u�O
��y�~���L�A�L�T��O���������ҡC
LONG
);
        set_weight(5000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",15);
                set("limit_con",15);
                set("unit", "��");       
                set("value",100);          
                set("volume", 3);                       
                set("material", "air");   
        }
        set("monster_armor_type","armor");
        set("monster_armor_prop/armor",32);       
        set("monster_armor_prop/con",3);
        set("monster_armor_prop/shield",18);
        set("armor_prop/armor",30);
        set("armor_prop/shield",18);
        set("armor_prop/con",2);
        setup();
}



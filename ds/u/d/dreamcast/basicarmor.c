#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIM"��"BLK"�v"HIW"�s"HIC"��"NOR,({"dreamcast armor","armor"}) );
        set("long",@LONG
�o�N�ODreamcast���W�諸�@�ҡA�ODreamcast�b�L�j�}�ѮɡA
��v�s���F�A��������Ұ����A�۷��w�E

LONG
);
        set_weight(5000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("armor_prop/armor", 50);
         set("armor_prop/str",2);
                set("unit", "��");       
         set("armor_prop/con",2);
         set("armor_prop/dex",-2);
                set("value",100);          
                set("volume", 3);                       
                set("material", "air");   
        }
        setup();
}


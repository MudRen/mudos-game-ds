#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("�]���l",({"magic bird wing","leggings","wing"}) );
        set("long",@LONG
���]�����ͻH�A�ǻ��N���j�b�}�W����d���C
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",15);
                set("unit", "��");       
                set("value",1100);          
                set("volume", 3);                       
                set("material", "meat");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/dex",2);
        setup();
}


#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name("�K�[�ܭ�",({"ba-chi cloak","cloak"}) );
        set("long",@LONG
�¤������s´���ܭ��A�������@�O�A�O���i�h�o�����~�C
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "��");       
                set("value",900);          
                set("volume", 3);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",15);       
        set("armor_prop/str",2);
        setup();
}



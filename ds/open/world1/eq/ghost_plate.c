#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIB"����"NOR,({"ghost plate","plate"}) );
        set("long",@LONG
�ѥb�~�H�֥H�Φa��֩ҲV�X�s�����w�ֲ������M��F�ǡA�����Ҵ�
�Ѫ����@�O�o�O�L�e�m�ê��C
LONG
);
        set_weight(8000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("limit_con",10);
                set("unit", "��");       
                set("value",1000);          
                set("volume", 4);                       
                set("material", "skin");   
        }
        set("armor_prop/armor",25);       
        set("armor_prop/con",1);
        setup();
}



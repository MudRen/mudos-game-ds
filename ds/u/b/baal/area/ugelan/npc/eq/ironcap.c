#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name("�K��",({"iron cap","cap"}) );
        set("long",@LONG
�ѸG�H��׹B�Ӫ��W�n�K�q�g�ѥ����K�K��y�Ӧ����K
���A�@�եH���N�i�ͪ����l�����˹��A�ݨӯ���L��C
LONG
);
        set_weight(2000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",1500);          
                set("volume", 3);                       
                set("material", "iron");   
        }
        set("armor_prop/armor", 20);
        set("armor_prop/dex",-2);
        setup();
}


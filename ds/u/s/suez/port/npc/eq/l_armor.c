#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("�֥�",({"leather armor","armor"}) );
        set("long","�֭��s��s���A�j�p�u��n�i�H�O�@�ݳ��A�_�I�̪�����ơC\n");
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",500);
                set("volume",3);
                set("armor_prop/armor",7);
        }
        setup();
}


#include <armor.h>
inherit F_UNIQUE;
inherit LEGGING;
void create()
{
        set_name("�Ȥ��H��" ,({ "sky leggings","leggings" }) );
        set("long","�o���H�ҥu�]��j�L�Τp�L���@�p����, �ݨӨ��m�O\n"
                   "�ä���, ���O�ڻ���W�h��}�{�|�֫ܦh�C\n");
        set_weight(4000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,4500);
                set("material","steel");
                set("replica_ob",__DIR__"leggings2");
        }
        set("armor_prop/armor", 7);
        set("armor_prop/shield",4);
        set("armor_prop/dex",2); 
        setup();
}

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("�c�l��" ,({ "pomelo's peel" , "peel" }) );
        set("long","�o�O�@�ӫp�p���c�l�֡A�E�ݤ��U�A�ٯu���@���U�l�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "peel");
        set("unit", "��" );
                set("value",10);
        }
        set("armor_prop/armor", 1);
        set("armor_prop/id",({"strange man","man"}));
        set("armor_prop/name",({"�Y���c�l�֪��ǤH"}));
        set("armor_prop/short",({"�Y���c�l�֪��ǤH(Strange man)"}));
set("armor_prop/long",({"�@���Y���c�l�֪��H�A�A�߸̤��T�Q�_�A�O���O����`�֨�F�C\n"}));
        setup();
} 

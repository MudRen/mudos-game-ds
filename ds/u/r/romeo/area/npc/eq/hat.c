#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIB "�岯" NOR,({ "blood-hat","hat" }) );
        set("long",
"�岯�A���p��W�A����Y���W���O��C�s���C���u�u���A��C
���_�b���W�y�I�C�n���y���ɪ��ˤl�A�ǻ��H�a�W�����Y���c���A
���a�W�����Y���c�]�I�C\n"
);
        set_weight(1900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/str", -1);
        }
        setup();
}


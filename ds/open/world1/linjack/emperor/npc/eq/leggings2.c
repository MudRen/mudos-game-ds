#include <armor.h>
inherit LEGGING;
void create()
{
        set_name("�H��" ,({ "leggings" }) );
        set("long","�o���H�ҥu�]��j�L�Τp�L���@�p����, �ݨӨ��m�O\n"
                   "�ä���, ���O���L�����m���M�����p�����U�C\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,800);
                set("material","iron");
        }
        set("armor_prop/armor", 4);
        set("armor_prop/shield",2);
        setup();
}

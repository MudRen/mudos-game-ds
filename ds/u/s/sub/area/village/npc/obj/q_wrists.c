#include <armor.h>
inherit WRISTS;
void create()
{
        set_name("�ժ�����" ,({ "platinum wrists","platinum","wrists" }) );
        set("long",@LONG
�o�O�@�ӥժ��s���������A�Ȧ⪺���~���H�X�G�L�k�����C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(300);
        set("unit", "��" );
        set("value",5000);
        }
        set("armor_prop/armor", 3);
        set("armor_prop/con", 1);
        set("armor_prop/bar", 2);
        set("armor_prop/str",-1);
        setup();
}

#include <armor.h>
inherit HANDS;
void create()
{
        set_name("���a�@��" ,({ "bi gloves","gloves" }) );
        set("long","�o�O�ʾ]�@�������a�a�Ǫ��@��A���M���~�[���A�����l�������m�ĪG�C");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "skin");
                set("volume",2);
                set("unit", "��");
                set("value",2000);
        }
        set("armor_prop/armor",5);
        set("armor_prop/hit",5);
        set("limit_int",20);
        set("limit_level",15);
        setup();
}


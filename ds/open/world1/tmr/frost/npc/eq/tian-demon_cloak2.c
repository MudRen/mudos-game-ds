#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("�ѧ��潴" ,({ "tian-demon cloak","cloak" }) );
        set("long","�o�O�@��U�c�����u�ѧ��v���ܪ��ѧ��潴�A�潴�W���ɦ���񺯥X�A�ǲ������C");
        set_weight(1200);
        if ( clonep() )
        set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",3);
                set("unit", "��");
                set("value",3500);
        }
        set("limit_con",20);
        set("limit_int",20);
        set("limit_level",25);
        set("armor_prop/armor",15);
        set("armor_prop/str",1);
          set("armor_prop/hit",5);
        setup();
}


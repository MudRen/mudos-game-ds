#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("�饻�Z�h�ԳT" ,({ "japen surcoat","surcoat" }) );
        set("long","�o�O�@��饻�Z�h�̩ҩܪ��ԳT�A�W�����饻��X���ϮסA
                    �����٦��|�Ӻ~�r�u�Z�h�믫�v�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",15);
        set_weight(6000);
        set("material", "skin");
        set("unit", "��" );
       set("value",3250);
        set("armor_prop/armor", 8);
        set_temp("apply/damage",6);
                set("volume",5);
        set("armor_prop/con",1);
        }
        setup();
}


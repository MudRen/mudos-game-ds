#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIC"�O�I�M"NOR ,({ "candom" }) );
        set("long","�o�O�@�u��ƥΪ��O�I�M�A�H���H�Ϋ��C\n");
        set_weight(60);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "waist");
        set("wear_msg","$N���W$n����A���M���@�ѷQ��ƪ��İ�\n");
        set("unit","�u");
        set("value",1000);
        }
         set("armor_prop/armor", 3);
        setup();
}



#include <ansi.h>
#include <armor.h>
inherit HEAD;
void create()
{
        set_name(HIC"�R"HIW"��"HIC"��"NOR,({"sky helmet","helmet"}) );
        set("long",@LONG
�۶ǬO�W�j�ɥN,�Z�ݩ������Y��,ť�����F�i�H�O�j�L�a�C
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                
                set("unit", "��");       
                set("value",0);          
                set("volume", 3);                       
                set("material", "ivory");   
        }
        set("armor_prop/armor", 30);
        set("armor_prop/con",20);
        set("armor_prop/str",20);
        set("armor_prop/dix",20);
        set("armor_prop/int",20);
        set("wear_msg",
HIR"$N���W$n"HIG"����"HIY"�������O��"HIM"���M�ܤj\n"NOR);
        set("unequip_msg", HIW"$N���U$n"HIW"��A�O���ܤp�F�C\n"NOR);
        setup();
}
int query_autoload() { return 1; }


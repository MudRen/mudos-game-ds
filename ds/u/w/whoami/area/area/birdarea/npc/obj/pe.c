#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"�E"HIY"��"NOR"����"NOR,({ "fox fur","fur" }));
        set_weight(1500);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@�i�q�E�����W�渨���֡A�A���b��W�������P��ǳ\\���]�O�E\n");
                set("unit","�i");
                set("value",1000);
                } 
                set("armor_prop/shield",1);
                set("armor_prop/armor", 5);
                set("wear_msg", "$N��W�@�i$n�A����P���J�L�a���O�q�I\n");
                set("unequip_msg", "$N��U�F$n�A�O�q�y�ɥ����y���F�I\n");
                set("armor_prop/wit",1);
                set("armor_prop/bar",-1);
                set("armor_prop/int",2+random(2));
                setup();
}


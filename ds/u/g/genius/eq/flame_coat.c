#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(RED"��K�k�T"NOR,({"dark flame coat","coat","surcoat"}) );
        set("long",@LONG
�o�O�@��t���⪺�j�k�v�T�A�~�������i�H�ݨ�@�Ӥ��K�Ϊ����Ǧ�
�аO�CXXXXXXXXXXXXXXX(��L�ԭz)
LONG
);
        set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("limit_con",3);
                set("armor_prop/dodge", 5);
                set("armor_prop/armor", 15);
                set("armor_prop/shield",40);
                set("armor_prop/int",3);
                set("value",5432);
        }
      set("wear_msg", RED"$N�ܤW$n"RED"�A�y�ɮ�^�ܪ��Q�����I�C\n"NOR);
      set("unequip_msg",CYN"$N�N"RED"$n"CYN"��F�U�ӡA��_�F���`�����A�C\n"NOR);
      setup();
}   
int query_autoload() { return 1; }

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"����x"NOR, ({ "blood-snake liver","liver" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��몺�x�n�A�i���������A�ε�����[�����i Max_Hp]�C\n");
                set("unit", "��");
                set("value", 4500);  
                set("food_remaining",1);
                set("heal_hp",3000);//����   
        }
}


// dumpling.c

inherit ITEM;
#include <ansi.h>

inherit F_PILL;

void create()
{
        set_name(HIB"�Ŧ�p�ĤY"NOR, ({ "blue pill","pill" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@���Ŧ⪺�p�ĤY�A���G��W�j�Y�د�O�C\n");
                set("unit", "��");
                set("value", 300);       
                set("heal_ap",30);      
                set("heal_body",10);    
                set("heal_head",10);    
                set("eat_msg","$N�Y�F�@��$n�H��, ���@�ѷQ�n�o��������C");
                set("eff_msg","�Aı�o���O�W�j�F���֡C");
        }
        setup();
}

// dumpling.c
#include <ansi.h> 
inherit ITEM;
inherit F_PILL;

void create()
{
           set_name("�������˾�",({"better medicine","medicine"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1000);
                set("eat_msg",HIB"$N�N$n�@�Ѹ����˶i�L�ڸ̡C"NOR);
                set("eff_msg",HIW"�A�����饿�b"HIY"�ֳt�^�_"HIW"���I"NOR);
}
                 set("heal",([
                  "ap":500,
                  "hp":500,
                  "mp":500,
]));
}

#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIG"�۬h����"NOR, ({ "xiangliu pill","pill" }));
        set("long",@LONG
���~  �۬h�������A���o�X�@�P������A�Y�F���U�˶ժ��^�_�C
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg",HIW"$N�Y�U�@�����o���𪺤����C"NOR);
                set("eff_msg",HIG "�@�}��������~�q�A���W�o�X....\n" 
                                     + NOR CYN "(�Aı�����骬�A�n�F�@�ǡI�I)"NOR );
        }
        set("value", 3000);
        set("cure",([
                "body" : 5,
                "head" : 5,
                "left_leg" : 3,
                "right_leg" : 3,
                "left_arm" : 3,
                "right_arm" : 3,
        ]));
        set("heal",([
                "hp"    : 500,
                "mp"    : 200,
                "ap"    : 200,
        ]));
        setup();
}


#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"�Ѻ���C"NOR,({"green sword","greensword","sword"}));
        set("unit", "��");
        set("long",@LONG
�@��Ѻ�⪺���C�A�C�������J�a�O���ܨS�`�C�p�G�A�V���@��
��ë(pray)���ܡA�����w�|���ƻ�_�����Ʊ��o�͡C

LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="green sword" && arg!="greensword" && arg!="sword" )
        {
                notify_fail("�A�n�擄��ë�i?\n");
                return 0;
        }

                message_vision(HIG"$N�ۤߪ��V�Ѻ����C��ë�A�@���Ѻ�⪺���~��¶��$N�C\n"NOR,me);
        return 1;
}


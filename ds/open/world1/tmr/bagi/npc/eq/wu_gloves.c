#include <armor.h>
#include <ansi.h>

inherit F_UNIQUE; //only one
inherit HANDS;

void create()
{
        set_name(HIY"���"HIC"�@�P��" NOR ,({ "sun-moon gloves","gloves" }) );
        set("long",@LONG
�o�O�@���y���D�`�I�����䪺�@��A�o���@��W¸���@�T�u�����P�v
�����u�ϡA¸�u����A����o�T���Hø�s���ϵo����ɵ��ɬ��B�g���[��
���ҬɡA�u�i�׬O���ܤѤu�]�����L�C
�b�A�ӲӪ��઱���ڡA���M�o�{¸�ϤW���@�p��r�G
        �u�ѳ��a���A�饿��ϡA�E�M����A�`�~�䤤�v
���G�b���ܧA�i�H�H��������A�����E�M����H(powerin)(regenerate)
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",2500);
                                set("replica_ob",__DIR__"wu_gloves2");
        }
                set("power",0);
        set("armor_prop/armor",8);
        set("armor_prop/dex",1);
        set("armor_prop/con",1);
        setup();
}

/* ��AP �S��\�� */
void init()
{
        add_action("do_powerin","powerin");
        add_action("do_regenerate","regenerate");
}

int do_powerin(string arg)
{
        object me=this_player();
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�S���Ű��o�ʧ@�C\n");
        if(me->query("hp")<query("max_hp")/2)
                return notify_fail("�A�ثe�����骬�A�ä��n�C\n");
        if(me->query("level")<20)
                return notify_fail("�A���⪺���šA�L�k�����ʧ@�C\n");
        if( me->query_temp("armor/hands")!=this_object() )
                return notify_fail("�A�����n����_�ӡA�~���γB�C\n");
        if(query("power")>=100)
                return notify_fail("�A�Pı���@�⪺��q�Q���R���C\n");
        if(me->query("gender")=="�k��")
                message_vision(HIY "$N��ۤ���@�P��ӲӦa�R�X�@�f����A����@�}��¶����A�Q�@��l�F�i�h�C\n" NOR,me);
        else
                message_vision(HIB "$N��ۤ���@�P��ӲӦa�R�X�@�f����A����@�}��¶����A�Q�@��l�F�i�h�C\n" NOR,me);
        me->start_busy(3);
        me->receive_damage("hp",(1+random(4))*10);
        add("power",me->query("level"));
        return 1;
}

int do_regenerate(string arg)
{
        object me=this_player();
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��o�ʧ@�C\n");
        if(me->query("level")<20)
                return notify_fail("�A���⪺���šA�L�k�����ʧ@�C\n");
        if( me->query_temp("armor/hands")!=this_object() )
                return notify_fail("�A�����n����_�ӡA�~���γB�C\n");
        if(!query("power"))
                return notify_fail("�@��W����q�w�g�����F�A�A�L�k�A�ϥΦ��\\��F�C\n");
        message_vision(HIB "$N���W���@���j���X�@�ѩ��N�����������A�w�w�a�]��F$N������C\n" NOR,me);
        tell_object(me,CYN "(�A�餺�����l��_���֤F�C)\n" NOR);
        me->receive_heal("ap",query("power")*3);
        set("power",0);
        me->start_busy(3);
        return 1;
}



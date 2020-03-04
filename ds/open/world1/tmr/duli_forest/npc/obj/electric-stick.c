#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�q����",({"electric shock stick","stick" }) );
    set("long",@LONG
�o�O�@�K�y�����K�y���q���ΡA���M�u�p�A���O�`�H�n�O�Q����
�i�r���q�O��Ĳ��A�Q�����]���C�q���έI��K�ۤ@�p�i���ϥΤ�k
�A�W���g�ۡG
                �q        ��   shock
                �վ�q�O�j�p   adjust
�ӤW�Y���q�O�j�p�վ�b�G
LONG
        );
        if(!clonep() )
        {
                set("value",12000);
                set("unit","�K");
        }
        set("electric",1000);   //�q�O
        set("adjust","low");            //�C���q�O
        set("long",query("long")+query("adjust")+"\n");
        setup();
}

void init()
{
        add_action("do_shock","shock");
        add_action("do_adjust","adjust");
}

int do_shock(string arg)
{
        object me,target;
        me=this_player();
        if(!arg) return notify_fail("�A�n�q���֩O�H�H\n");
        target=present(arg,environment(me));
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��o�ʧ@�C\n");
        if(!objectp(target) )
                return notify_fail("�o����S���o�ӪF��C\n");
        if(userp(target) && target!=me )
                return notify_fail("�A������L���a�X��C\n");
        if(query("electric") <= 0)
                return notify_fail("�o�K�q���Τw�g�Υ��q�O�F�C\n");
        if(target==me) {
                if( me->query_stat("hp") < 50)
                        return notify_fail("�A���ͩR���M�A�L�k���o�ئM�I���ʧ@�C\n");
                if( me->query_stat("nina") < 50)
                        return notify_fail("�A�餺�����O�����A�����ʧ@�|�޵o�ͩR�M�I�C\n");
                message_vision("$N���_�⤤���q���Ω��ۤw���W�@�W...\n",me);
                switch(query("adjust") )
                {
                        case "high":
                                message_vision(HIB "�@�}�J����q$N���W�ǤF�X��.....\n" NOR,me);
                                add("electric",-(10*random(3)));
                                /* ��-�q�ʩ��O �ޯ�g��*/
                                if( me->query_learn("electric nina") ) {
                                        me->improve_skill("electric nina",2+random(me->query_attr("int")));
                                        me->improve_skill("psychical",random(3) );
                                }
                                me->consume_stat("hp",10);
                                me->start_busy(1);
                                break;
                        case "middle":
                                message_vision(HIB "$N�T����D�u�F�@�n�A���G�Q�q�h�F.....\n" NOR,me);
                                add("electric",-(5*random(3)));
                                /* ��-�q�ʩ��O �ޯ�g��*/
                                if( me->query_learn("electric nina") ) {
                                        me->improve_skill("electric nina",1+random(me->query_attr("int")/2));
                                                me->improve_skill("psychical",random(3) );
                                }
                                me->consume_stat("hp",5);
                                me->start_busy(1);
                                break;
                        case "low":
                                message_vision(HIB "$N�y�W�@�}�C�@�}�աA���G���I���ԭ@�Q�q���Pı....\n" NOR,me);
                                add("electric",-(3*random(3)));
                                /* ��-�q�ʩ��O �ޯ�g��*/
                                if( me->query_learn("electric nina") ) {
                                        me->improve_skill("electric nina",1+random(5));
                                        me->improve_skill("psychical",random(3) );
                                }
                                me->consume_stat("hp",2);
                                me->start_busy(1);
                                break;
                }
        } else {
                return notify_fail("�ثe���}�������L�H���欰�C\n");
        }
        return 1;
}

int do_adjust(string arg)
{

        if(!arg)
                return notify_fail("�A�n�վ�q�O�j�p��h�֩O�H(high,middle,low )\n");
        switch(arg)
        {
                case "high":
                        set("adjust","high");
                        return notify_fail("�A�N�q���ΤW���q�O�j�p�վ�ܡu���q�O�v����m�C\n");
                        break;
                case "middle":
                        set("adjust","middle");
                        return notify_fail("�A�N�q���ΤW���q�O�j�p�վ�ܡu���q�O�v����m�C\n");
                        break;
                case "low":
                        set("adjust","low");
                        return notify_fail("�A�N�q���ΤW���q�O�j�p�վ�ܡu�C�q�O�v����m�C\n");
                        break;
                default:
                return notify_fail("�A�n�վ�q�O�j�p��h�֩O�H(high,middle,low )\n");
        }
}




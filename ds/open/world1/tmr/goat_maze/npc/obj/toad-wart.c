#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "�����" , ({ "toad wart", "wart" }));
        set("long",@LONG
�o�O�@�ɱq��������W���U�Ӫ��СA�]�еۤ@�b�c�ߪ��r�ġA����
�Y�b�L�̷|�O��˴����C
LONG
        );
        set("weight",50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("value",1);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env;
        me = this_player();
        ob = this_object();
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
        if( ob->query("do_eat") )
                return notify_fail("�A�w�g�t�b�L�̤F�C\n");
        if(me->query_temp("toad_wart_used") )
                return notify_fail("�A�L�̥��t�۪F��A����A��F��i�h�F�C\n");
        if( me->is_fighting() ) me->start_busy(2);
         message_vision(CYN "$N���X�F�@������СA�t�b�L�̤����a�l�m���Y���r��...\n" NOR,me);

        if(!ob->query("toad_wart_used") && !me->query_temp("toad_wart_used") )
        {
                message_vision( HBK "$N�y�W�y�ɳQ�®�Ţ�n�A���o�O�V���믫�����A�@�L�f�A�I�I\n" NOR,me);
                me->add_temp("apply/int", 2);
                me->add_temp("apply/con", 2);
                me->set_temp("toad_wart_used",1);
                ob->set("toad_wart_used",1);
                ob->set("do_eat",1);
                ob->set("no_drop",1);
                ob->set("no_sac",1);
                ob->set("no_give",1);
                ob->set("no_sell",1);
                call_out("delay", 600,me);     //���[�ݩʺ����ɶ�
        }
        return 1;
}

void delay(object me)
{
        if(!me) return;
        message_vision(CYN"$N�B�P�@�n�A���G�]�U�F����F��....\n" NOR,me);
        me->add_temp("apply/int",-2);
        me->add_temp("apply/con",-2);
        me->delete_temp("toad_wart_used");
        destruct(this_object());
}



#include <ansi.h>
#define BASIC 3

inherit SKILL;
inherit SSERVER;

int do_perform(object *obj);

string *attck_msg = ({
                         "$N�@�n���S�A���s�K�x��V$n�I�I\n",
                     });

string *start_msg = ({
                         HIW   "���Ѧ쪺$N�ǳƵo�ʧ�աI�I\n" NOR,
                         HIY   "���a�쪺$N�ǳƵo�ʧ�աI�I\n" NOR,
                         HIC   "���H�쪺$N�ǳƵo�ʧ�աI�I\n" NOR,
                     });


int form_array(object me)
{
    int i,j;
    object *t,ob,env;
    object *ct=({});

    if(!me) me=this_player();
    //�԰����}�k
    //      if(!me->is_fighting() )
    //              return notify_fail("�A�èS���b�԰��A�L�k�ϥγo�Ӱ}�k�C\n");

    if(me->is_busy() )
        return notify_fail("�A�����ۡA�S�ŧG�}�C\n");
    t=me->query_team();
    env=environment(me);

    //�qteam ���A��X�i�H�ϥΰ}�k���H��
    //���Y��b���]�n����C
    for (i=0;i<sizeof(t);i++)
    {
        ob=t[i];
        if( sizeof(ct)==BASIC ) break;
        if( !ob ) continue;
        if( ob->is_busy() ) continue;
        if( env != environment(ob) ) continue;

        /*
        if( !ob->is_fighting() ) continue;
        if( !ob->query_skill("seven-star") ) continue;
        if( ob->query("ap") < 200 || ob->query("hp") < 200 ) continue;
        */

        ct += ({ob});
        //          if(wizardp(me) ) write( ob->query("name")+"("+ob->query("id")+")\n");
    }

    if(sizeof(ct) < BASIC)  return notify_fail("�A�S�����������ͯ�ϥγo�Ӱ}�k�C\n");
    else                    do_perform(ct); //�޵o�}�k
    return 1;
}

int do_perform(object *ct)
{
    object ob,target;
    int i,damage,jj;

    target = offensive_target(ct[0]);
    if(!target)
        return notify_fail("�A�䤣��ĤH�C\n");

    message_vision(HIG "\n$N������X�F�԰�A���n���S�G�u�G�y�Ѧa�H�T�~�}�z�I�I�v\n" NOR,ct[0]);
    message_vision("$N���T�H�H�����ѡB�a�B�H�T��I�I\n",ct[0]);

    for(jj=0;jj<3;jj++)        {

        for (i=0;i<sizeof(ct);i++)        {
            ob=ct[i];
            message_vision(start_msg[i],ob);
            if(!ob->can_fight(target) )     {
                message_vision(CYN"$N���Τ@���A��Ӱ}�k���F�U�ӡC\n"NOR,ob);
                return 1;
            }
            ob->attack();
            if(!ob->is_fighting(target) )
                ob->kill_ob(target);
            if(!target->is_fighting(ob) )
                target->kill_ob(ob);
        }
        message_vision(CYN"$N���S�@�n�A�}�k�~���X�ʵۡI�I\n"NOR,ct[0]);
    }
    return 1;
}


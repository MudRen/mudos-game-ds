#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 HIR"\n��M$n�����������X����A�����N�@��A�~��$N�����a��$n�C\n"NOR,
 "\n$n��M���I�ᴡ�F���ͻH�@�˪����ʨ��t�A��$N�L�q�����_�C\n",
 "\n$n��M���k���몺��İ_�ӡA��$N�������ɶ��j�áA�]���׹L���ۡC\n",
 "\n$n���W�����A�����Q�۽�ۼΰ}�����ΡA�}�]��_�ۼΰ}���A��$N�L�q�U��C\n",
 "\n$n���}�@�ޡA���ĤW�ѡA�@��"+HIC+"�i��}�����j"+NOR+"�}�G�����b$N����C\n",
 "\n��M$n�}�B�ܻ��A�@��"+HIM+"�i�Ͼ��k�u�j"+NOR+"�A�b$N����դ��C���|��C\n",
 "\n��M$n��C�F�}�B�A���i���h�A��$N�����N�����Y���C\n",
 "\n�٨����A$n�������o�X���˪����~�A�ʧ@�񥭱`�n�֤W�ƭ��A��$N�����I����$n�@�ڴH��C\n",
});

int exert(object me, object target, string arg)
{
        string msg;

        int temp = me->query_skill("bird-eight"),
            temp2 = me->query_temp("bird/temp");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="bird-eight")
                        return notify_fail("�A�èS���ϥΡy�F�l�K�B�Z�z�C\n");
                me->map_skill("dodge");
                me->reset_action();
                me->add_temp("apply/dodge",- temp2);
                me->delete_temp("bird/temp");
                message_vision("\n"CYN"$N�C�C�������ର���`���C��C\n"NOR,me);
                write("�ޯ�y�F�l�K�B�Z�z�w�����C\n");
                return 1;
        }

        if(me->query_skill("dodge")<20) 
                return notify_fail("�H�A�����\\��¦�L�k�ϥΡy�F�l�K�B�Z�z�C\n");

        //��1. if(me->query_skill_mapped("dodge")=="mirage-steps")
        if(me->query_skill_mapped("dodge")=="bird-eight")  //luky��
                return notify_fail("�A�w�g�b�ϥΡy�F�l�K�B�Z�z�C\n");

        if(me->query("ap")<50 || me->query("hp")<50)
                return notify_fail("�A�����骬�L�k�ϥΡy�F�l�K�B�Z�z�C\n");

        if(!me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10))
          return notify_fail("�A���F�l�K�B�Z���۰ʧ@�٨S�����C\n");

        // ��2. me->map_skill("dodge", "mirage-steps");
        me->map_skill("dodge", "bird-eight"); //luky ��
        me->reset_action();
        me->add_temp("apply/dodge",temp);
        me->set_temp("bird/temp",temp);
        
message_vision("\n"HIR"$N��������M�ର�����A�����ĤH���@�|�@�ʡA�ǳƨϥX�ǻ������y�F�l�K�B�Z�z�C\n"NOR,me);
        me->receive_damage("ap",2);
        me->start_busy(1);
        //��3. call_out("delay",10,me);
        return 1;
}

void delay(object me)
{
        int temp = me->query_temp("bird/temp");
        if(!me) return;
        
        if(me->query_skill_mapped("dodge")!="bird-eight")
        {
                //�K. remove_call_out("delay");
                 return;
        }   
        
        if(me->query("ap")<10)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N������������_�����`�C��F�C\n"NOR,me);
                me->add_temp("apply/dodge",- temp);
                me->delete_temp("bird/temp");
                tell_object(me,"�A����O�����L�k�~��ϥ��F�l�K�B�Z�C\n");
                //�K. remove_call_out("delay");
                return ;
        }
        if ( me->is_fighting() ) me->receive_damage("ap",2); //�S�[�԰��P�_
        //��. call_out("delay",10,me);
        me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }

string query_dodge_msg(string limb, object target, object me)
{
        int sk,dex,tdex,tlv;
        tlv  = target->query("level");
        tdex = target->query("dex");
        sk   = me->query_skill("bird-eight");
        dex   = me->query("dex"); 
        return dodge_msg[random(sizeof(dodge_msg))];
        if (random( dex - tdex > tlv ))
        tell_object(target,"�A�]���L�ֳt�����k�ϧA���������h�F�`���E\n");
        target->start_busy(random(dex/70+sk/100));
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob) 
{
        int a;
        a=ob->query_dex()+ob->query_int()+40;
        if(a>100) a=100;
        return a;
}


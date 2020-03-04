// ��s���: 2003.06.15	�ק�H: Shengsan@DS �ק�N��: sV1 -->�ק� fogseven + dodge �Ҧ������
// fogseven.c �g�ۤC�B�Z ( editor date �ѤF )
// update time: 10, Sept., 2000.
// last update: 11, Sept., 2000. --> ��_ fogseven + dodge
#include <ansi.h>
inherit SKILL;

void remove_add_dodge(object me);

string *dodge_msg = ({
                         HIM"$n�H�a���F�@���A���M��$N���������Y�L�@���{�F�L�h�C\n"NOR,
                         HIM"$n�θ}�����F�@�U�}�y�A�j�s�F�@�n�z�A���۴N�����b$N���e�C\n"NOR,
                         HIM"$n�L�Lť��$N���Z����ӡA�����N���W�N���F�_�ӡC\n"NOR,
                         HIM"$N�@��V$n�A���G$n�q�I�᮳�X�@���K��A���۴N���a�W���}�k���F�C\n"NOR,
                         HIM"$n�����M�ĥX�@��H�A��$n���m���F�C\n"NOR,
                         HIM"$n���O�@���A���بϤ߲��ݡA��$N�������������F�_�ӡC\n"NOR,
                         HIM"$n���p���F�@��A���P�����L�F$N�������C\n"NOR,
                         HIR"$n��M�ϥX�@�ۥɨ߰{�����@�|�{�L�ĤH���r�P����\n"NOR,
                         HIR"$n��M�ϥX�G�۰{�F�Z�����ƪ��{�L�ĤH���������C\n"NOR,
                         HIR"$n���@���ϥX�T�۽������H�ۼĤH�������ϧ������O�Ʃ�G�Ǥ����жˡC\n"NOR,
                         HIR"$n���E���W���O, �ϥX�|�۳n���\\�n���������h�ĤH������,�l��O�����v�O,�{�L�����C\n"NOR,
                         HIR"$n���A��,�ϥX���۹P�a�ϱo�ĤH�@�ɤ����ұ�,�X���׹L�@���C\n"NOR,
                         HIR"$n�𯫤w��,���E��,�ϥX���ۺR�v�N�ϱo�ĤH��ɸ����@�ɲV�P,�׶}�����C\n"NOR,
                         HIR"$n���E���,�ϥX�g�ۤC�B�Z�̤W�h�ۼv�B�Z,��M�ۼv�ƤQ,�ϱo�ĤH�J�ç���,�k�L�����C\n"NOR,
                     });

string *dodge_msg_high = ({
                              HIB"$n�}��K�����椧���A��$N�m�����z�C\n"NOR,
                              HIB"$n�@�}��W�K���W���L�k��A�p����몺�f���C\n"NOR,
                              HIB"$n�o�ۨ��۪��A�L�ƫo���L�F$N�������C\n"NOR,
                              HIB"$n�f�������D�G�L�k����....�A�H�ۤf�����X�Ө��C\n"NOR,
                              HIB"$n��}��U�šA�p�O�̷ө����g�W�몺���סC\n"NOR,
                              HIR"$n���E���,�ϥX�g�ۤC�B�Z�̤W�h�ۼv�B�Z,��M�ۼv�ƤQ,�ϱo�ĤH�J�ç���,�k�L�����C\n"NOR,
                          });

int exert(object me, object target, string arg)
{
    int tmp;

    if ( arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="fogseven")
            return notify_fail("�A�èS���ϥΰg�ۤC�B�Z�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
        remove_add_dodge(me);
        write("�����ϥΧޯ� - �{�פ��ްg�ۤC�B�Z�C\n");
        return 1;
    }

    if( me->query_skill("dodge") < 5 )
        return notify_fail("�A�����\\��¦�����L�k�ϥΰg�ۤC�B�Z�C\n");

if( !me->skill_active("fogseven", (: call_other, __FILE__, "delay", me :), 12) )
        return notify_fail("�A���b�ϥΰg�ۤC�B�Z�C\n");

    if( me->query("ap") < 10 )
        return notify_fail("�A������ثe���p�ٵL�k�ϥΰg�ۤC�B�Z�C\n");

    me->map_skill("dodge","fogseven");
    me->reset_action();

    message_vision("\n"HIB"�@�n�������ݮ��n�A$N��|�e���𶰾¤��A�߷N�|���A�Τߥh��|�g�ۤC�B�Z���u�q�C\n"NOR,me);
    me->receive_damage("ap", 1);
    me->start_busy(1);
    if( me->query_temp("class_wind/fogseven_dodge") )
        remove_add_dodge(me);
    //sV1 me->add_temp("apply/sk_dodge", (tmp = me->query_skill("fogseven", 1)*2/5 + me->query_skill("dodge", 1)/5 + random(me->query_skill("dodge",1)/4)));
    me->add_temp("apply/sk_dodge", (tmp = me->query_skill("fogseven", 1)*2/5 + random(me->query_skill("dodge",1)/10)));//sV1
    me->set_temp("class_wind/fogseven_dodge", tmp);
    //	me->skill_active("fogseven", (: call_other, __FILE__, "delay", me :), 12);
    return 1;
}

void delay(object me)
{
    if( !me ) return;

    if( me->query_skill_mapped("dodge")!="fogseven" )
    {
        remove_call_out("delay");
        remove_add_dodge(me);
        return;
    }

    if( me->query("ap")<10 )
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�S�^�_��F�@�몺�t�סC\n"NOR,me);
        tell_object(me,"�A�������w�áA�w�L�k�A�ϥΰg�ۤC�B�Z�C\n");
        remove_add_dodge(me);
        remove_call_out("delay");
        return ;
    }

    if( me->is_fighting()  )
    {
        if( (me->query_skill("fogseven") + me->query_skill("dodge") - 30) > 1 ) me->receive_damage("ap", 1);
        else me->receive_damage("ap", 2);
    }
me->skill_active("fogseven",(: call_other, __FILE__, "delay", me :), 10);
}

void remove_add_dodge(object me)
{
    int ar1 = (int)me->query_temp("class_wind/fogseven_dodge");

    if( ar1 < 0 ) return;
    me->add_temp("apply/sk_dodge", -ar1);

    me->delete_temp("class_wind/fogseven_dodge");
    return;
}

string query_dodge_msg(string limb)
{
    if( this_player()->query_skill("fogseven") == 100 )
        return dodge_msg[random(sizeof(dodge_msg))];
    else return dodge_msg_high[random(sizeof(dodge_msg_high))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob) { return 100; }
int valid_learn(object me) { return 1; }

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
                         HIM"$n�H�a���F�@���A���M��$N���������Y�L�@���{�F�L�h�C\n"NOR,
                         HIM"$n�θ}�����F�@�U�}�y�A�j�s�F�@�n�z�A���۴N�����b$N���e�C\n"NOR,
                         HIM"$n�L�Lť��$N���Z����ӡA�����N���W�N���F�_�ӡC\n"NOR,
                         HIM"$N�@��V$n�A���G$n�q�I�᮳�X�@���K��A���۴N���a�W���}�k���F�C\n"NOR,
                         HIM"$n�����M�ĥX�@��H�A��$n���m���F�C\n"NOR,
                         HIM"$n���O�@���A���بϤ߲��ݡA��$N�������������F�_�ӡC\n"NOR,
                         HIM"$n���p���F�@��A���P�����L�F$N�������C\n"NOR,
                     });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="heart_dodge")
            return notify_fail("�A�èS���ϥΡ��[¤�e�߸}���C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
        write("�����ϥΧޯ�-�{�פ��ޡ��[¤�e�߸}���C\n");
        return 1;
    }
    if(me->query_skill("dodge")<20)
        return notify_fail("�A�����\\��¦�����L�k�ϥΡ��[¤�e�߸}���C\n");
    if(me->query_skill_mapped("dodge")=="heart_dodge")
        return notify_fail("�A���b�ϥΡ��[¤�e�߸}���C\n");
    if(me->query("mp")<10 || me->query("hp")<10)
        return notify_fail("�A������ثe���p�ٵL�k�ϥΡ��[¤�e�߸}���C\n");
    me->map_skill("dodge","heart_dodge");
    me->reset_action();

    message_vision("\n"HIB"�@�n�������ݮ��n�A$N��|�e���𶰾¤��A�߷N�|���A�Τߥh��|���[¤�e�߸}�����u�q�C\n"NOR,me);
    me->receive_damage("mp", 3);
    me->start_busy(1);
me->start_call_out( (: call_other, __FILE__, "delay", me , 3 :), 10);
    return 1;
}

void delay(object me,int cost)
{
    int heart,dodge,a;
    heart=me->query_skill("heart_dodge")-30;
    dodge=me->query_skill("dodge")-30;
    a=heart+dodge;
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="heart_dodge")
    {
        return;
    }
    if(me->query("mp")<10)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�S�^�_��F�@�몺�t�סC\n"NOR,me);
        tell_object(me,"�A�������w�áA�w�L�k�A�ϥΡ��[¤�e�߸}���C\n");
        return ;
    }
    if( a>1 )a=1;
    if( a<0 )a=0;
    me->receive_damage("mp", a);
me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }

// �ԻR(combat dance)

#include <ansi.h>

inherit SKILL;
string type() { return "knowledge"; }

int exert(object me,object target, string arg)
{
    if( arg == "off" ) {
        message_vision("$N������ԻR�F�C\n",me);
        me->delete_temp("is_busy/CombatDance");
        return 1;
    }

    if( me->query_condition("CombatDanceCD") )
        return notify_fail("�A�{�b�٤��Q���ԻR�C\n");

    if( me->query_temp("is_busy/CombatDance") )
        return notify_fail("�A�w�g�b���ԻR�F�C\n");

    if( me->is_fightint() )
        return notify_fail("�A�{�b���ۥ��[�A�S�Ÿ��ԻR�C\n");

    if( me->is_busy() || sizeof(me->query_temp("is_busy")) )
        return notify_fail("�A�{�b���b���A�S�Ÿ��ԻR�C\n");

    me->apply_condition("CombatDanceCD", 240);
    me->set_temp("is_busy/CombatDance", 1);
    me->start_busy(2);

    message_vision(HIW"$N��R���СA�}�l���_�F�u�ԻR�v�C\n"NOR,me);

    me->skill_active("combat-dance",(: call_other, __FILE__, "delay", me:), 2);

    return 1;
}

void DanceEffect(object me, object who, string condition, string type, int sk)
{
    object tmp;

    if( !who->query_condition(condition) ) {
        int effect;
        if( type == "str" || type == "con" || type == "int" || type == "dex" )
            effect = sk / 50;
        else 
            effect = sk / 5;
       who->add_temp("apply/"+type, effect);
        who->add_temp(condition, effect);

    } else {
        if( who->query_condition(condition) > 80 ) return;
    }

    tell_object(who, HIW"�A���۸���ı�o����R���F�O�q�C\n"NOR);
    who->apply_condition(condition, who->query_condition(condition) + 3 + random(4) );

    // �n�������R�T��
    if( me == who ) {
        switch( random(8) ) {
            case 0: message_vision("$N�G�u�ܡI���I�v��R���и��۾ԻR�C\n", me); break;
            case 1: message_vision("$N�P��P�}���H�K�ʤF�X�U�C\n", me); break;
            case 2: message_vision("$N����b�Ť��J�ä�e�C\n", me); break;
            case 3: message_vision("$N���}���k�}�A�^�F�Ӫ��Y�ˡC\n", me); break;
            case 4: message_vision("$N���F�_�ӡA�b�Ť���F�X��A���X���������סC\n", me); break;
            case 5: message_vision("$N�k�}�ΤO����a�G�u�ܡI�v\n", me); break;
            case 6: message_vision("$N��ʵۨ��ߡA�\\�X�ۥH���O�R�����L�y�C\n", me); break;
            case 7: message_vision("$N�ʧ@�ƬO�ᮺ�A�@�Ƥ��n�N�䪺�ˤl�C\n", me); break;
        }
        return;
    }

    // �����| me �� who �洫, �K�o���i��@�Ƴ��Oxxx��yyy���ʧ@
    if( random(100) > 50 ) {
        tmp = me;
        me = who;
        who = tmp;
    }

    switch( random(9) ) {
        case 0: message_vision("$N����$n���ԻR�ʧ@�A���˾ǼˡA���ʧ@�o�۷�©�C\n", me, who); break;
        case 1: message_vision("$N���p�߽��$n���}�A�`$n�^�b�a�W�C\n", me, who); break;
        case 2: message_vision("$N�۱o��֪����ۡA���p�߼��ۤF$n�C\n", me, who); break;
        case 3: message_vision("$N�P$n���۾ԻR�A�G�ﲴ�����ɪ������i�C\n", me, who); break;
        case 4: message_vision("$N���}�V�e���F�@�ӽ�L�ʧ@�A�o���F$n�����ѡC\n", me, who); break;
        case 5: message_vision("$N�M$n�P�n�ܹD�G�u���I�ܡI�v����P�ɻR�ʡC\n", me, who); break;
        case 6: message_vision("$N�@�_�M$n�R�ʨ��ߡA��ժ��ʧ@���a�۫²r�A�٬O�n�ݡC\n", me, who); break;
        case 7: message_vision("$N����R���_�ѹ��T�A�o����$n���y�n�X�U�C\n", me, who); break;
        case 8: message_vision("$N�@���WA�@�խn�V�e�^�ˡA��M������$n�A�G�H����½�u�^�b�a�W�C\n", me, who); break;
    }
}

void delay(object me)
{
    int i, sk;
    object *target;

    if( !me ) return;

    if( !me->query_temp("is_busy/CombatDance") || me->is_fighting() ) {
        message_vision("$N������ԻR�F�C\n", me);
        return;
    }

    if( me->query_condition("CombatDanceCD") <= 230 ) {
        me->delete_temp("is_busy/CombatDance");
        message_vision("$N������ԻR�F�C\n", me);
        return;
    }

    if( !environment(me) ) return;

    target = all_inventory(environment(me));
    i = sizeof(target);

    while( i-- ) {
        if( !userp(target[i]) ) continue;
        if( !target[i]->query_temp("is_busy/CombatDance") ) continue;
        sk = target[i]->query_skill("combat-dance");

        if( sk < random(500) ) continue;
        
        switch( random(8) ) {
            case 0:
                DanceEffect(me, target[i], "CombatDanceArmor", "armor", sk);
                break;

            case 1:
                DanceEffect(me, target[i], "CombatDanceDamage", "damage", sk);
                break;

            case 2:
                DanceEffect(me, target[i], "CombatDanceHit", "hit", sk);
                break;

            case 3:
                DanceEffect(me, target[i], "CombatDanceDodge", "dodge", sk);
                break;

            case 4:
                DanceEffect(me, target[i], "CombatDanceStr", "str", sk);
                break;

            case 5:
                DanceEffect(me, target[i], "CombatDanceCon", "con", sk);
                break;

            case 6:
                DanceEffect(me, target[i], "CombatDanceInt", "int", sk);
                break;

            case 7:
                DanceEffect(me, target[i], "CombatDanceDex", "dex", sk);
                break;
        }
        target[i]->improve_skill("combat-dance", random(10) );
    }


    me->improve_skill("combat-dance", 10 + random(me->query_int()) );
    me->skill_active("combat-dance", (: call_other, __FILE__, "delay", me:), 2);

    return;
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}

// cast.c
// ��Ҧ�query_skill()-> query_learn(),���Kplayer������0 �ᤣ��ϥΧޯ�.
// by alickyuen on 24-08-2002

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spl, trg;
        string sk_arg;
        object target;

        
        seteuid(getuid());
    if(me->is_ghost()) return notify_fail("     �A�{�b�٬O����a�C\n");
        if( me->is_busy() || me->is_block() )
                return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M����I�i�ޯ�ΪZ�\\�C)\n");

        if( environment(me)->query("no_exert") )
                return notify_fail("�o�̤���ϥίS��ޯ�C\n");

        if( !arg ) return notify_fail("���O�榡�Rexert <�ޯ�ΪZ��> [on <�ؼ�>]��[at <��V>]\n");

        if( sscanf(arg, "%s on %s", spl, trg) == 2 )
        {
                target = present(trg, environment(me));
                if( !target ) target = present(trg, me);
                if( !target ) return notify_fail("�o�̨S�� " + trg + "�C\n");
                sk_arg = trg;
        } else if( sscanf(arg, "%s %s", spl, sk_arg) == 2 ) {
                 target = 0;
        } else {
                spl = arg;
                sk_arg = 0;
        }

        sscanf(spl, "%s %s", spl, sk_arg);


    if( me->query_learn(spl) > 0 || me->query_skill(spl) )
                        return (int)SKILL_D(spl)->cast_skill(me, spl, target, sk_arg);

        return notify_fail("�A�٨S�ǹL���ޯ�ΪZ�\\�C(" + spl + ")\n");
}

int help (object me)
{
        write(@HELP
���O�榡�Rexert <�ޯ�ΪZ��> [on <�I�i��H>]��[at <�I�i��V>]
 
�ϥΧޯ�M�A���ݭn���w<�Z�ǩΧޯ�W��>�M<��H>��<��V>���ݭn�P�_
�h���ޯध�\��өw�C

�b�A�I�i�Y�@�ӪZ�\�Χޯध�e�M�A�����ǹL���Z�ǩάO�ޯ�C
 
HELP
        );
        return 1;
}


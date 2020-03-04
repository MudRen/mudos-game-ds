// exert.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string skill_name, func_name, target, toward;
        object tar;

        seteuid(getuid());
        if( me->is_ghost() )
                return notify_fail(" �A�{�b�٬O����a�C\n");
        if( me->is_busy() || me->is_block() )
                return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M����I�i�ޯ�ΪZ�\\�C)\n");
        if( environment(me)->query("no_exert") )
                return notify_fail("�o�̤���ϥίS��ޯ�C\n");
        if( !arg )
                return notify_fail("���O�榡�Rexert <�ޯ�ΪZ��>[.�Z�ǩ۳N] [on <�I�i��H>]��[at <�I�i��V>]\n");
        // �ѼƤ覡:
        // 1. exert skill_name.func_name on/at target/toward
        // 2. exert skill_name on/at target/toward
        // 3. exert skill_name func_name
        if( sscanf(arg, "%s on %s", skill_name, target) == 2 )
        {
                tar = present(target, environment(me));
                if( !tar ) tar = present(target, me);
                if( !tar ) return notify_fail("�o�̨S�� "+target+"�C\n");
                sscanf(skill_name, "%s.%s", skill_name, func_name);
        }
        else if( sscanf(arg, "%s at %s", skill_name, toward) == 2 )
        {
                if( stringp(target=environment(me)->query("exits/"+toward)))
                {
                        tar = load_object(target);
                        sscanf(skill_name, "%s.%s", skill_name, func_name);
                }
                else return notify_fail("�o�Ӥ�V����I�i�ޯ�ΪZ�ǡC("+skill_name+")\n");
        }
        else if( sscanf(arg, "%s %s", skill_name, func_name) != 2 )
        {
                skill_name = arg;
                tar = 0;
        }

        if( me->query_skill(skill_name) > 0)
                return (int)SKILL_D(skill_name)->exert(me, tar, func_name);
        else return notify_fail("�A�٨S�ǹL���ޯ�ΪZ�ǡC("+skill_name+")\n");
}

int help(object me)
{
        write(@HELP
���O�榡�Rexert <�ޯ�ΪZ��> [on <�I�i��H>]��[at <�I�i��V>]

���O�榡�R
1. exert <�ޯ�ΪZ��>.<�ۼƦW> [on <�I�i��H>]��[at <�I�i��V>]
2. exert <�ޯ�ΪZ��> [on <�I�i��H>]��[at <�I�i��V>]
3. exert <�ޯ�ΪZ��> <�Z�ǩۼ�>
 
�ϥΧޯ�M�A���ݭn���w<�Z�ǩΧޯ�W��>�M<��H>��<��V>���ݭn�P�_
�h���ޯध�\��өw�C

�b�A�I�i�Y�@�ӪZ�\�Χޯध�e�M�A�����ǹL���Z�ǩάO�ޯ�C
 
HELP
        );
        return 1;
}

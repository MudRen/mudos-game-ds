// cast.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
          string spl, trg, file;
        object target,env;
        
        seteuid(getuid());
        if(me->is_ghost()) return notify_fail(" �A�{�b�٬O����a\n");
        if( me->is_busy() || me->is_block() )
                return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M������G��C)\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���S�ŬI�k�C\n");
        if( environment(me)->query("no_magic") || environment(me)->query("no_cast") )
                return notify_fail("�o�̤�����G��C\n");

        if( !arg ) return notify_fail("���O�榡�Rcast <�k�N> [on <�ؼ�>]��[at <��V>]\n");
        if( sscanf(arg, "%s on %s", spl, trg)==2 )
        {
                target = present(trg, environment(me));
                if( !target ) target = present(trg, me);

                if( !target ) return notify_fail("�o�̨S�� " + trg + "�C\n");
                if( !target->is_character() || target->query("damage") )  {
                        if( spl != "life-death-symbol" )
                                return notify_fail("�ݲM���I�A�o�ä��O�ͪ��C\n");
                }
        }
        else  if( sscanf(arg, "%s at %s", spl, trg)==2 )
        {
                 env = environment(me);
                 if(stringp(file = env->query("exits/"+trg)))
                 {
                  target = load_object(file);

                  spl = replace_string( spl, " ", "_");
                  if( me->query_spell(spl) > 0 )
                  return (int)SPELL_D(spl)->cast_spell_dir(me, spl, target, trg);
                        else return notify_fail("�A�٨S�ǹL���G��C("+spl+")\n");
                 } else return notify_fail("�o�Ӥ�V����I�k�C("+spl+")\n");
        }
        else 
        {
                spl = arg;
                target = 0;
        }

        spl = replace_string( spl, " ", "_");
        arg = replace_string( arg, " ", "_");
        if( me->query_spell(spl) > 0 )
                return (int)SPELL_D(spl)->cast_spell(me, spl, target);
        else if( me->query_spell(arg) > 0 )
                return (int)SPELL_D(arg)->cast_spell(me, spl, target);
        
        return notify_fail("�A�٨S�ǹL���G��C("+spl+")\n");
}

int help (object me)
{
        write(@HELP
���O�榡�Rcast <�G��W��> [on <�I�G��H>]��[at <�I�k��V>]
 
�I�k�M�A���ݭn���w<�G��W��>�M<�I�G��H>�h�i���i�L�C
 
 
HELP
        );
        return 1;
}


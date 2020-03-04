// consider cmds
// changed By Tmr 2002/04/10
// merits-based damage -tmr 2007/07/23
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob,me_weapon,ob_weapon;
          int opp_damage,me_damage,me_hit,ob_hit,me_def,opp_def;
        string output,me_attack_skill,ob_attack_skill;
        
        seteuid(getuid(me));
 
        if(!arg)
                return notify_fail("�A�n�����֪��j�סS\n");
        ob = present(arg, environment(me));
        if(!ob) 
                return notify_fail("�o�̨S���A�n��������H�C\n");
        if(!me->visible(ob))
                return notify_fail("�o�̨S���A�n��������H�C\n");
        if(!living(ob))
                return notify_fail("�o�ӪF�褣��¯٩ʡC\n");
        if(ob==me)
                return notify_fail("�A�ۤv�����A�A�ۤv�̲M���a�C\n");
        if(me->query("mp")<5 )
                return notify_fail("�A�믫����, �L�k���T�P�_��⪺�j�סC\n");
        me_def=me->query_armor();
        opp_def=ob->query_armor();
        
        //�ĤH���ˮ`�{��=�ˮ`�O-�ڪ���ܤO
        opp_damage = ob->query_damage() - me_def;
        //�ڪ��ˮ`�{�� = �ˮ`�O-�ĤH����ܤO
        me_damage = me->query_damage() - opp_def;

        if( opp_damage<1) opp_damage = 1+(ob->query("str")<1?1:ob->query("str"))/2;
        if( me_damage<1) me_damage = 1+(me->query("str")<1?1:me->query("str"))/2;
        
        if( objectp(me_weapon=me->query_temp("weapon")) )
                me_attack_skill = me_weapon->query("skill_type");
        else    me_attack_skill = "unarmed";
        if( objectp(ob_weapon=ob->query_temp("weapon")) )
                 ob_attack_skill = ob_weapon->query("skill_type");
        else     ob_attack_skill = "unarmed";
                 
        me_hit = COMBAT_D->attack_factor(me,me_attack_skill);
        me_hit += COMBAT_D->dodge_factor(ob,"dodge");
        me_hit = (150 + me_hit)/3;
        if(me_hit<3) me_hit = 3;
        else if(me_hit>97) me_hit = 97;

        ob_hit=COMBAT_D->attack_factor(ob,ob_attack_skill);
        ob_hit+=COMBAT_D->dodge_factor(me,"dodge");
        ob_hit=(150+ob_hit)/3;
        if(ob_hit<3) ob_hit=3;
        else if(ob_hit>97) ob_hit=97;
                
        output = sprintf("�A�J�Ӧa�����F%s(%s)"NOR"���j�פ���o�{�G\n\n", ob->name(),  ob->query("id") );
        output = sprintf("%s �A��%s(%s)"NOR"���R���v: %5d%%    ����A���R���v: %5d%% \n",
                        output, ob->name(), ob->query("id"), me_hit, ob_hit);
        output = sprintf("%s �A��y��%s(%s)"NOR"���~�ʶˮ`: %5d    ����A���~�ʶˮ`: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "bar"), COMBAT_D->Merits_damage(ob, me, opp_damage, "bar") );
        output = sprintf("%s �A��y��%s(%s)"NOR"���ͪ��ˮ`: %5d    ����A���ͪ��ˮ`: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "bio"), COMBAT_D->Merits_damage(ob, me, opp_damage, "bio") );
        output = sprintf("%s �A��y��%s(%s)"NOR"���]�k�ˮ`: %5d    ����A���]�k�ˮ`: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "wit"), COMBAT_D->Merits_damage(ob, me, opp_damage, "wit") );
        output = sprintf("%s �A��y��%s(%s)"NOR"�����F�ˮ`: %5d    ����A�����F�ˮ`: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "sou"), COMBAT_D->Merits_damage(ob, me, opp_damage, "sou") );
        output = sprintf("%s �A��y��%s(%s)"NOR"����޶ˮ`: %5d    ����A����޶ˮ`: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "tec"), COMBAT_D->Merits_damage(ob, me, opp_damage, "tec") );
        output = sprintf("%s �A��%s(%s)"NOR"�������v��: %3d%%    ����A�������v��: %3d%% \n",
                        output, ob->name(), ob->query("id"), 
                        me->query_hit()-ob->query_hit_against(),
                        ob->query_hit()-me->query_hit_against()
                        );
        
        /*
        if( me_round < 5 )
                output+=HIW+"  ��I"+ob->name()+"�H�I..�N�̧A�H�ڬݬO�A�������@�ФF!\n"+NOR; 
        else
        {
                output+="  "+ob->name()+"��_�A�ӡA�֦���";
        
                if( me_round< 3)      output+=HIR"�԰��O�D�`���ơA"+NOR;
                else  if(me_round< 5) output+=HIM"�԰��O�Q���j�j�A"+NOR;
                else  if(me_round<11) output+=   "�԰��O��j�A"; 
                else  if(me_round<20) output+=   "�԰��O���z�A";
                else  if(me_round<35) output+=   "�԰��O���j�A";
                else                  output+=   "�԰��ä����H�¯٧A�A";
                
                if( opp_round < 3)     output+=HIG"�A���ӥi�H�b�@�������ӡC\n"NOR;
                else  if(opp_round< 5) output+=HIG"�A���ӥi�H�����P�P�a��ӡC\n"NOR;
                else  if(opp_round<11) output+=   "���M�A���۷��Ӻ�A���̦n���n���ġC\n"; 
                else  if(opp_round<20) output+=   "�A�j���n��@�f�\\�Ҥ~����Ĺ�C\n";
                else  if(opp_round<35) output+=   "�A�o�n���U�����ǳƤ~����ӡC\n";
                else                   output+=   "�o�N�|�O�ܨ��W���@�ԡC\n";
        }
                */
                output += "\n";
        write(output);
        me->receive_damage("mp", 5);
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : consider <��H�W��>

�o�ӫ��O�i�H���A(�p)�ε������w��H(�t�Ǫ�)���j�סC

see also : score
HELP
    );
    return 1;
}



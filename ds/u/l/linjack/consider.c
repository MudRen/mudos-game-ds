// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        int opp_damage,me_damage,me_round,opp_round;
        string output;
        
        seteuid(getuid(me));
 
        if(!arg) return notify_fail("�A�n�����֪��j�סS\n");
                ob = present(arg, environment(me));
        if(!ob) return notify_fail("�o�̨S���A�n��������H�C\n");
        if(!me->visible(ob)) return notify_fail("�o�̨S���A�n��������H�C\n");
	if(!living(ob)) return notify_fail("�o�ӪF��ݰ_�ӨS����¯٩ʡC\n");
	if(ob==me) return notify_fail("�A�ۤv�����A�A�ۤv�̲M���a�C\n");
	if(me->query("mp")<5 ) return notify_fail("�A�믫����, �L�k���T�P�_��⪺�j�סC\n");
	opp_damage=ob->query_damage();
	opp_damage = opp_damage/2 + random(opp_damage/2);
	opp_damage -= (int)(me->query_armor()*3+random(me->query_armor()*2))/5;
	me_damage=me->query_damage();
	me_damage = me_damage/2 + random(me_damage/2);
	me_damage -= (int)(ob->query_armor()*3+random(ob->query_armor()*2))/5;
	if(me_damage<1) me_damage=1;
	if(opp_damage<1) opp_damage=1; 
	me_round = me->query("hp")/(opp_damage*2);
	opp_round = ob->query("hp")/me_damage;
	
	output="�b�A�J�Ӫ������F"+ob->name()+"���j�פ���o�{:\n\n  ";

	if( me_round < 5 ) output+=HIW+"��I"+ob->name()+"?!..�N�̧A?..�ڬݬO�A�������@�ФF!\n"+NOR; 
	else
	{
		output+=ob->name();
	
		if(me_round< 3) output+=HIR"���D�`���ƪ��԰��O�C\n"+NOR;
		else  if(me_round< 5) output+=HIM"���j�j���԰��O�C\n"+NOR;
		else  if(me_round<11) output+="����j���԰��O�C\n"; 
		else  if(me_round<20) output+="�԰��O���z�C\n";
		else  if(me_round<35) output+="���԰��O���j�C\n";
		else output+="�������O�ä����H�¯٧A�C\n";
		
		if( opp_round < 3) output+=HIG"  �{�b���A���ӥi�H�b�������ӡC\n"NOR;
		else  if(opp_round< 5) output+=HIG"  �{�b���A���ӥi�H���P��ӡC\n"NOR;
		else  if(opp_round<11) output+="  ���M�A���۷��Ӻ�A���̦n���n���ġC\n"; 
		else  if(opp_round<20) output+="  �A�i��\�n��@�f�\\�Ҥ~��\����Ĺ�C\n";
		else  if(opp_round<35) output+="  �n���U�����ǳƤ~����ӡC\n";
		else output+="  �o�N�|�O�@�����[�ԡC\n";
	}
	write(output);
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


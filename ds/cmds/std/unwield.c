// unwield.c

inherit F_CLEAN_UP;
varargs int unwield_ob(object me,object ob,int silent);
int main(object me, string arg)
{
         object ob;
	if(me->is_busy() || me->is_block())
		return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
	if( !arg ) return notify_fail("�A�n�汼����S\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("�A���W�S���o�˪F��C\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("�A�èS���˳�"+ob->name()+"�@���Z���C\n");

	return unwield_ob(me,ob,0);
}

varargs int unwield_ob(object me,object ob,int silent)
{
	string str,gender;
	if( ob->unequip() )
	{
		if(!silent){
			if( !stringp(str = ob->query("unwield_msg")) )
				str = "$N��U�⤤��$n�C\n";
			if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
			else
			{	
				if(me->query("gender")=="�k��") gender="�p";
				else gender="�A";
				str=replace_string( str, "$N", gender);
				str=replace_string( str, "$n", ob->name());
				tell_object(me,str);
			}
		}
	if(me->is_fighting()) me->add_block(1);
		return 1;
	} else
		return notify_fail("�t�εL�k���`�����Z���A�Ц^��(report)�C\n");
}


int help(object me)
{
  write(@HELP
���O�榡 : unwield <���~�W>
 
�o�ӫ��O���A��U�⤤���Z���C
 
HELP
    );
    return 1;
}
 

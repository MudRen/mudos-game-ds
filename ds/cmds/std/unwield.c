// unwield.c

inherit F_CLEAN_UP;
varargs int unwield_ob(object me,object ob,int silent);
int main(object me, string arg)
{
         object ob;
	if(me->is_busy() || me->is_block())
		return notify_fail("你的上一個動作還沒完成。\n");
	if( !arg ) return notify_fail("你要脫掉什麼﹖\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上沒有這樣東西。\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("你並沒有裝備"+ob->name()+"作為武器。\n");

	return unwield_ob(me,ob,0);
}

varargs int unwield_ob(object me,object ob,int silent)
{
	string str,gender;
	if( ob->unequip() )
	{
		if(!silent){
			if( !stringp(str = ob->query("unwield_msg")) )
				str = "$N放下手中的$n。\n";
			if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
			else
			{	
				if(me->query("gender")=="女性") gender="妳";
				else gender="你";
				str=replace_string( str, "$N", gender);
				str=replace_string( str, "$n", ob->name());
				tell_object(me,str);
			}
		}
	if(me->is_fighting()) me->add_block(1);
		return 1;
	} else
		return notify_fail("系統無法正常卸除武器，請回報(report)。\n");
}


int help(object me)
{
  write(@HELP
指令格式 : unwield <物品名>
 
這個指令讓你放下手中的武器。
 
HELP
    );
    return 1;
}
 

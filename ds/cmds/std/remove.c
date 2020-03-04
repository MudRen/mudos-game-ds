// remove.c

#include <ansi.h>

inherit F_CLEAN_UP;

varargs int do_remove(object me, object ob,int silent);

int main(object me, string arg)
{
	object ob, *inv;
	int i;
	if(me->is_busy() || me->is_block())
		return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
	if( !arg ) return notify_fail("�A�n�汼����S\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			do_remove(me, inv[i]);
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("�A���W�S���o�˪F��C\n");
	return do_remove(me, ob,0);
}

varargs int do_remove(object me, object ob,int silent)
{
	string str,gender;

	if( (string)ob->query("equipped")!="worn" )
		return notify_fail("�A�èS���˳�"+ob->name()+"��@����C\n");

	if( ob->unequip() )
	{
		if(!silent)
		{
			if( !stringp(str = ob->query("unequip_msg")) )
				switch(ob->query("armor_type")) {
					case "cloth":
					case "armor":
					case "surcoat":
					case "boots":
					case "pants":
					case "legging":
					case "mask":
					case "hands":
					case "neck":
					case "finger":
						str = YEL "$N��U�@"+ob->query("unit")+"$n�C\n" NOR;
						break;
					case "bandage":
						str = YEL "$N�N$n�q�ˤf�B��F�U�ӡC\n" NOR;
						break;
					default:
						str = YEL "$N���U�@"+ob->query("unit")+"$n�C\n" NOR;
				}
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
                // ���s�p���ݩ�
                RACE_D( me->query("race") )->reset_attribute( me );
	if(me->is_fighting()) me->add_block(1);
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP
���O�榡 : remove all | <���~�W��>
 
�o�ӫ��O���A�汼���W�Y�󨾨�.
 
HELP
    );
    return 1;
}
 

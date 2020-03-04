// promote.c
#include <ansi.h>
inherit F_CLEAN_UP;
private string *wiz_levels = ({
	"(player)",
	"(superplayer)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});
int main(object me, string arg)
{
	object ob;
	string old_status, new_status,name;
	int my_level, ob_level, level;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("���O�榡�Rpromote <�ϥΪ�> <����>\n");

	if( wiz_level(new_status) < 0 ) return notify_fail("�S���o�ص��šC\n");
	tell_object(me,"member_array(new_status, wiz_levels):"+member_array(new_status, wiz_levels)+"\n");
	if( (int) member_array(new_status, wiz_levels)<0 ) return notify_fail("�S���o�ص��šC\n");
	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("�A�u����ܨϥΪ̪��v���C\n");

        if( wiz_level(me)<6 && wiz_level(me) <= wiz_level(new_status)+1 )
// �� <  �令  <= 
		return notify_fail("�A�S���o���v�O�C\n");

	if( wiz_level(me)<6 && wiz_level(me) <= wiz_level(ob) )
		return notify_fail("�A�S���o���v�O�C\n");

	if( wiz_level(me)<6 && new_status == "(admin)" )
		return notify_fail("�A�S���o���v�O�C\n");

	name=ob->query("id");
	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, me, new_status)) )
		return notify_fail("�ק異�ѡC\n");
	if(new_status=="(superplayer)")
	{
		mkdir("/superplayer/"+name[0..0]+"/"+name);
		ob->set("cwd","/superplayer/"+name[0..0]+"/"+name+"/");
	}
	else if((old_status=="(player)" || old_status=="(superplayer)") && new_status!="(player)")
	     {
	     	mkdir("/u/"+name[0..0]+"/"+name);
		ob->set("cwd","/u/"+name[0..0]+"/"+name+"/");
		message("system",HIC+"\n\n\t��M���Ť���X�U�D���~  �u �F ��� �� �� �� ��v�I\n\n\t"
					+ob->name_id(1)+HIC+"����F"+me->name()+HIC+"���P�l�o�D�ɤѤF�A�ڤۤC��q���S�h�F�@��Ův�C\n\n"
					+NOR,users());
	     }
	if(new_status=="(superplayer)" || new_status=="(player)") ob->disable_wizard();
	message_vision("$N�N$n���v���q " + old_status + " �אּ " + new_status + " �C\n", me, ob);
	seteuid(getuid());
	ob->setup();
	ob->save();
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : promote <�Y�H> (�v������)

�ΨӴ����v������,

����6  (admin)
����5  (arch)
����4  (wizard)
����3  (apprentice)
����2  (immortal)
����1  (superplayer)
����0  (player)

�@�� admin �ണ���v���ܥ��󵥯�, �� arch �u�ണ�ɦ� appr�C
HELP
    );
    return 1;
}

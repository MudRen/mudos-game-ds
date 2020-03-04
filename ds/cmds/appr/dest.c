// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;

	object obj;

	if (!arg) return notify_fail("���O�榡 : dest <���󤧦W�٩��ɦW>\n" );

	if( sscanf(arg, "%s %s", option, target)!=2 ) {
		target = arg;
		option="";
		}

	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
		seteuid(ROOT_UID);
	else 
		seteuid(geteuid(me));

	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	if (!obj) return notify_fail("�S���o�˪���....�C\n");
	if( stringp(obj->query("equipped")) )
	{
		if(option!= "-f") obj->unequip();
	}
	if( environment(me)==environment(obj) )
	if( !stringp(msg = me->query("env/msg_dest")) )
		msg = "$N�l��X�@�Ӷ¬}�M�N$n�]�S�F�C\n";
	else
		message_vision(msg + "\n", me, obj);

	destruct(obj);
	if(obj) write("�A�L�k�N�o�Ӫ���R���C\n");
	else write("Ok.\n");

	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡 : dest [-r | -f] <���󤧦W�٩��ɦW>

�Q�Φ��@���O�i�N�@�Ӫ���(object)�Ϊ���w�q(class)�q�O���餤�M���M�Y�M����
��w�q(�Y�R���w�ɦW�����p�U)�h�U�@���ѦҨ�o�Ӫ��󪺮ɭԷ|���s�N���sĶ�C

�㦳 (admin) �������Ův�i�H�� -r �ﶵ�H ROOT_UID �����ӲM���Q�O�@������p
�ϥΪ̡C

-f �ﶵ�i�H�M���w�˳ƪ��~

�ѦҸ�ơR destruct()
HELP
    );
    return 1;
}

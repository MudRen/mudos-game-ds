// ask.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n�n�n�Y�M���D�R�Sť���L�C\n",
	"$n�C�j�������$N�M��M�����D$P�b������C\n",
	"$n�q�F�q�ӡM�ܩ�p�a���R�L�i�^�i�C\n",
	"$n���D�R��....�o�ڥi���M���M�A�̦n�ݰݧO�H�a�C\n",
	"$n�Q�F�@�|��M���D�R�藍�_�M�A�ݪ��Ƨڹ�b�S���L�H�C\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("�A�n�ݽ֤���ơS\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("�o�̨S���o�ӤH�C\n");

	if( !ob->is_character() ) {
		message_vision("$N���$n�ۨ��ۻy....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N�V$n��ť�����y" + topic + "�z�������M���O$p��Mť�����H�ܡC\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N�V$n��ť�����y" + topic + "�z�������C\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���O����M���M$n�{�b�����p�S����k��$N�����СC\n",
			me, ob);
		return 1;
	}

	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N���D�R" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
   write( @HELP
���O�榡: ask <someone> about <something>

�o�ӫ��O�b�����ɫܭ��n, �q�`�����ǥѦ��@���O�~��
��o�i�@�B����T�C
HELP
   );
   return 1;
}

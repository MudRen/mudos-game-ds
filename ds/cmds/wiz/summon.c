// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("�x... ���o�ӤH��?\n");
	// moving
	tell_room(environment(ob),"�ѪŤ����X�@���j���"+
	(string)ob->query("name")+"��F�_��, �M�ᤣ���F.\n", ob);
	tell_object(ob,"�@�����A��F�_��, �A���e�@�}��....\n");
	ob->move(environment(me));
        tell_object(me, "�A��"+(string)ob->query("name")+"���A�����e.\n");
	tell_object(ob,".... ���Ӯɵo�{�O"+(string)me->query("name")+
	"��A�˹L�Ӫ�.\n");
	tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+
	"�b�A���e\n",({me,ob}));
  // Add log -Tmr
    log_file("static/SUMMON",
        sprintf("%s(%s) summon %s(%s) �� %s at  %s\n",
        me->name(1), geteuid(me), ob->name(1), geteuid(ob),file_name(environment(me)),ctime(time()) ) );

	// ok ..
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : summon <�Y�H>

�����O�i���A(�p)�N�Y�H���A���e�C
HELP
    );
    return 1;
}

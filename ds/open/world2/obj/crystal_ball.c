inherit ITEM;
void create()
{
	set_name("�����y",({ "crystal ball","ball" }) );
	set_weight(2500);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�@�������������y�C
	==================
	��G	curse <id>
	==================
LONG);
	set("unit", "��");
	set("material","ice");
	set("no_get",1);
	}
	set("value",5000);
	setup();
}

void init()
{
	object env,me;
	me=this_player();
	if(env=environment(this_object()))
	{
		add_action("do_curse","curse");
	}
}

string long()
{
	object env,who;
	string out="",tmp="";
	out = ::long();
	out += "�A�J�Ӫ��ݤF�ݤ����y..";
	if(!this_object()->query("player_id") || !who=find_player(this_object()->query("player_id")))
	{
		out +="\n  �����y�̭��@�����۪��ݤ��M���C\n";
		return out;
	}
	
	env = environment(who);
	if(!env) out +="\n  �����y�̭��@�����۪��ݤ��M���C\n";
	else 
	{
		out+="�A�����ݨ�...\n\n";
		if(tmp=env->query_long(1)) out+=tmp;
		else out+=env->query("long");
	}
	return out;
}

int do_curse(string arg)
{
	object who,me;
	me=this_player();
	if(!arg) return notify_fail("�A���ۻy�F�@�|��..\n");
	if(me->query("mp")<20)  return notify_fail("�A�{�b���믫���n�A�L�k�����믫..\n");
	message_vision("$N��ۤ����y���: ���F�F..�a�F�F.."+arg+"�ֲ{��..\n",me);
    who = find_player(arg);
    if(!who || wizardp(who) || !environment(who))
	{
		message_vision("�����y�èS�������ܤơC\n",me);
		this_object()->delete("player_id");
		return 1;
		//return notify_fail("�A���ۻy�F�@�|��..\n");
	}
	else
	{
		me->receive_damage("mp",20);
		this_object()->set("player_id",arg);
		message_vision("�����y��M�{�F�@�U�C\n",me);
		tell_object(who,"�A��M���ө_�����Pı�A���G���ﲴ���b�ݵۧA�C\n");
		return 1;
	}
}
int query_autoload() { return 1; }

/*
message_vision()�[�J�H�U�y�y
	object snobj;//�ʵ��H
	string *snpkey;
	mapping snp;
	int i;

	snp=environment(me)->query_temp("snp");
	  if (mapp(snp) && sizeof(snp))
	   {  snpkey=keys(snp);
		for (i=0;i<sizeof(snp);i++)
		{snobj=environment(me)->query_temp("snp/"+snpkey[i]);
		tell_object(snobj, ">>>"+str3);
		}
	   }
*/
//�ק�go.c snoop�ɤ���Ӱ�
//if (me->query_temp("snoop"))
//		return notify_fail("�A���Ǻʵ�������Ӱ�\n");

/* ���F��ܬY�Y���L�Ӧӭק�
/adm/simul_efun/message�������º���
varargs void view_message(string str, object env, object me )
{
	object snobj;//������
	string *snpkey;
	mapping snp;
	int i;
	 snp=env->query_temp("snp");
	  if (mapp(snp) && sizeof(snp))
	   {  snpkey=keys(snp);
		for (i=0;i<sizeof(snp);i++)
		{snobj=env->query_temp("snp/"+snpkey[i]);
		tell_object(snobj, ">>>"+str);
		}
	   }
	message("vision",str,env,me);
}
/cmds/std/go.c�������޸�
message( "vision", mout, environment(me), ({me}) );
�ģ�	view_message(mout,environment(me),me);
message( "vision", min, environment(me), ({me}) );
�ģ�	view_message(min,environment(me),me);
*/



#include <ansi.h>

inherit ITEM;
void init()
{
	add_action("do_see","see");
	
}
void create()
{
        set_name(HIY "�滷��" NOR, ({ "telscope" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {  set("long", "�o�O�@�Ӵ��q���滷��,�A�i�H�ΨӺʵ����񪺰��R\n"+
				    "��see south�� see none�����ʵ���\n");	
                set("unit", "��");
		   // set("no_drop","�o��n�Ϊ��F��,����drop��\n");
                set("value", 50000);
                set("material", "gold");
                
        }
        setup();
}

int do_see(string arg)
{	
	mapping exits;
	object env,me;
	me=this_player();
	env = environment(me);
	if (!arg || arg=="") return 0;
	if (arg=="none" )
	if (env=me->query_temp("snoop")) 
	{
	 env->delete_temp("snp/"+me->query("id"));
	 me->delete_temp("snoop");
	 message_vision("$N�����F�ʵ�\n",me);
	 remove_call_out("clear_temp");
	 return 1;
	}else return notify_fail("�A�èS���ʵ�\n");
	if (me->query_temp("snoop")) return notify_fail("�A���b�ʵ��O!\n");
	if (me->query("ap") < 50) return notify_fail("�A�Ӳ֨S���믫�ʵ�\n");
			if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			env->set_temp("snp/"+me->query("id"),me);
		else {
			call_other(exits[arg], "???");
			find_object(exits[arg])->set_temp("snp/"+me->query("id"),me);
			}
	message_vision("$N���_�滷��}�l�ʵ�"+arg+"�����R\n",me);
	//me->command("look "+arg);
	me->force_me("look "+arg);
	me->set_temp("snoop",env);
	call_out("clear_temp",60,env,me);
	return 1;
	}
	return notify_fail("�A�n�ݨ���\n");
}

void clear_temp(object env, object me)
{
	env->delete_temp("snp/"+me->query("id"));
	tell_object(me,"�A�ְ�,�𮧤@�|��a\n");
	me->delete_temp("snoop");
	me->add("jing",-30);
	

}
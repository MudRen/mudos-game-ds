#include <ansi.h>
void init()
{
	add_action("do_putin","putin");
	add_action("do_getout","getout");
	add_action("do_list","list");
}

int do_putin(string arg)
{
	string name;
	object me,ob,env;
	me=this_player();
	env=this_object();
	if(!me->query("item"))
                return notify_fail("�s�Ův���A��Ыΰh�F�a�C\n");
	if(!arg || arg=="") 
                return notify_fail("�A���W�S���o�˪F��C\n");
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("�A���W�S���o�˪F��C\n");
        if( ob->query("equipped") )
                return notify_fail("�A�{�b���˳ƵۡC\n");
        if( ob->query_amount()>1)
                return notify_fail("����...���O��A���u���\"1\"�󪺪F��ܡC\n");

	name=(string)base_name(ob);
	for(int i=1;i<11;i++)
	{
		if(me->query("item/item"+i)=="")
		{
		me->set("item/item"+i,name);
		write("�A��"HIC+ob->query("name")+NOR"�����x�ëǸ̤F\n");
		destruct(ob);
		me->save();
		return 1;
		}
	}
	return 1;
}
int do_getout(string arg)
{
	string path;
	object me,env;
	me=this_player();
	env=this_object();
	if(!me->query("item"))
                return notify_fail("�s�Ův���A��Ыΰh�F�a�C\n");
	if(!arg || arg=="")
                return notify_fail("���O getout <�s��>�C\n");
	if(!me->query("item/item"+arg)) 
                return notify_fail("�x�ëǸ̲{�b�S���o�ӪF���C\n");
	if(me->query("item/item"+arg)=="") 
                return notify_fail("�x�ëǸ̲{�b�S���o�ӪF���C\n");
	path=me->query("item/item"+arg);
	new(path)->move(env);
	write("�A�d���U�W��"HIC+new(path)->query("name")+NOR"�q�x�ëŅ̀�F�X�ӡC\n");
	me->set("item/item"+arg,"");
	me->save();
	return 1;
}

int do_list()
{
	string path;
	object env,*ob,me;
	me=this_player();
	env=this_object();
	if(!me->query("item"))
                return notify_fail("�s�Ův���A��Ыΰh�F�a�C\n");
	write("�ثe�x�ëǸ��x�s��\n");
	for(int i=1;i<11;i++)
	{
	if(me->query("item/item"+i)=="") 
	write(i+". �L\n");	
	else{
	path=me->query("item/item"+i);
	write(i+". "+new(path)->query("name")+"\n");
	}
	}
	return 1;
}


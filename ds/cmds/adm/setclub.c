// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string id,file,club_name;
	object mark,ob,old_mark;
	mapping ob_info;
	int level;
	seteuid(getuid());
        if(!arg) return notify_fail("���O�榡 : setclub <�Y�H> with (���|�H���ɮ׸��|)\n");
        else
        {
        	if( sscanf(arg, "%s with %s", id, file)!=2 ) return notify_fail("���O�榡 : setclub <�Y�H> with (���|�H���ɮ׸��|)\n");
                ob = present(id, environment(me));
                if (!ob) ob = find_player(id);
                if (!ob) ob = find_living(id);
	        if (!ob) return notify_fail("�S���o�ӤH��.\n");
		
		if(!mark=new(file)) return notify_fail("�S���o�ӫH���άO�ɮפ����T.\n");
		if(!stringp(club_name=mark->query("club"))) return notify_fail("�o�ӫH����<club>��Ƥ����T.\n");
		 if( (mark->query_weight()+ob->query_encumbrance())>ob->query_max_encumbrance() )
 		 return notify_fail(ob->name(1)+"������"+mark->query("name")+"�C\n");
		ob->delete("club");

		CLUB_D->add_club(mark->query("club_id"));
		
		if(mark->query("club_max_level") > 1) level=mark->query("club_max_level");
			else level=5;
		
		ob_info=([
				"level": level,
				"title": "���|�Щl�H",
				"info1": "�L",
				"info2": ctime(time()),
				"info3": me->name_id(1),
		]);
		
		CLUB_D->set_member(mark->query("club_id"),getuid(ob),ob_info);
		CLUB_D->set_club_leader(mark->query("club_id"),getuid(ob));
		while(old_mark=present("club_mark", ob)) destruct(old_mark);
		mark->move(ob);
		message_vision("$N�N$n���ɬ�"+club_name+"���Щl�H�C\n",me,ob);
		ob->save();
	}
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : setclub <�Y�H> with (���|�H���ɮ׸��|)

�N�@�W���a���@�������Ѥj�C
HELP
    );
    return 1;
}

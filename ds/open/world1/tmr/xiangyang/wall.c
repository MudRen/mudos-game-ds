// Room: /d/xiangyang/wall.c
// Create by Zeratul Jan 15 2001,�������𪺥۶����~�Ӧ����

inherit ROOM;

string *up_dirs = ({ "southup", "northup", "westup", "eastup",});

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	
	return 1;	 //nothing to do -Tmr

	if( !undefinedp(query("exits")[dir]) && member_array(dir, up_dirs)!=-1 )
	{ 	
		if(userp(me))
		{
			if (me->query("ap")<10)
				me->unconcious();
			else 
			{ 
	 			me->receive_damage("ap",10); 			
	 			c_exp=me->query("combat_exp");
	 			c_skill=me->query_skill("dodge",1);
	 			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
					(c_skill<101))
			 		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			} 
		} 
	} 
       	return 1;
}



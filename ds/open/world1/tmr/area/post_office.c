inherit ROOM;

void create()
{
        set("short", "孟村郵局");
        set("long", @LONG
這裡是孟村郵局。你可以在此收信或是寄信，這裡的一切服務都是
免費的。

	mail <某人>               寄信給別人。
	replymail <信件編號>      回信給發信者。
	forward <信件編號> <某人> 將某封信轉寄給別人。
	from                      查看信箱中的信件。
	read <信件編號>           閱讀一封信件。
	discard <信件編號>        丟棄一封信件。
	
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"mstart",
]));
	set("light",1);
        set("no_clean_up", 0);
        set("room_type","mail");
        set("no_kill",1);
        set("no_exert",1);
        set("no_fight",1);
        set("no_cast",1);
	set("no_recall",1);
    set("no_goto_cmd",1);
        setup();
}

void init()
{
	object mail_ob;
	if(userp(this_player()))
	{
		if(!present("mail_ob",this_player()))
		{
			mail_ob=new(MAILBOX_OB);
			if(!mail_ob->can_move(this_player()))
			{
				write("你身上東西太多了，請丟掉一些才能正常收發信。\n");
				return;
			}
			mail_ob->set_temp("invis",1);
			mail_ob->move(this_player());
		}
	}
}

int valid_leave(object me, string dir)
{
	object mail_ob;
        if( dir=="south" )
        {
        	mail_ob=present("mail_ob",me);
        	if(mail_ob)
        	{
        		mail_ob->save();
        		destruct(mail_ob);
        	}
        }
        return ::valid_leave(me, dir);
}

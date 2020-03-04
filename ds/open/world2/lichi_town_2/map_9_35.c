inherit ROOM;
void create()
{
	set("short", "�l��");
        set("long", @LONG
        ---------------------------------------------
	mail <�Y�H>               �H�H���O�H�C
	replymail <�H��s��>      �^�H���o�H�̡C
	forward <�H��s��> <�Y�H> �N�Y�ʫH��H���O�H�C
	from                      �d�ݫH�c�����H��C
	read <�H��s��>           �\Ū�@�ʫH��C
	discard <�H��s��>        ���@�ʫH��C
LONG
);
	set("exits",([
	"east" : __DIR__"map_9_36",
	]));
	set("light",1);
	set("map_long",1);     //show map as long
        set("room_type","mail");
        set("no_kill",1);
        set("no_exert",1);
        set("no_fight",1);
        set("no_cast",1);
	set("no_recall",1);
	set("no_goto",1);
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
				write("�A���W�F��Ӧh�F�A�Хᱼ�@�Ǥ~�ॿ�`���o�H�C\n");
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
        if( dir=="east" )
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

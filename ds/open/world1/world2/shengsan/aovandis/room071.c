// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"奧凡迪斯郵局"NOR);
        set("long", @LONG
這裡是奧凡迪斯郵局。你可以在此收信或是寄信，這裡的一切服務
都是免費的。

	mail <某人>               寄信給別人。
	forward <信件編號> <某人> 將某封信轉寄給別人。
	from                      查看信箱中的信件。
	read <信件編號>           閱讀一封信件。
	discard <信件編號>        丟棄一封信件。
	
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room072",
  "east" : __DIR__"room069",
]));
	set("light",1);
        set("no_clean_up", 0);
	set("no_recall",1);
        set("no_kill",1);
        set("no_exert",1);
        set("no_fight",1);
        set("no_cast",1);
	set("room_type","mail");
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
        if( dir=="south" || dir=="east")
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

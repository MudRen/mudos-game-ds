// mailbox.c
// 上次修改日期: 1999.10.21 0:51
// 上次修改者: Luky
// 修改內容: 修改mail的確認
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping *mails;

int last_read_time;
int newest_mail_time;
void get_mail_text(mapping mail, string str);

void create()
{
	set_name("信箱", ({ "mailbox","mail_ob" }) );
	set("long",@LONG

		這是一個用來寄信、收信的信箱﹐你可以用以下指令來處理你的郵件﹕
		
		
		mail <某人>               寄信給別人。
		replymail <信件編號>      回信給發信者。
		forward <信件編號> <某人> 將某封信轉寄給別人。
		from                      查看信箱中的信件。
		read <信件編號>           閱讀一封信件。
		discard <信件編號>        丟棄一封信件。
LONG
	);
	set("unit", "個");
	set("no_drop", 1);
	set("no_put", 1);
	set("no_insert", 1);
	seteuid(getuid());

}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void set_last_read(int time)
{
	if(last_read_time < time)
	{
		last_read_time = time;
//		save();
	}
	return ;
}

int query_last_read_time()
{
	return last_read_time;
}
int query_newest_mail_time()
{
	return newest_mail_time;
}

int query_mail_flag()
{
	if(last_read_time < newest_mail_time) return 1;
	else return 0;
}

void init()
{

	if( this_player() && environment()==this_player() )
	{
		set_owner( getuid(this_player()) );
		this_player()->set_temp("mbox_ob", this_object());
		set_name( this_player()->name(1) + "的信箱", ({ "mailbox","mail_ob" }) );
		add_action("do_mail", "mail");
		add_action("do_replymail", "replymail");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
		if(wiz_level(this_player()) > 4)
		{
			add_action("do_mailall","mailall");
			write(HIW"您可以使用 mailall 指令寄信所有的玩家.\n"NOR);
		}
	}
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	object ppl;
	if(ppl=find_player(query("owner_id")))
	{
                write("已通知 " + ppl->short(1) + " 收信!\n");
                tell_object(ppl,HIG"\n  Ouch!! 你突然被天上掉下來的酒瓶打到頭, 酒瓶碎片裡有張紙寫著:\n"+HIC"\n\t\t\t  [1;5m您有新信。\n\n"NOR+"你彷彿聽見"+this_player()->name(1)+"在一旁竊笑。\n");
	}

	if( !pointerp(mails) ) mails = ({ mail });
	else
	{
		mails += ({ mail });
		if(mail["time"] > newest_mail_time) newest_mail_time=mail["time"];
	}
	save();
	if(!environment()) destruct(this_object());
}

void send_mail(string receiver, mapping mail)
{
        object ob;
	if(!wizardp(this_player()) && this_player()->query("talk_point")<10)
	{
		write("你沒有足夠的說話點數。\n");
		return;
	}
	ob = FINGER_D->acquire_login_ob(receiver);
	if( !ob ) {
		write("沒有這個玩家。\n");
		return;
	}
        // Get the mailbox or make a new one if not found.
        if(!wizardp(this_player())) this_player()->add("talk_point",-10);

        MAIL_D->send_mail(receiver,mail);

}
/*
void send_mail(string rcvr, mapping mail)
{
	object ppl, ob, mbx;
	
	if(!wizardp(this_player()) && this_player()->query("talk_point")<4)
	{
		write("你沒有足夠的說話點數。\n");
		return;
	}
	// Acquire the login object of receiver and mark the arrival of newmail.
	ob = FINGER_D->acquire_login_ob(rcvr);
	if( !ob ) {
		write("沒有這個玩家。\n");
		return;
	}
	ob->set("new_mail", 1);
	ob->save();

	// Get the mailbox or make a new one if not found.
	ppl = find_player(rcvr);
	if(ppl)
	{
		mbx = ppl->query_temp("mbox_ob");
	}
	if( !mbx ) {
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
	}

	// Receive the mail and destruct the objects if receiver is off-line.
	mbx->receive_mail(mail);
	if(!wizardp(this_player())) this_player()->add("talk_point",-4);
	if(!ppl)
	{
		destruct(ob);
	} else tell_object(ppl,HIG"\n  Ouch!! 你突然被天上掉下來的酒瓶打到頭, 酒瓶碎片裡有張紙寫著:\n"+HIC"\n\t\t\t  [1;5m您有新信。\n\n"NOR+"你彷彿聽見"+this_player()->name(1)+"在一旁竊笑。\n");
	if(!environment(mbx)) destruct(mbx);
}
*/
int do_mail(string arg)
{
	mapping mail;
         string t1,t2;
	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("你要寄信給誰﹖\n");
	if(sscanf(arg, "%s %s", t1, t2) == 2 )	return notify_fail("指令格式: mail <who>\n");
	mail = ([
		"from":	this_player()->name(1) + "(" + getuid(this_player()) + ")",
		"title": "無題",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("信件標題﹕");
	input_to("get_mail_title", mail);
	return 1;
}

int do_mailall(string arg)
{
	mapping mail;
	if( this_player()!=environment() ) return 0;
	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "無題",
		"to": "all players",
		"time": time(),
		"text": ""
	]);
	write("信件標題﹕");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("信件內容﹕\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	string sigfn,id,sig;
	id=getuid(this_player());
	sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,id[0..0],id);
	if (sig = read_file (sigfn))
    		str = str + "\n--\n"+sig+NOR;
  	else
    		str = str+NOR;
	mail["text"] = str;
	write("您自己要留一份備份嗎(y/n)﹖[n]");
	input_to("confirm_copy", mail);
}
void confirm_copy(string yn, mapping mail)
{
	mapping old_mail;
        if( yn[0]=='y' || yn[0]=='Y' )
        {
        	old_mail = ([
		"from":	mail["from"],
		"title": "無題",
		"to": mail["to"],
		"time": mail["time"],
		"text": mail["text"]
		]);
        	old_mail["title"]="[備份] "+mail["title"];
        	receive_mail(old_mail);
        }

        if(mail["to"] == "all players")
        {
        	MAIL_D->send_mail_to_all(mail);
        	write("系統正在寄信給所有的玩家,這可能需要幾分鐘的時間.\n");
        	return;
        }
        else send_mail(mail["to"], mail);
        write ("請問還有要寄給誰嗎(y/n) ? [n]");
        input_to ("confirm_other", mail);
}

void confirm_other(string yn, mapping mail)
{
        if ( yn[0]=='y' || yn[0]=='Y' ) {
          write ("請一次一個輸入名單, 結束請用句點 '.'  : ");
          input_to("mail_other", mail);
        }
        else write("信寄出去了。\n");
}

void mail_other(string name, mapping mail)
{
        if (name == ".")
          write ("信寄出去了。\n");
        else {
	  mail["to"] = name;
          send_mail(name, mail);
          write ("請一次一個輸入名單, 結束請用句點 '.'  : ");
          input_to("mail_other", mail);
        }
}

int do_from()
{
	int i;

	if( !pointerp(mails) || !sizeof(mails) ) {
		write("你的信箱中目前沒有任何信件。\n");
		return 1;
	}
	write("你的信箱中現在共有 " + sizeof(mails) + " 封信件﹕\n\n");
	for(i=0; i<sizeof(mails); i++)
	{
		printf("%s\n%2d %-50s 寄信人﹕%-20s"NOR,last_read_time<mails[i]["time"]? HIG : "",
			i+1, mails[i]["title"], mails[i]["from"] );
	}
	write("\n\n");
	return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要讀哪一封信﹖\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("沒有這個編號的信件。\n");

	num --;

	printf("信件標題﹕%s\n寄 信 人﹕%s\n\n%s\n",
		mails[num]["title"], mails[num]["from"], mails[num]["text"] );
	set_last_read(mails[num]["time"]);
	save();
	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丟棄哪一封信﹖\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("沒有這個編號的信件。\n");

	num --;
	set_last_read(mails[num]["time"]);
	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("你要將哪一封信轉寄給別人﹖\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("沒有這個編號的信件。\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/轉寄自" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

int do_replymail(string arg)
{
	int num,i;
	object me;
	string t1,t2,text,old_text,temp_text,*tmp,dest,title;
	mapping mail,old_mail;
	me=this_player();

	if( !arg || sscanf(arg, "%d", num)!=1 )	return notify_fail("你要回覆哪一封信﹖\n");

	if( !pointerp(mails) || num > sizeof(mails) ) return notify_fail("沒有這個編號的信件。\n");
	num--;
	if( this_player()!=environment() ) return 0;
	old_mail=([]);
	old_mail = mails[num];
	t1=old_mail["from"];
	if(sscanf(t1,"%s(%s)", t2,dest)!=2) return notify_fail("無法辨認寄件者。\n");

  // mail 是要編的信，notes 是板面上的信
  // old_mail 是要回的信的內容，也就是舊信內容,
  // temp_mail 則是改 note1 的暫時信的內容

  title = old_mail["title"];
  title = replace_string(title,"回覆:","");
  title = "回覆:"+title;
  old_text=old_mail["text"];

  old_text = sprintf (" %s        [%s]%s的來信:\n%s\n%s",
                old_mail["title"]+"",
                ctime(old_mail["time"])[4..9]+"",
                old_mail["from"]+"",
                "=============================================================",
                old_mail["text"]+"");
                
  old_text = replace_string(old_text,CYN,"");
  old_text = replace_string(old_text,NOR,"");
  temp_text = CYN+":"+old_text;
  //note1 = replace_string(note2,"\n",CYN+"\n: ");
  temp_text = replace_string(temp_text,"\n","\n"+CYN+": ");
  temp_text = temp_text[0..<3];
  temp_text = temp_text+NOR+"\n";

  tmp = explode(temp_text,"\n");
  text="";
  for(i=0; i < sizeof(tmp); i++)
  {
    if (tmp[i] == CYN+": --") break;  //簽名檔
    if (strsrch(tmp[i],": : :") != 0) text += tmp[i] + "\n";
  }
  tmp = 0;
  text = text+NOR+"\n";
  
  mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": title,
		"to": dest,
		"time": time(),
		"text": ""
  ]);
  this_player()->edit( (: get_mail_text, mail :),text );
  return 1;
  
//  write("您要在編輯時暫停所有訊息(包括被攻擊)的接收嗎?(y/n) ");
//  return input_to( (: to_post :), me,board,note,note1 );

}

void owner_is_killed() { destruct(this_object()); }

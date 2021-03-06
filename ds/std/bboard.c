// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

int do_help(string);

void setup()
{
	string loc;

	seteuid(getuid());

	if( stringp(loc = query("location")) )
		move(loc);
	else {
	  write ("這個留言版要擺\在哪兒?.\n");
	  return;
	}
	set("no_get", 1);
	set("no_sac", 1);
	set("no_clean_up",1);
	if(!query("unit")) set("unit", "面");
	restore();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_discard", "discard");
        add_action("do_help", "help");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ 沒有任何留言 ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s [ %d 張留言﹐%d 張未讀 ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d 張留言 ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, last_time_read, n;
	string msg, tmp;

	notes = query("notes");
	msg = query("long");
	msg = msg + query("name")+"的使用方法請見 help board。\n\n";
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");
	msg +="=============================== 留 言 索 引 表 ===============================\n";
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++) {
		tmp = notes[i]["title"]+" ";
		n = 52-strlen(notes[i]["author"]);
		if (strlen(tmp) > n) tmp = tmp[0..n-1];
		else {
		  n -= strlen(tmp);
		  tmp+=BLU;
		  while (n-->0) tmp+="_";
		  tmp+=NOR;
		}
		tmp += " "+notes[i]["author"];
		msg += sprintf("%s[%02d]" NOR " %s [%s]\n",
			( notes[i]["time"] > last_time_read ? HIY: ""),
			i+1,
			tmp,
//                        ctime(notes[i]["time"])[0..15] );
                        ctime(notes[i]["time"]) );


	}
	msg+="\n";
	return msg;
}

int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;
	object me;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
	me = this_player();

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前沒有任何留言。\n");

	if( !arg ) return notify_fail("指令格式﹕read <留言編號>|new\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要讀第幾張留言﹖\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("沒有這張留言。\n");

	num--;

	me->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
//          num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
         num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"]))


		+ notes[num]["msg"] );

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}

int do_discard(string arg)
{
	mapping *notes;
	mixed masters;
	string myid;
	object	me;
         int num, i, master;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式﹕discard <編號>\n");
	me = this_player();
	//myid = me->query("id");
	myid=getuid(me);
//	write("myid is "+myid+"\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("沒有這張留言。\n");
	num--;

	master = 0;
	masters=this_object()->query("master");
	if( arrayp(masters) )
	{
	    for(i=0; i<sizeof(masters); i++)
	    {
//	    	write(masters[i]+"\n");
	    	if( masters[i] == myid)
	    	{
	    		write(" You are board master !! \n");
	      		master = 1;
	      		break;
	      	}
	    }
	}
	else if( stringp(masters) )
	     {
	       if( masters == myid ) master = 1;
	     }

	if( notes[num]["author"] != (string) me->query("name")+"("+me->query("id")+")"
	&& master==0
	&& (string)SECURITY_D->get_status(me) != "(admin)")
		return notify_fail("你沒有刪除此留言的權力。\n");

	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("刪除第 " + (num+1) + " 號留言....Ok。\n");
	return 1;
}

int do_help(string str)
{
  if (str!="board") return 0;
    write(@Help
    
    □ 夢幻七域留言版使用方法
    
    post <標題>      把你的留言貼上去﹐注意..你必須指定一個標題。
    followup <編號>  對別人的留言有意見? 這可以讓你回應指定編號的留言。
    read <編號>      閱讀指定編號的留言。
    read new         閱讀新的留言。
    
    discard <編號>   刪除指定編號的留言。
                     
    PS. 只有大神和板主可以刪除別人的留言﹐你只能刪除自己寫的。
                 
Help);
  return 1;
}

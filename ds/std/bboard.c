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
	  write ("�o�ӯd�����n�\\�b����?.\n");
	  return;
	}
	set("no_get", 1);
	set("no_sac", 1);
	set("no_clean_up",1);
	if(!query("unit")) set("unit", "��");
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
		return ::short() + " [ �S������d�� ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s [ %d �i�d���M%d �i��Ū ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d �i�d�� ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, last_time_read, n;
	string msg, tmp;

	notes = query("notes");
	msg = query("long");
	msg = msg + query("name")+"���ϥΤ�k�Ш� help board�C\n\n";
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");
	msg +="=============================== �d �� �� �� �� ===============================\n";
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
		return notify_fail("�d���O�W�ثe�S������d���C\n");

	if( !arg ) return notify_fail("���O�榡�Rread <�d���s��>|new\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("�A�nŪ�ĴX�i�d���S\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("�S���o�i�d���C\n");

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
		return notify_fail("���O�榡�Rdiscard <�s��>\n");
	me = this_player();
	//myid = me->query("id");
	myid=getuid(me);
//	write("myid is "+myid+"\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("�S���o�i�d���C\n");
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
		return notify_fail("�A�S���R�����d�����v�O�C\n");

	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("�R���� " + (num+1) + " ���d��....Ok�C\n");
	return 1;
}

int do_help(string str)
{
  if (str!="board") return 0;
    write(@Help
    
    �� �ڤۤC��d�����ϥΤ�k
    
    post <���D>      ��A���d���K�W�h�M�`�N..�A�������w�@�Ӽ��D�C
    followup <�s��>  ��O�H���d�����N��? �o�i�H���A�^�����w�s�����d���C
    read <�s��>      �\Ū���w�s�����d���C
    read new         �\Ū�s���d���C
    
    discard <�s��>   �R�����w�s�����d���C
                     
    PS. �u���j���M�O�D�i�H�R���O�H���d���M�A�u��R���ۤv�g���C
                 
Help);
  return 1;
}

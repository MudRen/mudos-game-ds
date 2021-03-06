// post.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit F_DBASE;
int help(object);
void create()
{ 
	seteuid(getuid()); 
	set("no_clean_up",1);
	set("name", "回報精靈");
	set("id", "bugman");
}
void done_post(object me,object board,mapping note,string text)
{
  mapping last_read_time;
  string myid;
  mapping *notes;
  int c;
  string sigfn,sig,id;

  seteuid(ROOT_UID);
  last_read_time = me->query("board_last_read");
  myid = board->query("board_id");
  id = me->query("id");
  if( id == "guest" )
      return 0;
  sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,id[0..0],id);
  if(objectp(environment(me))) text+="\n [回報地點]: "+base_name(environment(me))+"\n";
  if (sig = read_file (sigfn))
    note["msg"] = text + "\n--\n"+sig;
  else
    note["msg"] = text;

  notes = board->query("notes");

  if ( !pointerp(notes) || !sizeof(notes) )
    notes = ({ note });
  else
    notes += ({ note });

  // Truncate the notes if maximum capacity exceeded.
  c = board->BOARD_CAPACITY;
  if (sizeof(notes) > c)
    notes = notes[c / 2 .. c];

  board->set("notes",notes);
  tell_object(me,"留言完畢。\n");

  // Keep track which post we were reading last time.
  if ( !mapp(last_read_time) )
    me->set("board_last_read",([ myid: note["time"] ]) );
  else if (undefinedp(last_read_time[myid]) || note["time"] >
    last_read_time[myid] )
  {
    last_read_time[myid] = note["time"];
  }

  board->save();
  
  //remind wiz to take care this bug post.		
  CHANNEL_D->do_channel( this_object(), "wiz", sprintf("%s(%s)回報了一個新的BUG: %s",
					me->name(1), getuid(me), note["title"]));
  return;
}

void ed_exit()
{
  object board;
  mapping note;
  string fn,buf;
  string sigfn,sig,myid;

  seteuid(ROOT_UID);
  board = this_player()->query_temp("post/board");
  note = this_player()->query_temp("post/note");
  fn = this_player()->query_temp("post/fn");

  myid = this_player()->query("id");
  sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,myid[0..0],myid);
  if (sig = read_file (sigfn))
    buf = read_file(fn) + "\n--\n" + sig;
  else
    buf = read_file(fn);
  rm (fn);
  done_post (this_player(),board,note,buf);
  buf = 0;
}

int main(object me,string arg)
{
  mapping note=([ ]);
  object  board;
  string args;
  
  if (me != previous_object()) return 0;

  seteuid(geteuid(me));

  if (!arg) return help(me);
  if (arg=="-r") return help(me);
  
    if (!board = load_object("/obj/board/bug_b"))
    return 0;

  if ( arg =="-l")
  {
  	me->start_more(board->long());
  	return 1;
  }

  if( sscanf(arg,"-r %s",args)>0)
  {
  	return board->do_read(args);
  }


  note = allocate_mapping(4);
  note["title"] = "●"+arg;
  note["author"] = me->query("name")+"("+getuid(me)+")";
  note["time"] = time();

  me->edit( (: done_post,me,board,note :) );
  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : report <標題>    : 回報BUG
	   report <-l> 	    : 文章列表
	   report <-r 編號> : 閱讀文章
	   
指令說明 : 可在任何地方用本命令來回報Bug，回報內容會存放至Bug板.

	如: >report moon_force有BUG!!
回報時注意事項:
目前大家因為想賺 award, 找錯字找得是很兇. 不過很多人都找
一堆根本沒錯的字來, 以後要 report 錯字需要注意以下幾點:
    1.要有該錯字的字義解釋
    2.要有正確字的字義解釋
    3.要有為什麼不能用原字的理由
要不然就算亂報 report, 要扣 award. 以後請 DS 玩家注意.
=========================================================
還有遇上出現 bug 訊息時, 請即刻 report,
並把當時您所下的指令, 或所在場所, 以及 bug 訊息
一並 report 在一起, 以便巫師除蟲.
=========================================================


相關指令: post followup signature 。

<Luky.7/19/99>
<Linjack.7/2/00>
HELP
    );
    return 1;
}

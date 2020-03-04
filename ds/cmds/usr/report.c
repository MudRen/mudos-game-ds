// post.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit F_DBASE;
int help(object);
void create()
{ 
	seteuid(getuid()); 
	set("no_clean_up",1);
	set("name", "�^�����F");
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
  if(objectp(environment(me))) text+="\n [�^���a�I]: "+base_name(environment(me))+"\n";
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
  tell_object(me,"�d�������C\n");

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
  CHANNEL_D->do_channel( this_object(), "wiz", sprintf("%s(%s)�^���F�@�ӷs��BUG: %s",
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
  note["title"] = "��"+arg;
  note["author"] = me->query("name")+"("+getuid(me)+")";
  note["time"] = time();

  me->edit( (: done_post,me,board,note :) );
  return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : report <���D>    : �^��BUG
	   report <-l> 	    : �峹�C��
	   report <-r �s��> : �\Ū�峹
	   
���O���� : �i�b����a��Υ��R�O�Ӧ^��Bug�A�^�����e�|�s���Bug�O.

	�p: >report moon_force��BUG!!
�^���ɪ`�N�ƶ�:
�ثe�j�a�]���Q�� award, ����r��o�O�ܥ�. ���L�ܦh�H����
�@��ڥ��S�����r��, �H��n report ���r�ݭn�`�N�H�U�X�I:
    1.�n���ӿ��r���r�q����
    2.�n�����T�r���r�q����
    3.�n�������򤣯�έ�r���z��
�n���M�N��ó� report, �n�� award. �H��� DS ���a�`�N.
=========================================================
�٦��J�W�X�{ bug �T����, �ЧY�� report,
�ç��ɱz�ҤU�����O, �ΩҦb����, �H�� bug �T��
�@�� report �b�@�_, �H�K�Ův����.
=========================================================


�������O: post followup signature �C

<Luky.7/19/99>
<Linjack.7/2/00>
HELP
    );
    return 1;
}

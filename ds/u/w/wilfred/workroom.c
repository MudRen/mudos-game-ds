#include <ansi2.h>
inherit ROOM;

void leave_message(object me);
int check_friend(object me);
void create()
{
  set("short",HIB"�P"HIW"��"HIG"�m"HIR"ø"NOR);
  set("long",
HIW"\n\t�p�G�A�Aı�o�����O���򪺬��n          \n"
HIW  "\t  �A�����ñ��]�ߪ��R�C                \n"
HIW  "\t���ߡA�뤧���N���{��j�a              \n"
HIW  "\t  �ڭ̱N�H�w�r�B�@�۪��ߪﱵ͢�����{�C\n\n"NOR
);
  set("exits",([
  "down" : __DIR__"workroom1",
//  "area" : "/open/world1/wilfred/sand/room12",
]));
  set("objects", ([
//  __DIR__"toilet" : 1,
]));
  set("no_clean_up",0);
  set("light",1);
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/wilfred_b" , "???");
}

void init()
{
  if(!userp(this_player())) return;
  leave_message(this_player());
  call_out("enter_check",1,this_player());
  if(geteuid(this_player()) == "wilfred") add_action("catting","show");
  add_action("do_say","say");
}

int enter_check(object ob)
{
  string file, str = "";
  if(geteuid(ob) == "wilfred") return 1;
  file = "/u/w/wilfred/guest.log";

  if(wiz_level(ob) > 4) str = HBBLU""HIW"";
  str += sprintf("%s(%s) �Ө�P�űmø�� %s �C\n",ob->query("name"),geteuid(ob),ctime(time()));
  str += ""NOR;
  if( file_size(file) < 0 ) write_file(file, str);
  write_file(file, str);
  message_vision(HIY"���B�@�D�n�����GHi! "+ob->name()+ HIY" �A�n�r�I\n"NOR, ob);
  return 1;
}

int catting(object me)
{
  if( file_size("/u/w/wilfred/guest.log") < 0 ) return notify_fail("�S���o���ɮ�\n");
  write(HIC"�סססססססססססססס� �X�ȰO�� �סססססססססססססס�\n"NOR);
  this_player()->start_more(read_file("/u/w/wilfred/guest.log"));
  write("\n");
  return 1;
}

void leave_message(object me)
{
  object boss,ob1,ob2;
  int i;
  boss = find_player("wilfred");

  if(wiz_level(me) != 6 && !check_friend(me) && geteuid(me) != "wilfred")
  {
    message_vision(HIR"�ѤW�ǨӤ@���n�����D�G�y�޳޳�...�o�n�����O$N�ӨӪ��a���...�z\n"NOR,me);
    message_vision(HIY"�ѤW��M���U�@�D���A�N$N�ιΥ]���A�M�ᤣ���F�C\n"NOR,me);
    me->move("/open/always/ppl_jail");
    return;
  }

  if( boss )
  {
    if( geteuid(me) != "wilfred" )
    {
      ob1 = load_object(__DIR__"workroom");
      ob2 = present("wilfred",ob1);
      if( ob2 ) return;
      tell_object(boss,BEEP""BLINK""HBBLU""HIW"���X�Ȩ��o�I( "+me->query("name")+" )\n"NOR);
      tell_object(me,HIG"���t�w�Ъ��d���G�ڲ{�b���b�u�@�ǡA�]���i�ण�b�u�W�A���ƽЯd�� Thanks�I \n"NOR);
    }
  }
  else tell_object(me,HIG"���t�w�Ъ��d���G�ڲ{�b���b�u�@�ǡA�]���i�ण�b�u�W�A���ƽЯd�� Thanks�I \n"NOR);

  write(WHT"\n�����t�w�Ъ���L�d���G��\n"NOR);
  i = random(3);
  if( file_size("/u/w/wilfred/message"+(string)i) < 0 )
  {
    write(HIR"\n�L�C\n\n"NOR);
    return;
  }
  this_player()->start_more(read_file("/u/w/wilfred/message"+(string)i));
  write("\n");
  return;
}

int check_friend(object me)
{
  string *str = ({
"aoe","anfernee","eeman","ftp","kimfish","kula","lily","sopp","spock","acme",
"tmr","cominging","luky","shengsan","linjack","testchar","baal"
});
  int i;
  for(i=0;i<sizeof(str);i++)
    if(geteuid(me) == str[i]) return 1;
  return 1;
}
int do_say(string str)
{
  object me = this_player();
  write(YEL"�A���R"+str+"\n"NOR);
  say(YEL""+me->query("name")+ "(" +geteuid(me)+ ")" +"���R"+str+"\n"NOR);
  return 1;
}


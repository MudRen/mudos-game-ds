#include <ansi2.h>
inherit ROOM;

void leave_message(object me);
int check_friend(object me);
void create()
{
  set("short",HIB"星"HIW"空"HIG"彩"HIR"繪"NOR);
  set("long",
HIW"\n\t如果，你覺得晚霞是那麼的美好          \n"
HIW  "\t  你更應珍惜夜晚的靜。                \n"
HIW  "\t今晚，月之神將降臨於大地              \n"
HIW  "\t  我們將以歡愉且虔誠的心迎接祂的來臨。\n\n"NOR
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
  str += sprintf("%s(%s) 來到星空彩繪於 %s 。\n",ob->query("name"),geteuid(ob),ctime(time()));
  str += ""NOR;
  if( file_size(file) < 0 ) write_file(file, str);
  write_file(file, str);
  message_vision(HIY"遠處一道聲音說：Hi! "+ob->name()+ HIY" 你好呀！\n"NOR, ob);
  return 1;
}

int catting(object me)
{
  if( file_size("/u/w/wilfred/guest.log") < 0 ) return notify_fail("沒有這個檔案\n");
  write(HIC"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝ 訪客記錄 ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"NOR);
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
    message_vision(HIR"天上傳來一個聲音說道：『喂喂喂...這好像不是$N該來的地方喔...』\n"NOR,me);
    message_vision(HIY"天上突然降下一道光，將$N團團包圍住，然後不見了。\n"NOR,me);
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
      tell_object(boss,BEEP""BLINK""HBBLU""HIW"有訪客來囉！( "+me->query("name")+" )\n"NOR);
      tell_object(me,HIG"高速硬碟的留言：我現在不在工作室，也有可能不在線上，有事請留言 Thanks！ \n"NOR);
    }
  }
  else tell_object(me,HIG"高速硬碟的留言：我現在不在工作室，也有可能不在線上，有事請留言 Thanks！ \n"NOR);

  write(WHT"\n§高速硬碟的其他留言：§\n"NOR);
  i = random(3);
  if( file_size("/u/w/wilfred/message"+(string)i) < 0 )
  {
    write(HIR"\n無。\n\n"NOR);
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
  write(YEL"你說﹕"+str+"\n"NOR);
  say(YEL""+me->query("name")+ "(" +geteuid(me)+ ")" +"說﹕"+str+"\n"NOR);
  return 1;
}


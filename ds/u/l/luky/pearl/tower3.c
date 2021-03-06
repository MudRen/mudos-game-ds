// This is a room made by roommaker.
#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
set("short", "海神塔三樓");
set("long", @LONG
一走上來你立刻注意到一座雄偉的雕像。這一座海神海力克斯的雕像非常
的生動, 栩栩如生的雙眼威嚴的注視著你, 使你不自主的低下頭來避開祂的視
線。這裡有四個窗戶並且分別對準四個方位, 可以很清楚的看見周圍環境的狀
況, 是個非常優良的瞭望場所。
LONG
);
set("objects",([
__DIR__"npc/towersoldier":2,
__DIR__"npc/towerleader":1,
]));
set("exits", ([ 
  "down" : __DIR__"tower2",
]));
set("item_desc",([
"statue":@NOTE
一個海神的上半身雕像, 雕像的右手抓著一隻金黃色的動物, 你仔細一看才知
道那原來是一隻大龍蝦..雕像前面放了一個供桌(Table), 用來放置祭品。
NOTE
,
"雕像":@CNOTE
一個海神的上半身雕像, 雕像的右手抓著一隻金黃色的動物, 你仔細一看才知
道那原來是一隻大龍蝦..雕像前面放了一個供桌(Table), 用來放置祭品。
CNOTE
,
"table":"一個四腳的大石桌, 上面還放了許\多的小魚乾..怪怪的..\n"
"或許\你該好好的調查看看。\n",
"供桌":"一個四腳的大石桌, 上面還放了許\多的小魚乾..怪怪的..\n"
"或許\你該好好的調查看看。\n",
]));
set("no_clean_up", 0);
setup();
 load_object(__DIR__"npc/halfshark1");
 load_object(__DIR__"pearl_12");
 load_object(__DIR__"pearl_1");
 load_object(__DIR__"pearl_8");
 load_object(__DIR__"pearl_10");
}

void init()
{
 object ob;
 ob=this_object();
 add_action("do_search","search");
 add_action("do_put","put");
 if(!ob->query("WarStart") && !ob->query("startcheck"))
 {
  ob->set("startcheck",1);
  call_out("war_check",50);
 }
}

int do_search(string arg)
{
 object me,obj;
 me=this_player();
 if(!arg) return notify_fail("你要搜查什麼?\n");
 if(arg=="table" || arg=="供桌" || arg=="桌子")
 {
  if(query_temp("cork")) return notify_fail("你沒有發現任何東西.\n");
  write ("你發現了一個木箱子, 箱子上面還有一個小洞(Hole)。\n",me);
  return 1;
 }
 if(arg=="hole" || arg=="小洞" || arg=="洞")
 {
  if(query_temp("cork")) return notify_fail("你沒有發現任何東西.\n");
  write ("這個洞的大小和酒瓶子的瓶口大小差不多, 裡面好像藏了什麼東西。\n",me);
  return 1;
 }
 return 0;
}

int do_put(string arg)
{
 object me,cork;
 mixed msg;
 me=this_player();
 if(query_temp("cork")) return 0;
 msg=({
  "\n小木箱開始發出些許\的呻吟聲...並晃動了起來!!\n"NOR,
  "\n小木箱:"+HIY+" 唔.. 好難過啊..快沒氣了..我..受不了啦..\n"NOR,
  "\n碰! 的一聲.. 木箱被撞個粉碎!! \n"NOR,
  });

 if(arg=="cork in hole")
 {
  cork=present("cork",this_player());
  if(!cork) return notify_fail("你沒有這樣東西.\n");
  message_vision("$N用軟木塞輕輕塞住箱子上的小洞..\n",me);
  call_out("delay_msg",3,msg[0]);
  call_out("delay_msg",7,msg[1]);
  call_out("delay_msg",10,msg[2]);
  call_out("do_clone",11,me);
  set_temp("cork",1);
  destruct(cork);
  return 1;
 }
 return 0;
}

int delay_msg(string str)
{
 tell_object(this_object(),str);
 return 1;
}

int do_clone(object me)
{
  object obj;
  obj=new(__DIR__"npc/turtlef");
  obj->move(this_object());
  tell_object(this_object(),HIY"一隻大海龜慢慢的從破木塊中爬了出來..\n"NOR);
  tell_object(this_object(),HIY"大海龜說道: 是哪一個缺德的傢伙把我的通氣孔給堵死啦?!\n"NOR);
  return 1;
}

void war_check()
{
 object ob;
 ob=this_object();
 remove_call_out("war_check");
 if(ob->query("war")==2)
 {
  shout(HIC"\n\n 海妖族首領: "HIW" 喔?! 還有很多的人躲在陸地上?? 很好!!!\n\n"NOR);
  shout(HIW"            那還等什麼?! 讓我們一口氣把那些自以為是的人類給消滅掉!! 哈哈哈..\n\n"NOR);
  new(__DIR__"npc/halfshark")->move(__DIR__"sand1");
  new(__DIR__"npc/halfshark")->move(__DIR__"sand1");
  ob->delete("war");
  ob->delete("startcheck");
  ob->set("WarStart",1);
  call_out("war_report",50);
 } else
 if(ob->query("war")==1)
 {
  shout(HIC"\n\n 海妖族首領: "HIW" 嘿嘿嘿... 那個可惡的海神走狗終於死了!!\n\n"NOR);
  shout(HIW"                 我飢餓的子民們!! 讓我們離開這個黑暗潮濕的地方, 去大快朵頤一番吧!!! \n\n"NOR);
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_1");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_12");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_12");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_1");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_8");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_10");
  ob->set("war",2);
  call_out("end_war",600);
  call_out("war_check",150);
 } else call_out("war_check",50);
 
}

void war_report()
{
 object obj1, where1;
 remove_call_out("war_report");
 if(this_object()->query("WarStart"))
 {
  obj1=find_living("halfshark");
  if(obj1) where1=environment(obj1);
  if(!where1)
  {
   remove_call_out("end_war");
   shout("\n\n"+HIM"               海妖一族全部被趕回海底去了\n\n"NOR);
   this_object()->delete("WarStart");
   return;
  }
  else
  {
   call_out("war_report",30);
  }
 }
}

void end_war()
{
 object obj1, where1;
 remove_call_out("end_war");
 remove_call_out("war_check");
 remove_call_out("war_report");
 this_object()->delete("WarStart");
 while(obj1=find_living("halfshark"))
 {
 	where1=environment(obj1);
 	if(where1)
 	{
   		message_vision("$N大笑幾聲便離開了.\n",obj1);
	}
	destruct(obj1);
 }
 shout("\n\n"+HIM"               海妖一族摧毀了海底城..\n\n"NOR);
 return;
}
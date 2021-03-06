#include <ansi.h>
inherit ROOM;

void can_north(int index);

void create()
{
  set ("short", HIR"朱漆石門"NOR);
  set ("long", @LONG
來到這高大的建築外，只見這建築外形氣派華貴宏偉，可能是某
位大有權勢之人的住宅。首先看到的是朱紅色的大門，此門高十六尺
，寬十尺，整扇門皆以赤青石製成，想必十分沉重，大門是關上的，
想要推開可能要花一番力氣。
LONG
);

  set("exits", ([
  "southwest" : __DIR__"room80",
  "southeast" : __DIR__"room84",
]));

  set("item_desc", ([
"大門" : "\n\t只見左右兩扇門上有各有一個鑰匙孔，左邊的鑰匙孔周圍塗滿了金漆，"+
         "\n\t右邊則是銀漆，也許\該去找合適鑰匙的來試試 (plug left 或 plug right)。\n\n",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

void init()
{
  add_action("do_plug","plug");
  add_action("do_pray","pray");
}

int do_plug(string str)
{
  object key, me = this_player(), ob = this_object();
  if( str != "left" && str != "right" ) return 0;

  if(me->is_busy()) return notify_fail("你正在忙。\n");
  me->start_busy(2);
  if(str == "left")
  {
    if(!key = present("gold key",me)) return notify_fail("你沒有合適的鑰匙喲！\n");
    message_vision(HIW"\n$N將$n插入金色鑰匙孔中....\n\n"NOR,me,key);
    ob->set("open_left",1);
    call_out("at_same_time",1,key,me);
    return 1;
  }
  if(str == "right")
  {
    if(!key = present("silver key",me)) return notify_fail("你沒有合適的鑰匙喲！\n");
    message_vision(HIW"\n$N將$n插入銀色鑰匙孔中....\n\n"NOR,me,key);
    ob->set("open_right",1);
    call_out("at_same_time",1,key,me);
    return 1;
  }
  return 1;
}

void at_same_time(object key, object me)
{
  if(!me || environment(me) != this_object())
  {
    tell_room(this_object(),"結果什麼事都沒發生.....\n");
    return;
  }

  if(!query("open_left") || !query("open_right"))
  {
    tell_room(this_object(),WHT"你聽到『喀』的一聲輕響，但沒發生任何事 .....\n"NOR);
    delete("open_left");
    delete("open_right");
    return;
  }

  if(key->query("id") == "silver key")
  {
    destruct(key);
    return;
  }
destruct(key);
  call_out("msg",1,0);
  return;
}

void msg(int index)
{
  string *str = ({
HIG"\n\t轟 ！ 門開了 ......... 一點點的小縫。\n\n"NOR,
HIG"但還是不足以讓人通行。\n"NOR,
HIR"\n看來只有 Plug & Pray 了，上天保佑。\n\n"NOR,
HIW"請開始禱告(pray)吧.........\n"NOR
});

  tell_room(this_object(),str[index]);
  index++;
  if(index < sizeof(str)) call_out("msg",3,index);
    else set("can_pray",1);
  return;
}

int do_pray()
{
  string *str, msg = "";
  int i, index;
  object env;

  if(!query("can_pray")) return 0;
  if(this_player()->is_busy()) return notify_fail("你正在忙。\n");
  this_player()->start_busy(1);

  str = ({
"萬能的上帝啊","聖母瑪麗蓮夢露","五月天的專輯最好聽了",
"佛祖保佑我","觀世音菩薩","隔壁的小黃","樓下的老王","其實",
"我是豬","我想吃正露丸","熬夜對身體不好。","我十八歲，我不抽煙。",
"夢幻七域真好玩，大家一起打廣告。",
"哇哈哈!! 哇哈哈!! 夢幻七域真有趣，哥哥姊姊都來玩。"
});
  index = random(2)+1;
  for(i=0;i<index;i++)
    msg += str[random(sizeof(str))];

  message_vision("$N虔誠的喃喃唸道： " +msg+ "\n",this_player());

  env = load_object(__DIR__"room92");
  if(random(20) == 7)
  {
    delete("can_pray");
    tell_room(this_object(),HIW"沉重的大門終於開了 ... 糟.... 小心！！！\n"NOR);
    can_north(1);
    if(!env->is_war()) env->start_war();
      else tell_room(this_object(),"小心跌倒！！\n"NOR);
  }
  return 1;
}

void reset()
{
  object env;
  env = load_object(__DIR__"room92");
  if(env->is_war()) return;

  delete("can_pray");
  delete("open_left");
  delete("open_right");
  can_north(0);
  ::reset();
}

void can_north(int index)
{
  string temp;
  mapping exits = query("exits");

  if(!index)
  {
    set("exits", ([
"southwest" : __DIR__"room80",
"southeast" : __DIR__"room84",
]));
    tell_room(this_object(),HIB"\n石門又緩緩的關上了 ...... \n\n"NOR);
    return;
  }

  temp = __DIR__"room89";
  if(mapp(exits)) set("exits", (mapping)exits + ([ "north" : temp, ]) );
    else set("exits", ([ "north" : temp, ]));

  tell_room(this_object(),HIW"\n轟，只見石門緩緩的打開了！！\n\n"NOR);
  return;
}

/*
int valid_leave(object me, string dir)
{
  if( dir == "north" && !userp(me) && me->query("id") != "ghost") return notify_fail("那裡只有玩家才能進去。\n");
  return ::valid_leave(me, dir);
}

*/

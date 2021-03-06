#include <ansi.h>
inherit ROOM;

string *str = ({"在","乾","易","象","至","坤","成","形","天","圓","地","方","萬","物","其","宗"});

string random_item();
void can_down();
void game_change(int index);

void create()
{
  set ("short", "石室");
  set ("long", @LONG
這是一個八尺見方的石室，看來並無甚特別之處，只見一面牆壁
上刻著數個極大的字：

　在 乾 易 象 至 坤 成 形 天 圓 地 方 萬 物 其 宗
　　　　　　　　　　　　　　　　                  －天機子
LONG
);

  set("exits", ([
"north" : __DIR__"room48",
]));

  set("item_desc", ([
"地板上的奇異圖形" : "\n地板上隱約畫了一個像是召回陣法的圖形，當你碰觸它時，它竟然亮了"+
                     "\n起來，此圖形若非刻意找尋，還真看不出來。\n\n",
"牆壁" : (: random_item :),
]));

  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_push","push");
  write("你似乎聽到『咯啦.... 』的一聲 ...\n");
}

int do_push(string arg)
{
  int i;
  object obj;

  if(!query_temp("can_push")) return 0;
  if(query_temp("game_now")) return notify_fail("這些字己無需再按了。\n");

  for(i=0;i<sizeof(str);i++)
  {
    if(arg != str[i]) continue;
    if(arg != query("item"))
    {
      write("一點動靜也沒有...\n");
      return 1;
    }
    if(!obj = present("eight mirror",this_player()))
    {
      write("你使出全身的力氣去按這個字，弄得滿頭大汗卻無法動其一分一毫，只得廢然而返。\n"+
            "只見字上有一個約巴掌大，八角形的洞，不知有何功\用。\n");
      return 1;
    }

    set_temp("in",obj->query("mirror_set_in"));
    set_temp("out",obj->query("mirror_set_out"));
    message_vision(HIW"\n$N將$n嵌在洞上，輕輕一按，【"+query("item")+"】字應聲而入，接著石室突然一陣劇烈搖動，過不久又回復平靜。\n\n"NOR,this_player(),obj);
    destruct(obj);

    call_out("eight_mirror",5);
    return 1;
  }
  write("你要按什麼？\n");
  return 1;
}

string random_item()
{
  string temp = "";
  mapping item = query("item_desc");
  int index, i;

  write(HIR"\n除了牆壁上刻的這些字，其他地方再也沒有甚特別之處，難道這些字.... ？\n\n"NOR);

  if(query_temp("can_push")) return "";

  index = random(12);
  for(i=0;i<sizeof(str);i++)
  {
    if(i==index)
    {
      set("item",str[i]);
      temp += NOR+WHT+str[i]+NOR+" ";
    }
    else temp += HIW+str[i]+NOR+" ";
  }

  if(mapp(item)) set("item_desc", (mapping)item + ([ "字" : temp+ "\n\n這些字看來有些古怪，似乎可以按(push)下去？\n", ]) );
    else set("item_desc",([ "字" : temp+ "\n\n這些字看來有些古怪，似乎可以按(push)下去？\n", ]) );

  set_temp("can_push",1);

  return "";
}

void reset()
{
  object env;
  env = load_object(__DIR__"room92");
  if(env->is_war()) return;

  if(query_temp("game_now")) return;

  tell_room(this_object(),HIC"\n洞又慢慢的關了起來 ......\n\n"NOR);
  set("exits", ([
"north" : __DIR__"room48",
]));

  set("item_desc", ([
"地板上的奇異圖形" : "地板上隱約畫了一個像是陣法的圖形，當你碰觸它時，它竟然\n亮了起來，此圖形若非刻意找尋，還真看不出來。\n",
"牆壁" : (: random_item :),
]));

  delete_temp("can_push");
  ::reset();
}

void eight_mirror()
{
  can_down();
/*
  game_change(0);
  tell_room(this_object(),HIR"\n只見一個石柱從地板上的奇異圖形中間升了起來！！\n\n"NOR);
  stone = new(__DIR__"npc/obj/obj23");
  stone->move(this_object());
  stone->accept_
*/
  game_change(1);     // 之後石柱寫好要刪掉, 上面要改回來
  return;
}

void can_down()
{
  string temp;
  mapping exits = query("exits");

  temp = __DIR__"room" + ( (string)random(4)+70 );
  if(mapp(exits)) set("exits", (mapping)exits + ([ "down" : temp, ]) );
    else set("exits", ([ "down" : temp, ]));

  tell_room(this_object(),HIR"\n地板上畫的奇異圖形突然裂了一個大洞！！\n\n"NOR);
  return;
}

void game_change(int index)
{
  object white, black, room;
  int i;
  if(!index)
  {
    set_temp("game_now",1);
    return;
  }

  delete_temp("game_now");
  tell_room(this_object(),HIG"\n地底不遠處傳來一些聲響。\n\n"NOR);

  white = load_object(__DIR__"room69");
  black = load_object(__DIR__"room67");
  white->can_down(1);
  black->can_down(1);

  // 以下這些程式碼在石柱寫好之後要刪掉
  // -----------------------------------------
  for(i=50;i<66;i++)
  {
    room = load_object(__DIR__"room"+i);
    room->change(random(8)+1);
  }
  // -----------------------------------------

  return;
}


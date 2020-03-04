#include <ansi.h>  
#include <room.h> 
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short","拱門前");  
 set("long",@LONG
這裡是巨形拱門前的門口, 中間的門縫, 似乎可以隱隱約約的透出光線, 說
是透明的拱門, 其實是中間的門縫透出的光線, 使得整片拱門看起來亮亮的
,  奇怪的是 . . . 門前旁, 竟然有一堆白骨(search), 原是看起來漂亮的拱門, 無形的蒙上一層鬼魅的氣氛。
 LONG
 set("exits", ([  
 "up": __DIR__"area2/room4",
 ]));
 set("item_desc", ([
     "" : "一堆白骨, 或許你可以從裡面找(search)到一點訊息。\n",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 create_door("north","透明拱門","south",DOOR_LOCKED,"key");
 setup();
}

void init()
{
 add_action("do_open","open");
}

int do_open(string arg)
{
 object me,jail,king;
 
 me = this_player();
 
 if(arg=="door" || arg=="north")
 {
  jail = load_object("underground/kingroom");
  if(!jail) return 0;
  king=present("king",jail);
  if(!king) return (int)call_other("/cmds/std/open", "main", me, arg);
  if(!call_other("/cmds/std/open", "main", me, arg)) return call_other("/cmds/std/open", "main", me, arg);
  message_vision("嘎嘎嘎嘎嘎....只聽見幾聲怪音....。\n",me);
  king->move(this_object());
  message_vision(HIW"$N(ant king)說:哈哈哈哈哈...多謝你放我出來!!\n",boy);
  message_vision(HIW"$n對$N說 : 讓我來答謝你吧 . . !\n"NOR,me,boy);
  tell_object(me,HIR"\n警告 ! ! ! ! 螞蟻王雙眼發紅的看著你 . . !\n\n"NOR);
  return 1;
 }
 return 0;
}

int do_search(object me,string arg)
{
 object key;
 if(!arg) return 0;
 if(arg == "skeleton")
 {
  if(this_object()->query_temp("key"))
  {
   message_vision("$N趴到白骨堆裡翻了翻, 滿無頭緒的爬了起來。\n",me);
   return 1;
  }
  message_vision("$N趴到白骨堆裡翻了翻..滿意的找到一根骨頭。\n",me);
  key = new("/u/m/moonhide/underground/key");
  key->move(this_object());
  this_object()->set_temp("key",1);
  return 1;
 }
 return 0;
}

void reset()
{
        this_object()->delete_temp("key");
        ::reset();
}


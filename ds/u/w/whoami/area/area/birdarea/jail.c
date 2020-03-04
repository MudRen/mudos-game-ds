#include <ansi.h>

#include <path.h>

#include <room.h>

inherit ROOM;

void create()
{
    set("short", "監牢");
        set("long", @LONG
這裡是一個監牢，四周的牆上掛滿了各式各樣的刑具，這裡
還充斥著一股惡心的屍臭味，看來似乎有不少人被刑求而死，眼
前還有兩個拿著鞭子的獄卒，看來變成那堆屍骨的時間也不遠了
LONG);
 set("item_desc",([
        "屍骨":"一個早已乾枯\的屍骨，他身上應該沒什麼值錢貨•\n",     ]));
set("no_recall",1); 
        setup();
}
int x = 1;
int room_effect(object me)
{
   int i;
   me=this_player();
   i=me->query_temp("superjail");
   if(me->query_temp("rich_jail") > random(10)) 
   {
      message_vision(HIB"$N趁獄卒拿起鞭子抽向$N，$N抓準時機趁獄卒重心不穩同時，從門口溜了出去•\n"NOR,me);
         me->delete_temp("rich_jail");
       me->move(__DIR__"rich1");
   }
   else {
    message_vision(HIR"獄卒拿起鞭子往$N身上抽去，打得$N皮開肉綻！\n"NOR,me);
     me->receive_damage("hp",random(50));  
     me->set_temp("rich_jail",i+1);
   }
}
void init()
{
  add_action("do_run","run"); 
  add_action("do_fly","fly"); 
  add_action("do_search","search");
  add_action("do_send","send");
}

int do_search(string arg)
{
        object me,item;
        me=this_player();
        if(arg != "屍骨") return 0;
        if( me->is_busy() ) return notify_fail("你的動作還沒有完成﹐不能做動作。\n");
        message_vision("$N不信邪的找了找屍骨，看看有沒有什麼寶貝•••\n",me);
        if(x != 0){
        item=new(__DIR__"npc/obj/seal");
           message_vision("找了又找，$N終於在屍骨裡找到"+item->query("name")+"•\n" ,me);
           x=0;
        item->move(this_player());
        } else
        {
                message_vision("$N找了又找，還是什麼也翻不出來..\n",me);
        }                               
        return 1;
}

int do_run()
{
  write("這裡是監牢！\n");
  return 1;
}
int do_fly()
{
  write("這裡是監牢！\n");
  return 1;
}
int do_send()
{
  write("這裡是監牢！\n");
  return 1;
}



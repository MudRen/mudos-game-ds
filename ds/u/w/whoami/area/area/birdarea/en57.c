#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG
你踩入泥沼區的同時你感覺到行動十分不便, 似乎快被泥沼
所吞噬, 四處散發著刺鼻的臭味, 讓人非常想吐. 你發現四處有
一些從未見過的昆蟲和植物, 不禁讚嘆大自然的奧妙.
LONG);
 set("exits",(["west":__DIR__"en56",
               "east":__DIR__"en58",
               "south":__DIR__"en62",
               "northeast":__DIR__"en54",
               "northwest":__DIR__"en52",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 set("can_summon",1);
 setup();
}        

void init()
{
        object ob;
        object me=this_player();
        if( objectp(ob=present("summon seal",me))) 
        tell_object(me,HIW"你身上的召喚符似乎對此地有反應•••\n"NOR);
        add_action("do_summon","summon");
}

int do_summon()
{
 object ob = this_object();
 object me = this_player();
 object ob1,ob2;
 if( objectp(ob1=present("summon seal",me)) ){

  if( objectp(ob2=present("corpse",environment(me))) )
  {
   message_vision("$N將祭品擺\在一旁，口中喃喃自語地唸著咒文•••\n",me);
   destruct(ob1);
   ob->set_temp("summoning",1);
   me->start_busy(5);
   call_out("gosummon",1,ob);
   } else {
   tell_object(me,"在召喚前應該先準備點祭品吧？\n");
   }
   
 } else {
 tell_object(me,"你身上又沒有召喚符•••\n" NOR);
        }
}

void gosummon()
{
 object ob=this_object();
 object me=this_player(); 
 object ob1= present("corpse",environment(me));
 object mob,mob1;
 int i = ob->query_temp("summoning");
   switch( i ) {
     case 1:
      message_vision(HIR"\n\n忽然間在$N身邊祭品消失了•••\n",me);  
      destruct(ob1); 
      ob->add_temp("summoning",i+1);
      call_out("gosummon",1,ob);
      break;
     case 2:
      message_vision(HIW"\n\n一陣陣低吼聲從$N身邊的沼澤中傳出•••\n",me);  
      ob->add_temp("summoning",i+1);
      call_out("gosummon",1,ob);
      break;
     case 3:
      if ( ob->query("can_summon") >= 1 ) {
      mob=new(__DIR__"npc/dark_crocodile.c");
      mob->move(environment(me));
      message("world:world1:vision", HIY+BLK"\n\t東北方的森林內傳來一陣低聲的怒吼∼∼\n\n"NOR,users());
      message_vision(HIW+BLK"突然間一隻"+mob->query("name")+HIW+BLK"從$N身邊竄了出來！！\n",me);
      call_out("summonagain",900,ob);
      ob->delete("can_summon");
      ob->delete_temp("summoning");
      } else {
      mob1=new(__DIR__"npc/h_crocodile.c");
      mob1->move(environment(me));
      message_vision(HIC"\n突然間一隻"+mob1->query("name")+HIC"從$N身邊跳了出來！！\n"NOR,me);      
      ob->delete("can_summon");
      ob->delete_temp("summoning");
      } 
          break;
     }
}            

void summonagain()
{ 
 object ob = this_object();
 ob->set("can_summon",1);
}


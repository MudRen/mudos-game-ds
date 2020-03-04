#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void end_war();
void start_war();

string *place=({"village1","village2","village3","village4","village5",
                "village6","village7","village11","village12","village10"
               });

void create()
{
 set("short","富宅一角");
 set("long",@LONG
這裡是這個住宅裡面最不起眼的角落，但是你的觀察力異於
常人還是發現了這個隱密的地點，在你的腳下似乎有一道暗門， 
不知道這面鐵製的暗門後面有著甚麼不可告人的秘密。 
LONG);

 set("exits",([ 
               "down":__DIR__"jail",
               "west":__DIR__"rich5", ]));  
 setup();
 create_door("down","鐵門","up",DOOR_LOCKED,"nokey"); 
}        

varargs int unlock_door(string dir, int from_other_side)
{
        object env,npc,me=this_player();
        if( :: unlock_door(dir, from_other_side) )
        {

        env=this_object();
        if(!objectp(npc=find_living("_Fox_Village_Guard_") ) && env->query("_Fox_Village_Guard_")==1 )
           env->delete("_Fox_Village_Guard_");
        if( me->query_skill("pick_lock") < random(120) && env && env->query("_Fox_Village_Guard_")!=1 )
        {
      message_vision("因為$N開鎖技巧的拙劣，一個不留神就驚動了監獄的守衛。\n",me); 
      message("world:world1:vision",
HIY"\n\t獄卒大吼道：該死的"+me->query("name")+"膽敢劫獄，不要命了！！\n"NOR,users() );
      message_vision("獵狐村富宅內的守衛傾巢而出，頓時之間平靜的獵狐村又掀起一股風暴。\n",me); 
          env->start_war(1);
          env->set("_Fox_Village_Guard_",1);
          
        }        
        }
        return :: unlock_door(dir, from_other_side) ;
} 

void start_war()
{
        int i;
        object g;
//巡邏守衛(patrol guard)  -> 5 隻
//----------------------------------
//合計(total)              -> 5 隻

        for (i=0;i<=4;i++)
        {
        g=new(__DIR__+"npc/patrol_guard");
        g->move(__DIR__+place[random(sizeof(place))] );
        } 

     call_out("end_war",60);
    return;
}

void end_war()
{
        object npc;
        if(objectp(npc=find_living("_Fox_Village_Guard_") ) )
        {
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else 
          this_object()->delete("_Fox_Village_Guard_");
return;
}



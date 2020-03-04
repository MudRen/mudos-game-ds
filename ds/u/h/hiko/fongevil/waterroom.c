#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);
int room_effect(object me);
void setroom()
{
       set("no_clean_up",0);
       set("light",1);
       set("no_map",1);
       set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
}  

void init()
{ 
      add_action("do_unsling","unsling");
}

int room_effect(object me)
{      
      int water,de,swim;
      de=me->query_dex()/14;
      swim=me->query_skill("swim",1)/18;
      if(!userp(me))  //玩家才會被打到
      return 0;
      if(de+swim>8)
         water=8;          
      else if(de+swim>=7)
         water=7;
      else if(de+swim>=6)
         water=6;
      else if(de+swim>=5)
         water=5;
      else if(de+swim>=4)
         water=4;
      else if(de+swim>=3)
         water=3;
      else if(de+swim>=2)
         water=2;
      else   
         water=1;
       if(water>6)
        water-=random(2);
       if(water<3)
        water+=random(2);
       if(random(2))
       switch(water){
    case 8: message_vision(HIB"$N看到前方出現一道水柱,$N靠極快速度閃過只有擦傷\n"NOR,me);
            me->receive_damage("hp",10+random(20));
            return 1;
    case 7: message_vision(HIB"$N被突然襲來的水柱攻擊,$N迅速迴轉避過只有一點傷\n"NOR,me);  
            me->receive_damage("hp",10+random(30));
            return 1;
    case 6: message_vision(HIB"忽然出現一團水球,$N快速閃過只有一些傷\n"NOR,me);
            me->receive_damage("hp",20+random(40));
            return 1;         
    case 5: message_vision(HIB"正前方嘩拉嘩拉衝出水,$N勉力閃過只有小傷\n"NOR,me);
            me->receive_damage("hp",30+random(40));
            return 1;         
    case 4: message_vision(HIB"$N身邊猛然出現水膜,$N往旁邊跳過受了創傷\n"NOR,me);
            me->receive_damage("hp",30+random(50));
            return 1;    case 3: message_vision(HIB"$N沒注意到身後出現水浪,$N被水擊傷了\n"NOR,me);
            me->receive_damage("hp",30+random(60));
            return 1;    case 2: message_vision(HIB"$N耐不住強大水壓,$N受了嚴重傷害\n"NOR,me);
            me->receive_damage("hp",40+random(60));
            return 1;                  
    case 1: message_vision(HIB"$N因為不斷吃水而嗆到,$N受了極大創傷\n"NOR,me);
            me->receive_damage("hp",50+random(60));
            return 1;   
    }       
}

int do_unsling(string arg)
{
        object me,ob,oproom;
        string open,moveto,cango;
        int fde,swim;
        me=this_player();
        ob=environment(me);
        open=ob->query("open_room");       
        cango=ob->query("can_go");
        fde=me->query_dex()/2; //敏捷/2
        swim=me->query_skill("swim",1)/4; //sk 游泳/4
        moveto=ob->query("move_room");
        if(!open) return 0;
        if(arg!="robe" && arg!="繩子") return notify_fail("你要放掉什麼?\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，無法專心應付此動作。\n");         
        if(!oproom=load_object(open)) return notify_fail("出問題了..快找wiz來\n");
        if(random(fde*3/2) + fde/2 + swim > 20+random(65))
          {
            message_vision(HIB"$N把繩子放開後,傳來一陣轟轟聲...水位消退不少\n"NOR,me);
            oproom->set(cango,1);
            return 1;
          }         else
          {
           message_vision(HIB"$N一時不注意被水柱衝擊到,竟然被沖走了\n"NOR,me);
           me->move(moveto);  
           return 1;
          }
}

int valid_leave(object me, string dir)
{
  object env=environment(me),*inv;
  mapping exits;
  int i; 
  inv = all_inventory(env);
  exits = env->query("exits");
  if(undefinedp(exits[dir])) return 0;
    for(i=0;i<sizeof(inv);i++)
   {
      if(living(inv[i]) && inv[i]->query("fong_guard")  )
      {
        if( inv[i]->is_corpse() ) continue;
        message_vision(HIW"$N衝了出來擋住你的去路\n"NOR,inv[i]);
        return notify_fail("");       
      }
   }
   if(env->query("high_water")==dir) //檢查是不是=高水位的方向
    {
      if(!env->query("can_go1") && !env->query("can_go2")) //檢查有沒有把水放開 
       { 
        message_vision(""+dir+"水位太高了$N無法渡過\n",me);
        return notify_fail("");
       }
      //標記刪除
      env->delete("can_go1");       env->delete("can_go2");
      message_vision("$N趁著水位消退時趕快離去\n",me);
      return ::valid_leave(me, dir);
    }
   return ::valid_leave(me, dir);
}









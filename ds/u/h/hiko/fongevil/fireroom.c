#include <ansi.h>
inherit ROOM;
int fire_move(object me);
int valid_leave(object me, string dir);
int room_effect(object me)
{      
      int fire,st;
      st=me->query_str()/15;
      if(!userp(me)) //非玩家不會被打到
      return 0;
      if(st>=7)
         fire=7;          
      else if(st>=6)
         fire=6;
      else if(st>=5)
         fire=5;
      else if(st>=4)
         fire=4;
      else if(st>=3)
         fire=3;
      else if(st>=4)
         fire=2;
      else 
         fire=1;
 
    if(fire>5)
       fire-=random(2);    
    if(fire<3)
       fire+=random(2);
       if(random(2))
       call_out("fire_move",2,me);
       switch(fire){
     case 7:                   message_vision(HIR"$N被突然襲來的火球襲擊,$N靠強大力量即時閃過只有擦傷\n"NOR,me);
            me->receive_damage("hp",10+random(10));
            return 1;
    case 6: message_vision(HIR"忽然出現一道火柱,$N反應快只有一點傷\n"NOR,me);
            me->receive_damage("hp",10+random(30));
            return 1;         
    case 5: message_vision(HIR"正前方轟的跑出一團火,$N迅速迴轉只有小傷\n"NOR,me);
            me->receive_damage("hp",20+random(40));
            return 1;         
    case 4: message_vision(HIR"$N腳邊冒出火苗,$N快速後退受了些傷\n"NOR,me);                        me->receive_damage("hp",30+random(50));
            return 1;         
    case 3: message_vision(HIR"$N一時不注意旁邊出現火焰,$N被燒傷了\n"NOR,me);                 me->receive_damage("hp",50+random(50));
            return 1;         
    case 2: message_vision(HIR"遠方出現紅光,$N來不及閃躲,被狠狠擊中\n"NOR,me);                 me->receive_damage("hp",60+random(60));
            return 1;        
    case 1:  message_vision(HIR"$N感到耐不住炎熱,一直被燒傷\n"NOR,me);                                       me->receive_damage("hp",40+random(100));
           return 1;  
      }       
}

int fire_move(object me)
{
        object env=environment(me);
        mapping exits;
        int fst=me->query_str();
        string *dirs;
        exits = env->query("exits");
        if(!me || me->is_fighting() || !userp(me)) return 0;
        if(env->query("boss")) //boss房不move 
        return 0; 
        if(fst/2>60) fst=60; 
        else fst=fst/2;        
        if(fst>20+random(60)) return 0;
        if( !mapp(exits) ) return 0;
        if( sizeof(exits) < 1 ) return 0;
        dirs = values(exits);
        message_vision(HIR"$N突然被火焰猛烈撞擊上去，一時收勢不住被撞飛了。\n"NOR,me);
        me->move(dirs[random(sizeof(dirs))]);           me->receive_damage("hp",10+random(20));                       tell_room(environment(me),"$N突然飛了過來，身上還帶著火花。\n",({me}));
        return 1;
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
   return ::valid_leave(me, dir);

}



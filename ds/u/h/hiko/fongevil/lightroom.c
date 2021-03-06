#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);
int room_effect(object me);
int check_light();
string look_mirror();
mapping turn_mirrors = ([        "north":                "北",
        "south":                "南",
        "east":                 "東",
        "west":                 "西",
        "northeast":            "東北",
        "northwest":            "西北",
        "southeast":            "東南",
        "southwest":            "西南",
        ]);
void setroom()
{      
       string *mirrors;
       mirrors=keys(turn_mirrors);
       set("no_clean_up",0);
       set("light",1);
       set("no_map",1);
       set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
       set("light_on",mirrors[random(sizeof(mirrors))]);
}  

void init()
{ 
      add_action("do_turn","turning");
}

int room_effect(object me)
{      
      int light,co;
      co=me->query_con()/15;
      if(!userp(me))  //玩家才會被打到
      return 0;
      if(co>8)
         light=8;          
      else if(co>=7)
         light=7;
      else if(co>=6)
         light=6;
      else if(co>=5)
         light=5;
      else if(co>=4)
         light=4;
      else if(co>=3)
         light=3;
      else if(co>=2)
         light=2;
      else   
         light=1;
       if(light>6)
        light-=random(2);
       if(light<3)
        light+=random(2);
       if(random(2))
       switch(light){
    case 8: message_vision(HIY"$N警覺到一道光柱襲來,$N體能強大只有擦傷\n"NOR,me);
            me->receive_damage("hp",15+random(20));
            return 1;
    case 7: message_vision(HIY"$N看到周圍光線不對勁,$N很快轉身逃過只有一點傷\n"NOR,me);  
            me->receive_damage("hp",15+random(30));
            return 1;
    case 6: message_vision(HIY"旁邊猛然出現一團光圈,$N恰巧閃過只有一些傷\n"NOR,me);
            me->receive_damage("hp",25+random(40));
            return 1;         
    case 5: message_vision(HIY"兩邊忽然冒出許\多光霧,$N靠體能硬是接下只有小傷\n"NOR,me);
            me->receive_damage("hp",35+random(40));
            return 1;         
    case 4: message_vision(HIY"$N身旁咻的一聲出現光羽,$N勉強接下受了創傷\n"NOR,me);
            me->receive_damage("hp",35+random(50));
            return 1;    
    case 3: message_vision(HIY"$N沒注意到身後出現光柱,$N被光燒傷了\n"NOR,me);
            me->receive_damage("hp",35+random(60));
            return 1;    
    case 2: message_vision(HIY"$N抵擋不住眾多光罩,$N受了嚴重傷害\n"NOR,me);
            me->receive_damage("hp",45+random(60));
            return 1;                  
    case 1: message_vision(HIY"$N因為不斷被光柱掃到,$N受了極大創傷\n"NOR,me);
            me->receive_damage("hp",55+random(60));
            return 1;   
    }       
}

int do_turning(string arg)
{
 object me,ob,aliroom,env;
 string turnof,str="",area;
 int lightno;
 me=this_player();
 env=environment(me);
 turnof=env->query("light_on");
 aliroom=env->query("light_room");
 lightno=env->query("light_number");
 area=env->query("light_area");
 if(me->is_busy() || me->is_fight())
 return notify_fail("你正在忙..沒空做這件事..\n");
 if(!lightno) return 0;
 if(!arg)
 return notify_fail("你想轉什麼?\n");
 if(undefinedp(turn_mirrors[arg]))
 return notify_fail("天照鏡不能轉那個方位\n"); 
 message_vision(HIY+"$N轉動了天照鏡,發出了一道黃色光芒\n"NOR,me);
 aliroom->set("list/"+lightno,arg);
 if(arg==turnof)
 if(aliroom->check_light())
 {
  str+="$N將天照鏡方位全部組合好了\n";
  str+="$N被一道光籠罩著...忽然消失了\n"; 
  me->move(__DIR__"folight_move");
  message_vision(HIR+str+NOR,me);
  load_object(__DIR__"folight_move")->set("pass/"+area,1); }
 return 1;
}

int check_light()
{
 int i;
 string lightpath,file,turnof,*list;
 mixed newturn;
 mapping rights;
 list=query("light_list");
 rights=query("list");
 lightpath="folight_";
 for(i=0;i<sizeof(list);i++)
 {
  file = resolve_path(__DIR__,lightpath+list[i]);
  file +=".c";
  turnof=load_object(file)->query("light_on");
  newturn = rights[list[i]];
  if(newturn==turnof) continue;
  else 
   return 0;
 }
 return 1;
}    

string look_mirror()
{
 string item,chitem,msg="",*mirrs;
 object me,ob;
 int co,anti;
 me=this_player();
 ob=this_object();
 item=ob->query("light_on");
 co=me->query_con();
 anti=me->query_skill("anti_poison")/10;
 mirrs=keys(turn_mirrors);
 if(co/2 + anti > random(65) ) chitem=turn_mirrors[item];
 else
 {
  mirrs-=({item});
  chitem=mirrs[random(sizeof(mirrs))];
  chitem=turn_mirrors[chitem];
 } 
 msg+="你看到天照鏡好像可以轉動(turning)，而且有一道光芒由";
 msg+=chitem+"方向照來。\n";
 return HIY+msg+NOR;
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










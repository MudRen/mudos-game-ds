/*   靈感源於  漫畫 -摺紙戰士- 【ＲＰＧ漫畫之神】周顯宗所畫*
 *   考慮作為未來的Class , 其特色為有趣, 不拘泥於一個角色的*
 *   限制, 如果可以, 將把它編為未來工會之一。              *
 *   此為一開始的信物摺紙, 其可以折成的精靈摺紙如: 龍族..等*
 *                            editor by kkeenn@ds 2002/6/1 */
#include <ansi.h>
inherit ITEM; 
void create()
{
  set_name("無色摺紙", ({ "none paper", "paper" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");
    set("long", " 
    這是一張已被尚未被折成任何東西的化身摺紙。
"HIG"摺紙：origami xxx"NOR"
"HIW"目前能折的精靈有：
"HIC"1.龍族(dragon)  2.花族(flower)  3.鶴族(bird)
"HIC"4.狼族(wolf)    5.兔族(rabbit)  6.魚族(fish)
"NOR);
    set("value",0);
    set("no_drop",1);
    set("no_sell",1);
    set("no_get",1);
    set("no_sac",1);
    set("no_give",1);
  }
   setup();
}
int query_autoload() { return 1; }
void init()
{ 
    add_action("do_origami","origami");
}
int do_origami(string arg) 
{
  object obj,me; 
  int limit;
  string race,word,file,gift;
  obj = this_object(); 
   me = this_player(); 
  file = __DIR__"paper2.c"; 
 if(!arg) return notify_fail("你到底想將它折成啥東西ㄚ？\n"); 
   if(me->query("family")) return notify_fail("你已經有精靈化身了。\n"); 
switch(arg)
{ 
case "dragon":
  limit = 60;
  gift = "fire";
  race = "龍族";
  word = "龍";
  break;
case "flower":
  limit = 15;
  gift = "wood";
  race = "花族";
  word = "仙";   //取材於道德經 花，乃世間之仙子也
  break;
case "bird":  //鳥...配合下面的字不太雅觀
  limit = 10;
  gift = "wind";
  race = "鶴族";
  word = "鶴";
  break;
case "wolf":
  limit = 24;
  gift = "electric";
  race = "狼族";
  word = "狼";
  break;
case "rabbit":
  limit = 30;
  gift = "earth";
  race = "兔族";
  word = "兔";
  break;
case "fish":
  limit = 41;
  gift = "water";
  race = "魚族";
  word = "魚";
  break;
default:
return notify_fail("精靈界沒有這隻精靈。\n");
break;
}
if(me->query_skill("origami") < limit ) 
         return notify_fail("你的摺紙技巧不足摺出" + word +"頭摺紙！\n"); 
      switch(random(10) + 1) 
     {
    case 1 : me->set("family/name","狂"+ word);
             break;
    case 2 : me->set("family/name","天"+ word);
             break;
    case 3 : me->set("family/name","魔"+ word);
             break;
    case 4 : me->set("family/name","暗"+ word);
             break;
    case 5 : me->set("family/name","神"+ word);
             break;
    case 6 : me->set("family/name","聖"+ word);
             break;
    case 7 : me->set("family/name","地"+ word);
             break;
    case 8 : me->set("family/name","火"+ word);
             break;
    case 9 : me->set("family/name","舞"+ word);
             break;
   case 10 : me->set("family/name","夢"+ word);
             break;
     }  
  me->set("family/race",race);
  me->set("family/gift",gift);   //決定使用法術的屬性
  me->set("family/id",arg);
       switch(me->query("level")/5) 
{
   case 1 :
 me->set("family/level",1);
 me->set("family/color","紫色");
             break;
   case 2 :
 me->set("family/level",2);
 me->set("family/color","靛色");
   break;

   case 3 :
 me->set("family/level",3);
 me->set("family/color","藍色");
   break;
   case 4 :
 me->set("family/level",4);
 me->set("family/color","綠色");
   break;
   case 5 :
 me->set("family/level",5);
 me->set("family/color","黃色");
   break;
   case 6 :
 me->set("family/level",6);
 me->set("family/color","橙色");
   break;
   case 7 :
 me->set("family/level",7);
 me->set("family/color","紅色");
   break;
   case 8 :
 me->set("family/level",8);
 me->set("family/color","白色");
   break;
   case 9 :
 me->set("family/level",9);
 me->set("family/color","黑色");
   break;
   case 10 :
 me->set("family/level",10);
 me->set("family/color","灰色");
   break;
}
message_vision(HIW"$N運用高超的技巧將一張無色摺紙折成了一隻"+ word +"頭摺紙！\n" NOR,me);new(file)->move(me);
destruct(obj);
return 1;
}


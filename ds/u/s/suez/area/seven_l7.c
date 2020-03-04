#include <ansi.h>
inherit ROOM;

void create()
{
 set("short","山壁");
        set("long",@LONG
你撞到山壁了！這裡十分荒涼，只有一張貼著符咒的大石，好像封印著什麼。
LONG
        );
        
        set("outdoors","land");
 set("item_desc",([
     "大石":"大石沒啥好看的，看看符咒吧！\n",
     "符咒":"你看著這個符咒時，突然聽到一個細微的聲音在你耳邊說：「撕下它(tear)撕下它(tear)...」\n"
     ]));
        setup();

 }
int n=1;
void init()
{
        add_action("do_tear", "tear");
}
int do_tear(string arg)
{
        object me,obj;
        me=this_player();

        if (arg != "符咒" && arg !="符" )
                return 0;
      if(n !=0) {
      message_vision(HIY"$N用力撕下符咒，只見一道金光由符咒中激射而出﹗﹗\n"NOR ,me);
       obj=new(__DIR__"npc/player-ghost");
       obj->move(environment(me ) );       
     message_vision(HIR"$P大笑：「哈哈哈﹗﹗終於自由了﹗﹗我要大鬧天下﹗﹗」\n"NOR,obj);
     n=0;
      }else
     {
      message_vision(HIW"$N正要撕下符咒時，突然向後退了幾步，似乎被什麼東西彈開的樣子。\n"NOR ,me);

        }
   return 1;
        }

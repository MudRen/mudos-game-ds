inherit ITEM;
#include <ansi.h>
void create()


{
        set_name(HIY"足球"NOR, ({"soccer", "soccer"}));
        set_weight(1000);
        set("unit", "顆");
        set("long", @LONG一個超強力足球
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("fire","kickout");
}
int fire(string str)
{



 object target,targetenv;
  object kickout;
  
  if(!str || str == "") return 0;
  target=present(str,environment(this_player()));
  if(!target) target = find_living(str);
  if(!target) {
  write(HIC+"帥哥,請瞄準了再說！！！\n"+NOR);
  return 1;}
  targetenv=environment(target);
  
  if(target != this_player())
   write(HIB + "你用力的往球踢去" + this_object()->query("name") + HIB + "把" +
        HIG + (string)target->query("name") + HIB + "踼出遊戲。\n"+
        this_object()->query("name") + HIW + "快速的飛往" + HIB + 
        (string)target->query("name") + HIB + "的方向飛去！！！\n"+NOR);
  else
  {
        write(HIW+"你不能踢自己。\n"+NOR);
        return 1;
  }
  tell_room(environment(this_player()),""+HIW+


       (string)this_player()->query("name")+HIC+
       "把一個足球放在地上，用力的一腳踹過去向"+HIW+
       (string)target->query("name")+HIC+"，飛起打在"+ HIW +
        (string)target->query("name")+HIC+"的屁屁上！\n"
       ,({this_player(),target}));
  tell_object(target, 
HIR+"\n你的眼前一黑﹐接著什麼也不知道了....\n\n"+NOR+
"你醒來時發覺自己已被踢出遊戲，依稀記得屁屁上給人踹了一腳。\n"
);
        target->move("/u/p/promise/workroom");
  
  return 1;
}


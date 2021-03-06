#include <ansi.h>
inherit ITEM;

void create()
{   set_name("遙控器",({ "control" }));
    set("no_drop",1);
    set("can_give",1);
    set("unit","個");
    set("value",0);
    setup();
}

int query_autoload() { return 1;}

void init()
{
   add_action("do_gome", "gome");
   add_action("do_dhome", "gohome");
   add_action("do_control", "ct");
   add_action("do_where", "mary");
}

int do_gome()
{
   object me,dog;
   dog = find_living("_NPC_MARY_");
   me = this_player();

   if(!dog) return notify_fail(dog->query("name")+"不存在於區域中。\n");

   message_vision("$N在$n耳邊小聲地說了些話。\n",dog,me);
   tell_room(environment(dog), "轉眼間"+dog->query("name")+"不知道跑哪去了...\n");
   dog->move(environment(me));
   return 1;
}

int do_dhome()
{
   object room,dog;
   dog = find_living("_NPC_MARY_");
   room = find_object("/obj/board/fedex_b");

   if(environment(room) != environment(dog))
   {
      message_vision("$N摸摸鼻子, 回到自己的工作室。\n",dog);
//      ob->set_name(HIY"奶油犬"NOR ,({ "butter dog","dog" }));
      dog->move(environment(room));
      message_vision("$N回到工作室了。\n",dog);
   }
   else { write(dog->query("name")+"已經在工作室了。\n"); }
   return 1;
}

int do_control(string arg)
{
   string cmd;
   object ob,me,dog;
   me = this_player();
   dog = find_living("_NPC_MARY_");

   if(!arg || sscanf(arg, "%s",cmd) != 1 )
      return notify_fail("指令格式﹕ct <指令>\n");
   if(!dog) 
      return notify_fail("找不到"+dog->query("name")+"無法執行命令。\n");
   if(!(ob = present(dog, environment(dog))))
      return 1;
   dog->force_me(cmd);
  return 1;
}

int do_where()
{
  int i,idle;
  string status1,status2,status3,status4,status5,status6,status7;
  object room,dog,*who;

  dog = find_living("_NPC_MARY_");

  if(!dog) return notify_fail("找不到目標。\n");

  room = environment(dog);
  who = all_inventory(environment(dog));

  if(!who) return 1;
  write(dog->query("name")+"目前正在"+room->query("short")+" - ("+file_name(room)+")\n");
  write("　　"+room->query("long")+"\n");
  for(i=0;i<sizeof(who);i++)
  {
     if(who[i] == dog) continue;
     if(environment(who[i]))
     {
//        idle = query_idle(who[i]);   //執行時段錯誤﹕*query_idle() of non-interactive object.
        write("  ");
        if(who[i]->query("title")) write(who[i]->query("title")+" "); 
        if(who[i]->query("nickname")) write("「"+who[i]->query("nickname")+"」");
        write(who[i]->query("name")+"("+who[i]->query("id")+")");
//        if(query_idle(who[i])) status1 = HIY"(發呆中)"NOR;
//          else status1 = "";
        if(who[i]->query_temp("invis")) status2 = HIB"(隱形)"NOR;
           else status2 = "";
        if(who[i]->query_temp("hide")) status3 = WHT"(躲藏)"NOR;
           else status3 = "";
        if((in_edit(who[i]))) status4 = sprintf(HIY"([編輯]: %s)"NOR,in_edit(who[i]));
           else status4 = "";
        if(in_input(who[i])) status5 = HIC"<輸入>"NOR;
           else status5 = "";
        if(who[i]->query_temp("killer")) status6 = HIR"[殺人犯]"NOR;
           else status6 = "";
        if(who[i]->is_inactive()) status7 = HIW"[閒置]"NOR; 
           else status7 = "";
        write(sprintf("%s%s%s%s%s%s\n",status2,status3,status4,status5,status6,status7));
     }
  }
  return 1;
}

#include <ansi.h>
#define IN_ROOM "/open/world1/god_club/eldership"

inherit NPC;
inherit SELLMAN;
int qwiz(string arg);

void create()
{
        set_name(HIY"Mr.金手指"NOR, ({ "game master","man","master" }) ); 
        set("level",30);
        set("age",45);
        set("gender", "男性"); 
        set("race", "human");        
        set("long",HIR"似乎可以從她身上拿到什麼東西？\n"NOR);
        set_temp("freeze",1); 
        set_temp("float",1);
        set("sell_list",([ 
               "/open/always/god_mark" : 1,
               "/open/always/sky_mark" : 1,
               "/open/always/doll"     : 1, 
        ]) );
        setup(); 
 }

void init()
{       
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() )
    {
       remove_call_out("meeting");
       call_out("meeting", 1, ob);
       call_out("qwiz",0);
    }
    add_action("do_fuck","fuck");
    add_action("do_sex","sex");
    add_action("do_doll","doll");
    add_action("do_list","list");
    add_action("do_buy","buy");
}
  
void meeting(object ob)
{
   string id;
   object me = this_player();
   id=me->query("id");
   if( id == "fedex"  ) 
   { 
      message_vision("$N恭敬的對$n說：老闆您回來拉！\n"NOR,this_object(),me);
      this_object()->set("creater",me); 
   }
   else
   {
      message_vision(HIY"$N"NOR+"皺著眉頭對$n說：你是誰？\n"NOR,this_object(),me);
   }
}

int do_fuck(string arg)
{
   object me;
   me = this_player();
        
   if(arg!="game master" && arg!="master" )
   { return notify_fail("你要幹嘛？\n"); }

   message_vision("$N用輕藐的口氣對$n說：你是在看啥小？\n",me,this_object());
   tell_room(environment(me),HIW"疑？！"+me->name()+"怎麼突然不見了？？\n"NOR,({me}));
   me->move(IN_ROOM);
   write(HIG"你到了長老室。\n"NOR);
   tell_room(environment(me),HIW+me->name()+" 從工作室走了過來。\n"NOR,({me}));
   return 1;    
}

int do_doll(string arg)
{
   object me,obj;
   me = this_player();
   obj = new("/open/always/doll");
   message_vision("$N偷偷拿了一"+obj->query("unit")+obj->name()+"給$n。\n",this_object(),me);
   obj->move(me);
   return 1;     
}

int do_sex(string arg)
{
   object me,obj; 
   me = this_player();
   obj = new("/obj/money/coin");    
   obj->move(environment(me)); 
   message_vision("$N丟下一"+obj->query("unit")+obj->name()+"。\n",this_object());
   return 1;    
}

int qwiz(string arg)
{
   int i,j=1,n,idle;
   object *user_list,where;
   string status1,status2,status3,status4,status5;
   user_list = users();
   n = sizeof(user_list);
   write(sprintf("◎"HIC"夢幻七域"NOR"   %s\n",ctime(time())));
      write("──────────────────────────────────────────────────\n");
       for( i=0 ;i<n ;i++)
       {
           if(wizardp(user_list[i]))
           {
              where = environment(user_list[i]);
              idle = query_idle(user_list[i]);
              if(user_list[i]->query_temp("invis")) status1=HIB"(隱形)"NOR;
                  else status1="";                         
              if(idle>=60) status2=sprintf(HIY"(發呆"+"%d"+"分鐘)"NOR,idle/60);
                  else status2=""; 
              if((in_edit(user_list[i]))) status3 = sprintf(HIY"([編輯]: %s)"NOR,in_edit(user_list[i]));
                  else status3="";
              if(in_input(user_list[i])) status4=HIC"<輸入>"NOR;
                  else status4="";
              if(user_list[i]->query_temp("netdead")) status5=HIB"(斷線)"NOR;
                  else status5="";
              write(sprintf("%12s "WHT+"%10s"NOR+"(%10s) 正在 %s(%s)%s%s%s%s%s\n",RANK_D->query_rank(user_list[i]),
                  user_list[i]->query("name"),
                  user_list[i]->query("id"), 
                  (string)where->query("short"),
                  (string)file_name(where),
                  status1,status2,status3,status4,status5)); 
                  j++;
           }
       }
       write("──────────────────────────────────────────────────\n");
       this_player()->start_more(sprintf("目前共有 %d 位wiz在線上.\n",j-1));
       return 1;
}

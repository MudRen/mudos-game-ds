#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(YEL"老舊的木盒"NOR,({"old box","box"}));
     set_weight(1); 
     set("long",HIC"一個老舊不堪的木盒子，不過它已上鎖，鑰匙不知道去哪了(toopen)。\n"NOR);
     set("no_sell",1); 
     set("no_give",1); 
     setup();
}
void init()
{ 
     add_action("do_open","toopen");
}
int do_open(string arg)
{ 
    object me=this_player(),key;    
    if(arg == "box")   
    {    if(!objectp(key=present("wood key",me) ) ) return notify_fail("你沒有鑰匙要怎麼開呀?\n"); 

      switch(random(3))
      {
       case 0:
              message_vision(YEL"$N將木製鑰匙插入鎖內轉了一下，但是因為其太過老舊，竟不堪斷裂了！？\n"NOR,me);
              destruct(key);
              return 1;
       case 1:
              message_vision(HIY"$N將木製鑰匙插入鎖內轉了一下，突然黃光一現！$N嚇的差點把盒子掉在了地上\n"NOR,me);  
              tell_object(me,"一個個活像真人似的武者，手中都拿著一把斧頭，盡情揮舞。\n");   
              tell_object(me,"強大的經神壓力迎面而來！不知道撐不撐的過來！\n"); 
              call_out("do_eee",2,this_object());  
              me->start_busy(8);
              destruct(key); 
              return 1;
      }  
    }
} 

int do_eee(object me, string arg)
{ 
        me=this_player();
        switch(random(3))
        {
                
         case 0:        message_vision("$N的頭突然昏了一下...\n",me);  
                        destruct(this_object());
                        return 1;
         
         case 1:        message_vision("$N嘆了口氣，擦了擦額頭的汗。\n",me);  
                        tell_object(me,HIY"新技能學得『 連砍 』\n"NOR);
                        me->set_skill("lan_pu",1+random(9)); 
                        destruct(this_object());
                        return 1; 
         default:       return 1;
        }
}


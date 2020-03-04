inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
set("short", HIC"Ａｏｅ"HIW"工作間"NOR);
  set("long",
"這間工作室供給那些有"HIR"問題"NOR"想"HIC"問"HIW"Ａｏｅ"NOR"的人一個可以發問的地方
，不管是任何問題，只要"HIW"Ａｏｅ"NOR"會的，他都會盡力回答，不過他最近
實在太忙了，如果問題一直得不到回應，"HIM"請耐心等候"NOR"吧。"HIG"Ｓｏｒｒｙ
Ａｔ　Ａｌｌ∼∼\n\n"NOR);
set("exits", ([
"wiz" : "d/wiz/hall1",
  "mulder" : "/u/m/mulder/workroom.c",
  "mail" : "/open/world1/tmr/area/post_office",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
call_other("/obj/board/aoe_b", "?!?!");
}
void init()
{
        object me;
        seteuid(getuid());
        me = this_player();
        if (me)
        add_action("do_qwiz","qwiz");
}

int do_qwiz(string arg)
{
        int i,j=0,n,idle;
        object *user_list,where;
        string status1, status2, status3;

        user_list = users();
        n = sizeof(user_list);
        write(HIY"YELLOW LCD"NOR"閃爍著，掃瞄器正在找尋其他wiz....\n");
        for( i=0 ;i<n ;i++)
        {
                if( wizardp(user_list[i]))
                {
                        where = environment(user_list[i]);
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIY"(INPUT)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i])))
        status2=sprintf(HIY"(EDIT: %s)"NOR,in_edit(user_list[i]));
                                else status2="";
                        if (idle>180) status3=sprintf(HIY"(IDLE %d MIN)"NOR,idle/60);
                                else status3="";
                        write(sprintf("TTF [ %2d %12s %s(%s) 正在 %s(%s) ]\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where)));
                        if ((status1!="")||(status2!="")||(status3!=""))
                        write(sprintf("TTF [                STATUS: %s%s%s]\n",
                                      status1,status2,status3));
                        j++;
                }
        }
        return 1;
}
/*
// 可以用來做特殊效果(如燙傷,凍傷,中毒,補血,或是定時訊息)
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 7:        message_vision("∼喵嗚∼∼哇靠!!　$N突然被一隻路過的貓抓了幾下。\n",me);
                        me->receive_damage("hp",random(3)+1);
                        return 1;
         case 6:        message_vision("∼咻∼∼ＯＵＣＨ!!　$N突然被一顆蘋果砸到頭。\n",me);
                        me->receive_damage("mp",random(3)+1);
                        return 1;
         case 5:
         case 4:        tell_object(me,"∼咻∼∼一隻貓突然飛奔過去。\n");
                        return 1;
         
         case 3:
         case 2:        tell_object(me,"∼咻∼∼一顆蘋果從身後的蘋果樹掉下來。\n");
                        return 1;
         case 1:
         case 0:        message_vision("$N開始楞楞的發起呆來。\n",me);
                        return 1;
   
         default:       return 1;
        }
}
*/

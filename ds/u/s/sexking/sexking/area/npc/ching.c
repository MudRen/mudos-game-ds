#include <ansi.h>
inherit NPC;
void create()
{
             set_name(HIG"淺井拓也", ({ "ching gin"NOR,"gin","ching"NOR}) );
             set("level",30);
             set("combat_exp",5000);
             set("long" ,"他是一位付責看管扶桑浪人營入口的高手..長的一付很正派的樣子。\n"
                         "他十分的尊敬很強的人但也十分輕視沒用的人..如果你認為你是強者的話\n"
                         "可以"HIR"爆發(burst)"NOR"自己雄厚的"HIC"功\力"NOR"給他看看。\n");
             set("age",39);
             set("gender","男性");
             set_skill("blade",90);
             set_skill("dodge",90);
             set_skill("parry",50);
             set_skill("combat",100);
             set("talk_reply","請不要煩擾我..我得專心的盡忠職守。");
             set("chat_chance",8);
             set("chat_msg", ({
  name()+"半開玩笑的說:想過去?跟我下跪(Kneel)吧.....。\n",
  name()+"專心的尋顧四周的動靜，一草一木也不放過。\n"NOR,
  (: command("think") :),
  }) );
setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
       }
void init()
{
       object me;
       ::init();
       if(interactive(me = this_player()) && !is_fighting()) 
       {
       remove_call_out("man");
       call_out("man",1,me);
       }
       add_action("do_guard", "go");
       add_action("do_knee","Kneel");
       add_action("do_burst","burst");
}
int do_guard(string arg)
{
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        {
        if(this_player()->query_temp("nice")>=1)
        { 
        message_vision(HIM"淺井拓也恭恭敬敬的說:這位請英雄請了...。\n"NOR,this_player());
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        } 
        if(this_player()->query_temp("bad")>=1)
        {
        message_vision(HIM"淺井拓也笑著說:小卒仔走慢點別摔著了...。\n"NOR,this_player());
        command("hoho");
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        }
         else
        {
        write( name() + "將你擋了下來。\n");
        command("no");
        say("淺井拓也說道："HIR"這裡不是你該來的地方！！\n"NOR);
        return 1;
  }
}
}
int do_knee(string arg)
{
     if(arg!="gin")
     {
                notify_fail("請用Kneel (人名)\n");
                return 0;
     }
     if(this_player()->query_temp("nice")>=1)
     {
     message_vision(HIG"淺井拓也驚荒失措的說:不敢當.不敢當.請起請起!\n"NOR,this_player());
     return 1;
     }
     else
     {     
     message_vision(HIG"$N對著淺井拓也恭恭敬敬的跪了下去..。\n"NOR,this_player());
     call_out("kneel1",3,this_player());
     return 1;        
     }
}
void kneel1(object me)
{
     if(!me) return;
     message_vision(HIC"淺井拓也對笑著說:哈哈哈!你真的是個卒仔ㄟ..過去吧..。\n"NOR,me);
     me->move("/u/s/sexking/sexking/area/map_2");
     me->set_temp("bad",1);
     tell_room(environment(me),me->name()+"突然跌跌撞撞的跑了進來。\n",({me}));
     return;
}
int do_burst(string arg)
{
        if(arg!="功\力")
        {
                notify_fail("你要爆發功\力請打 burst 功\力\n");
                return 0;
        }
        if(this_player()->query("level") >25)
        {
        message_vision(HIY"$N爆發出自己雄厚的內勁以及功\力..看得淺井拓也眼花潦亂。\n"NOR,this_player());
        message_vision(HIC"$N的功\力使淺井拓也不知不覺得拍手叫好...。\n"NOR,this_player());
        this_player()->start_busy(2);
        this_player()->set_temp("nice",1);
        call_out("go",3,this_player());
        return 1;
 } 
        else
        {
        message_vision(HIR"$N現出了三腳貓的功\夫在淺井拓也面前舞了一舞。\n"NOR,this_player());
        message_vision(HIC"看得淺井拓也哈哈大笑。\n"NOR,this_player());
        this_player()->start_busy(1);
        call_out("go2",4,this_player());
        return 1;
}
}
void go(object me)
{
     if(!me) return;
     message_vision(HIM"淺井拓也驚訝的說:哇!你果然是一名英雄,歡迎歡迎!.失禮了...。\n"NOR,me);
     me->move("/u/s/sexking/sexking/area/map_2");
     tell_room(environment(me),me->name()+"滿面光采,走路有風的走了過來。\n",({me}));
     return;
}
void go2(object me)
{
     if(!me) return;
     message_vision(HIY"淺井拓也很不爽的說:你當我三歲小孩喔?這種三腳貓的功\夫也拿出來現醜...。\n"NOR,me);
     return;
}
void man(object me)
{
if(this_player()->query_temp("nice")>=1)
{
message_vision(HIC"淺井拓也恭敬的說:你是"HIY + me->name(1) + NOR""HIC"大俠吧..我已經見識過你的實力了..請進請進!\n"NOR,me);
return;
}
if(this_player()->query_temp("bad")>=1)
{
message_vision(HIC"淺井拓也笑咪咪的說:你就是"HIY + me->name(1) + NOR""HIC"小卒仔喔?就算你進去也沒人會注意你的存在的..\n"NOR,me);
command("hoho");
tell_object(me,HIR"你突然一肚子火..不知道此羞辱何時能討回來。\n"NOR);
return;
}
}




#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
        set_name( "車長" , ({ "trainman","man" }) );
        set("long",@long
他是一個駕駛連接主城到礦區的地下鐵的列車長。看來約五十歲上下
，滿臉滄桑的樣子。
long
);

        set("age", 50);
        set("level", 5);
	set("gender","男性");
	set("race","human");
        setup();
        call_out("do_train",60,"train_station",0);
}


void do_train(string arg,int flag)
{
        object ob;
        ob=this_object();
if(flag==0)
{
        command("say 你們坐好，現在開車了。");
        ob->set_temp("do_train",arg);
        ob->move(__DIR__"train");       
        command("say 你們坐好，現在開車了。");
        tell_room(environment(ob),"車長按下一個按鈕，鐵路即時開動。\n");
        environment(ob)->set("exits",([]) );
        call_out("do_train",20,arg,1);
}
else
{
        message_vision("你感到車速開始變慢，看來快到達了。\n",ob);
        command("say 到達了，大家快下車吧。");
        environment(ob)->set("exits",(["out":__DIR__+arg]) );
        ob->move(__DIR__+arg);
        if(arg=="train_station1") arg="train_station";
        else arg="train_station1";
        call_out("do_train",60,arg,0);

}
        return;
}
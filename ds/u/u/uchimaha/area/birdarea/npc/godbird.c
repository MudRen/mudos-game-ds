#include <ansi.h>
inherit NPC;
void create()
{
 set_name("神梟",({"god bird","god","bird"}));
 set("long","他是傳說中的大鳥，沒人之知到牠從何處來，也沒
人知道牠是哪種鳥，大家只因為牠的身型奇特、體
型高大，而給他一個稱號為﹝神梟﹞，他看起來肚
子餓了，傳聞中他喜歡吃一種綠色的小蟲。\n");
 set("age",235);
 set("race", "野獸");
 set("level",30);
 set("title","傳說之鳥");
 set("limbs", ({ "頭部", "身體", "翅膀", "腳", "尾部" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("evil",-50);
 set("dodge",70);
 set("parry",70);
 set("chat_chance",10);
 set("chat_msg", ({"神梟肚子咕嚕咕嚕的響了起來~~~~~~\n",
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "green worm")
        {
           command("slap "+who->query("id"));
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 嘰嘰，嘰嘰嘰嘰吱吱吱﹝我正在忙，請你等一下﹞。\n");
             return 0;
           }
             message_vision("$N給了神梟一條 "+ob->query("name")+"。\n",who);
             command("lick");
             obj->start_busy(6);
             obj->set_temp("giveworm",1);
             destruct(ob);
             call_out("giveworm",1,who);
return 1;
        }
}
void giveworm()
{
      int i;
      object me,obj,worm;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveworm");
       if( !me || environment(me) != environment(obj) )
        {
                command("say 吱吱吱吱吱？？﹝咦？" + RANK_D->query_respect(me) + "人呢？？﹞");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"神梟張大了眼瞧了瞧這條蟲。\n"NOR);
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 2:
            command("say 吱吱嘰嘰﹝就是這種蟲﹞。");
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",2,me);
            break;
          case 3:
            say(HIY"神梟一邊吃著這條蟲、一邊很高興的看著你。\n"NOR);
            command(":)");
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 4:
            say(HIY"神梟在樹洞中東翻西找的好像在找尋什麼。\n"NOR);
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 5:
            command("say 吱吱喳喳嘰嘰﹝這個送給你﹞。");
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 6:
            worm=new(__DIR__"obj/fur2");
            worm->move(obj);
            command("give fur to "+ me->query("id") );
            obj->delete_temp("giveworm");
            break;
          }
}


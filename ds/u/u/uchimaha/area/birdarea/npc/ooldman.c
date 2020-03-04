#include <ansi.h>
inherit NPC;
void create()
{
 set_name("老人",({"oldman"}));
 set("long","他是一位曾經闖蕩江湖的男子，自從他的左手被仇家從肩砍斷後
，便一直隱居在這裡，成為一個鐵匠，他的夢想就是打造一把神
兵利器，但是他好像缺少了什麼....\n");
 set("age",72);
 set("gender","男性");
 set("level",20);
 set("title","獨臂鐵匠");
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",10);
 set("chat_msg", ({"獨臂老人拿起手中的鐵箝嘆了一口氣.\n",
                   (:command("sigh"):),
 }));
set("chat_chance_combat",200);
 set("talk_reply","你能幫老夫一點忙(help)嗎?\n");
 set("inquiry/help","我現在在打造"HIG"陰陽劍"NOR"，但是缺了種石頭，叫"HIG"陰陽鐵石"NOR"，只有這種石頭才能打造出
陰陽劍。\n");
set("inquiry/精鐵石","你可以去東北澤林的泥沼區碰碰運氣，那裡有不少的鐵石•\n");
set("inquiry/陰陽鐵石","是由"HIG"陰陽石"NOR"與"HIG"精鐵石"NOR"用內力融合而成的珍貴寶物•\n");
set("inquiry/陰陽劍","嘿嘿....等到你幫我拿到陰陽鐵石時，你就會知道了•\n");
set("inquiry/陰陽石","聽說在北方的洞穴中，但是去的路卻找不到了•\n");
set("chat_msg_combat",({                         
                         (:command,"say 你太小看我了!!":),
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "陰陽鐵石")
        {
           command("slap "+who->query("id"));
           command("say 你給我這個是啥啊....-.-");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了老人一個 "+ob->query("name")+"。\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"老人摸了摸這塊石頭。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say 謝謝你阿，小兄弟。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"老人拿起了一把劍，開始打造那把劍。\n"NOR);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"過了一會獨臂老人手上多了一把發著藍光和紅光的劍。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            command("say 我的夢想已經完成了，這把劍在不在我身邊已經不重要了，我就把它給你吧。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/sword");
            plate->move(obj);
            command("give sword to "+ me->query("id") );
            me->add("popularity",3);
            me->add("exp",20000);
            tell_object(me,HIW"(你完成此任務，得到了 20000 點EXP 與 3點聲望。)\n"NOR);
            obj->delete_temp("givehat");
            break;
          }
}


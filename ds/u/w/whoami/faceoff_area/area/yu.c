#include <ansi.h>
inherit NPC;
void create()
{
set_name("余滄",({"yu chen","yu","chen"}));
set("long",@LONG
這是一個在無砂名聲響噹噹的鹽梟, 但他到底是黑道白道
到今天還是眾說紛紜, 不過可信的是, 在無砂尚未有海政司之
前, 余滄倒是相當公平的處理貧富之間的糾紛, 也因此得罪了
不少富人, 因此相當不滿於今日站在富人群中, 壓榨窮民的王
霸, 幸虧余滄早年曾得一高人指點刀法, 才能在無砂中不受王
霸的鏟除.
LONG
    );
 set("attitude","peaceful"); 
 set("title",HIY"鹽俠"NOR);
 set("age",51);
 set("gender","男性");
 set("level",30);
 set_skill("blade",90);
 set_skill("sea-blade",100);
 map_skill("blade","sea-blade");
 set_skill("force",60);
 set_skill("combat",70);
 setup();
 carry_object(__DIR__"eq/dragon_blade")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
}

void want_kill()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("want_kill");
      switch( i ) {
          case 1:
            command("say 哪個小賊敢闖入此處 !!");
            obj->set_temp("want_kill",i+1);
            call_out("want_kill",2,me);
            break;
          case 2:
            message_vision(YEL"余滄惡狠狠的望向$N。\n"NOR,me);
            obj->set_temp("want_kill",i+1);
            call_out("want_kill",2,me);
            break;
          case 3:
	    command("say 敢情小子是官府派來的 ..?!");
            command("say 老子在問你話, 難道連點頭搖頭都不會 ...?");
            command("hmm");
            obj->set_temp("want_kill",i+1);
            call_out("want_kill",3,me);
            break;
          case 4:
            command("say 小賊敢情是活得不耐煩了 !");
	    command("kill "+me->query("id") );
	    obj->delete_temp("want_kill",i+1);
            break;
            }
}

#include <ansi.h>
inherit NPC;
void create()
{
          set_name("揚躍文", ({ "yang-yao-wen","yang","wen" }) );
          set("long",@LONG
  錟都城的太守，是錟都城中最大的長官，好文厭武，是個書呆子，
  不過父親卻是個武林中人，而且還是個極負盛名的武林高手，不單如此
  他的母親也是個江湖上響噹噹的人物。面對這樣的家庭，揚躍文可說是
  受盡壓力，因為啊，家裡的人個個都希望有朝一日，揚盜文能雄霸武林
  啊。所以揚躍文再受盡壓力下，在18歲那年離家，音信全無。過了十年
  後，揚躍文當上了錟都城的太守，才開始有了消息。他的雙親也放棄了
  ，逼他習武的念頭，一家人就隨著他遷居到錟都。
LONG
          );
          set("level",35+random(5));
          set("age",35);

          set("combat_exp", 290000);
          set("chat_chance", 10);
          set("chat_msg", ({
    (:command("say 苦惱啊"):),
    (:command("sigh"):),
  }));
          set("inquiry/井","閣下若想知道，大可自行下去，不必理會本官.\n");
          set("inquiry/well","閣下若想知道，大可自行下去，不必理會本官.\n");       
          
          set_skill("whip", 100);
          set_skill("parry", 80);
          set_skill("unarmed", 80);
          set_skill("dodge", 80);

          setup();
          carry_object(__DIR__"obj/whip")->wield();
          carry_object(__DIR__"obj/cloth")->wear();
  }
int special_attack(object me,object target,int hitchance)
  {
      int tdex,tcon; 
     if(!me || !target) return 0;
      if(random(5)) return 0;
      tdex=target->query_dex();
      tcon=target->query_con();
      if(random(hitchance/2) > tdex+tcon)
      {
        message_vision("\n"
                       +HIC"$N突然目露金光，背後顯現出金蟬形象，張嘴一吐射出蟬絲，嘗試想要包住$n..\n"
                      +"$n發現自己跟石頭一樣，無法移動!!!\n"NOR
                      ,me,target);
        target->start_busy(5);
        return 1; 
      }
      else
      {
        message_vision("\n"
                      +HIC"$N突然目露金光，背後顯現出金蟬形象，張嘴一吐射出蟬絲，嘗試想要包住$n..\n"
                      +"但是$n在千鈞一髮之際往右急閃......\n\n"NOR
                      ,me,target);      
              return 1;
      }
}
int accept_object(object who, object ob)
{
        object tob, a;
        tob = this_object();
        if( ob->query("id")!="letter" || query_temp("letter") ) return 0;

        command("thank "+who->query("id"));
        command("say 謝謝你了，"+RANK_D->query_respect(who)+"！\n");
        who->add("exp", 10000);
        set_temp("letter",1);
        tell_object(who,HIR"你得到 10000 點經驗值。\n"NOR);
        call_out(
"delay",600,this_object());
       
        set("long",@LONG
  錟都城的太守，是錟都城中最大的長官，好文厭武，是個書呆子，
  不過父親卻是個武林中人，而且還是個極負盛名的武林高手，不單如此
  他的母親也是個江湖上響噹噹的人物。面對這樣的家庭，揚躍文可說是
  受盡壓力，因為啊，家裡的人個個都希望有朝一日，揚盜文能雄霸武林
  啊。所以揚躍文再受盡壓力下，在18歲那年離家，音信全無。過了十年
  後，揚躍文當上了錟都城的太守，才開始有了消息。他的雙親也放棄了
  ，逼他習武的念頭，一家人就隨著他遷居到錟都。
          揚躍文一臉滿足的喜悅，看來很滿足的樣子..
LONG
                  );
          return 1;
}

void reset()
  {
          delete_temp("letter");
          set("long",@LONG
  錟都城的太守，是錟都城中最大的長官，好文厭武，是個書呆子，
  不過父親卻是個武林中人，而且還是個極負盛名的武林高手，不單如此
  他的母親也是個江湖上響噹噹的人物。面對這樣的家庭，揚躍文可說是
  受盡壓力，因為啊，家裡的人個個都希望有朝一日，揚盜文能雄霸武林
  啊。所以揚躍文再受盡壓力下，在18歲那年離家，音信全無。過了十年
  後，揚躍文當上了錟都城的太守，才開始有了消息。他的雙親也放棄了
  ，逼他習武的念頭，一家人就隨著他遷居到錟都。 
LONG 
);
          return;
}



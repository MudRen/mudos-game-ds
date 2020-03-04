#include <ansi.h>
inherit NPC;

void create()
{
       set_name("柴子雲",({"tsai tsi yuin","tsai","yuin"}));
       set("long",@LONG
    柴子雲，柴子玲兄妹皆為八極門李書文的得意弟子。其中柴子雲
個性耿直，身材魁梧，專研八極拳十數年終於成就不凡的武藝。武林
中人號稱其：「神拳似龍游四海，震腿如雷貫九天。」這次離師遠行
是為了其妹身上的宿疾，但是似乎遭遇了什麼困難，讓這位叱吒武林
的俠客在這裡哀聲嘆氣，騷頭抓耳不知所措。
LONG);
       set("gender","男性");
       set("age", 30);
       set("level", 30);
       create_family("八極門 ",7,"弟子");


       set("str", 70);
       set("con", 70);
       set("guild_gifts",({10,7,0,3}));

       set_skill("unarmed", 90);
       set_skill("parry", 70);
       set_skill("dodge", 50);
       set_skill("bagi_fist",97);
       set_skill("horse-steps",97);


       set("chat_chance", 20);
       set("chat_msg", ({
            (:command("sigh"):),
        (:command("exert bagi_force power up "):),
        (:command("exert bagi_force armor "):),
            (:command("exert bagi_fist"):),
            (:command("exert horse-steps down-power "):),
            (:command("exert horse-steps ten-power "):), 
            (:command("exert horse-steps twine-power "):),
        (:command("exert bagi_force heal "):),
            "柴子雲在這裡走過來∼∼又走過去∼∼就這樣一直走來走去。\n",
            (:command("say 已經到了這步田地，怎麼會突然這樣？這該如何是好∼ "):),                  
             }));


        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
        }) );

    
        setup(); 

      carry_object(__DIR__"wp/fire-bird_craw")->wield();
}
int special_attack()
{
        int hp ,max_hp ,ppl_hp,ppl_maxhp;
        hp=this_object()->query("hp");
        max_hp=this_object()->query("max_hp");
        ppl_hp=this_player()->query("hp");
        ppl_maxhp=this_player()->query("max_hp");
/*
      if(environment(this_player())!=environment(this_object())) 
      {
      say ("柴子雲坐了下來吐納了幾口，看起來他的體力恢復了不少");
      this_object()->receive_heal("hp",700);
      this_object()->receive_heal("ap",700);
      this_object()->receive_heal("mp",700);
       return 0;
      }
*/
        if(hp<max_hp/2 )
      {
      if(this_object()->query("mp")<70) return 0;
      if(random(7)) return 0;
      this_object() -> receive_damage("mp", 70);      
      say (HIY"柴子雲閉上雙眼大喝一聲！頓時他身上真氣流動，待他張開眼後似乎比剛剛更有精神了。\n"NOR); 
      this_object()->receive_heal("hp",500);
      this_object()->receive_heal("ap",300);
       return 1 ;
      }
        
        if(ppl_hp<ppl_maxhp/7)
      {
         command("exert bagi_fist");
         return 1;  
      }
}


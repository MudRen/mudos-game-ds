#include <ansi2.h> 
inherit NPC;
void steal_eq();
void create() 
{
        set_name(YEL"狸貓"NOR,({"palm civet", "civet", "palm"}));   
        set("long","一隻頭頂著一片樹葉的狸貓，那片葉子是他所有法力的來源•據\n"
                   "傳聞說，狸貓善用幻術跟敵人作戰，一但敵人中了幻術，狸貓變\n"
                   "會趁機逃之夭夭•\n");         
        set("level",23+random(5));
        set("attitude", "peaceful");
        set("race", "野獸");
        set("max_hp",3500+random(4000));
        set("str",40+random(2));  
        set("dex",40+random(2));   
        set("addition_damage",70+random(20));  
        set("addition_shield",200);  
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
        carry_object(__DIR__"eq/leaf")->wear();
}

void init()
{
  object me,ob=this_object();

  ::init();
  if( interactive(me = this_player()) && !is_fighting() && !ob->visible(me))
  { 
    if ( random(4) > 2){
    message_vision("膽小的$N看到$n靠了過來，一溜煙就逃得不見蹤影了•\n",ob,me);    
    destruct(ob);
    }
  }
} 
void die()
{
        object me=this_object(),
               obj=present("leaf",me),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(50) ){
         case 0..48:
          message_vision("$N頭頂的樹葉突然間著火燒掉了…\n",me);
          destruct(obj);
         break;
         }

        if(!random(8)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"你得到 1 點聲望。"NOR);  
        }     
        ::die();
        return;
}        


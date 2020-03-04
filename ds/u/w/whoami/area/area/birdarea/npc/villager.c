#include <ansi2.h>
inherit NPC; 
int aa;
void create()
{
        set_name("村民",({ "villager" }) );
        set("long","一個居住在獵狐村的村民，似乎常常出去獵補狐狸，賣其皮以糊口•\n");
        set("race","人類");
        set("title",HIR"獵狐村"NOR);
        set("age",20+random(15));
        set("level",30+random(10));
        set("str",40+random(10)); 
        set("dex",random(30)+20);
        set("int",40); 
        set("addition_armor",100);
        set("addition_shield",100);        set("max_hp",6000+random(1500));
        set("attitude","friendly");
        set_skill("dodge",50+random(40));
        set_skill("unarmed",20+random(70));
        set_skill("parry",random(50)+30);
   setup();  
     for (aa=0;aa<3;aa++)
     { 
       switch( random(14) )
       {
        case 1: carry_object(__DIR__"eq/f_hat")->wear(); break;
        case 2: carry_object(__DIR__"eq/f_neck")->wear(); break;
        case 3: carry_object(__DIR__"eq/f_cloth")->wear(); break;
        case 4: carry_object(__DIR__"eq/f_armor")->wear(); break; 
        case 5: carry_object(__DIR__"eq/f_cloak")->wear(); break;
        case 6: carry_object(__DIR__"eq/f_wrists")->wear(); break;
        case 7: carry_object(__DIR__"eq/f_gloves")->wear(); break;
        case 8: carry_object(__DIR__"eq/f_ring")->wear(); break;
        case 9: carry_object(__DIR__"eq/f_waist")->wear(); break;
        case 10: carry_object(__DIR__"eq/f_pants")->wear(); break; 
        case 11: carry_object(__DIR__"eq/f_leg")->wear(); break;
        case 12: carry_object(__DIR__"eq/f_boots")->wear(); break;
       }
     } 
   add_money("coin",800+random(500));           
}

void init()
{     
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 
   if ( !me->query("quest/ko_fox") ){
   command("sula " + me->query("id"));
   command("say 沒進去過狐穴的人怎麼配來我們獵狐村呢？");
   } else if ( me->query("quest/ko_fox") >= 1000 ){
   command("wa");
   command("say 這位" + RANK_D->query_respect(ob) + "真是不簡單，殺了這麼多的狐狸！" );    
   return;
   } else if ( me->query("quest/ko_fox") >= 10000 ){
   command("kneel " + me->query("id"));
   command("say 你真是厲害，能解決掉這麼多的狐狸還安然無恙！" );    
   return;
   } if ( me->query_temp("ko_fox_nine") ){
   command("walileh "+me->query("id"));
   command("say 你..居然能封印九尾.." );     
   command("fear "+me->query("id"));    
   return;
   } 
}



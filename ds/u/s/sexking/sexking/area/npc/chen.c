#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
set_name( "小成深介", ({ "shu chen","shu","chen"}));
        set("long", @TEXT
他是一位看起來眉清目秀的中年人，本是一位浪人劍客，年輕時在一
次戰役中被敵方二十名高手偷襲砍成了重傷，一氣之下瘋狂的殺光他
們全部的人，但因為負傷過重失血過多而功力大退如今已退隱江湖從
事販賣。
TEXT    );
        set("level",50);
        set("title","商人");
        set("gender", "男性");
        set("race", "人類");
        set("age", 43);
        set("str",70);                  
        set("dex",50);                
        set("con",90);                  
        set("int",90);               
        set("combat_exp",8000);         
        set("evil",-20);                 
        set_skill("blade",90);         
        set_skill("parry",90);          
        set_skill("dodge",70);  
        set_skill("perception",25);  
        set("sell_list",([
                __DIR__"obj/sous" : 9,
                __DIR__"obj/wine" : 10,
                __DIR__"obj/noodles" :15,
                __DIR__"obj/boil" :15,
        ]) );     
        set("attitude", "peaceful");  
        set("talk_reply","那就多買些日本的東西回去品嘗吧.....");
        set("storeroom",__DIR__"japen_shop"); 

  set("chat_chance", 3 ); 
  set("chat_msg", ({      
"小成深介嘆口氣說:人還是過得平靜點好.. ..\n",
(:command("smile"):),
(:command("tender"):),
}) );
set("inquiry/name", @LONG
   我叫做小成深介.. 請多指教!!
LONG );

        setup();

      
      carry_object(__DIR__"wp/japen_blade")->wield();
      }

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}


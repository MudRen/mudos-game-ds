#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟守衛",({"guard",}));
 set("long",@LONG
你看了一看這一個昔日大教的守衛，只見他的太陽穴微微突
起，顯然所修練的內功並不深厚，但一雙手掌卻粗糙無比，
想來外家功夫不容小覷•
LONG
     );
 set("attitude","peaceful"); 
 set("age",28);
 set("gender","男性");
 set("level",33);  
 set("max_hp",8000+random(3000)); 
 set("max_ap",8000); 
 set("str",80); 
 set("dex",80);  
 set("Merits/bar",8); 
  set_skill("sky-dagger",75);
 set_skill("dagger",70);
 set("chat_chance",3);
 set("chat_msg", ({"天梟守衛兩眼直盯著你看.... .\n",
 }));
 set("chat_chance_combat",20);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say 難道天梟人人可欺!!  ":),
 }));
 setup();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/dagger")->wield();
 carry_object(__DIR__"eq/owl_armor")->wear();
 carry_object(__DIR__"eq/grass_boots")->wear();
}


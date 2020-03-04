#include <ansi.h>
inherit NPC; 
void combat_ai();  

void create()
{
 set_name("弓箭手",({"archer"}));
 set("long",@LONG  
在你眼前的就是隨處打劫十萬山山道中旅人錢財的土匪, 傳
聞道十萬山中的土匪各各兇悍無比, 但卻都是女人. 看來這
個傳聞絕非空穴來風. 
LONG);
 set("title",YEL"十萬山山寨"NOR);
 set("age",23+random(15));
 set("gender","女性");
 set("level",30);  
 set("max_hp",6600+random(3000)); 
 set("max_ap",8000); 
 set("str",75+random(18)); 
 set("dex",75+random(15));  
 set("Merits/bar",5+random(3));
 set("Merits/bio",3+random(3));  
 set("Merits/wit",5+random(3)); 
 set_temp("apply/damage",95+random(30)); 
 set_temp("apply/hit",30+random(30));
 set_skill("gun",80+random(15));
 set_skill("dodge",70+random(15)); 
 set_skill("parry",70+random(15)); 
 set_skill("block",70+random(15));
 set("chat_chance_combat",60);
 set("chat_msg_combat", ({
 (: combat_ai :),
 }));
 
 setup();  
   carry_object(__DIR__"eq/thunder_crossbow")->wield();
 carry_object(__DIR__"eq/bolt"); carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
}

void init()
{
  object me=this_player(),ob=this_object();
 
  ::init(); 
  if ( !me->query("class1") ) return; 
  if ( me->query_temp("invis") ) return;
  command("shoot "+me->query("id"));

} 
 
void combat_ai()
{
        int i;
        object *target,wp;

        target = all_inventory(environment(this_object()));
        wp = this_object()->query_temp("weapon");

        /* 武器被打掉，則裝回去 */
        if( !this_object()->query_temp("weapon") ) 
                command("wield crossbow");

        if( wp->query_temp("loaded") < wp->query("max_load")/5 )
                command("reload bolt");

        /* 敵人->attack */ 
 
           command("shoot");
           this_object()->start_busy(-2);
        return;
}


#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name(HIW"魚老大"NOR,({"fish boss","boss","fish"}));
       set("race","野獸");
       set("level",25);
       set("max_hp",2222); 
       set("age",50);      
       set("attitude","friendly");
       set("devil",20); 
       set("limbs", ({ "頭部", "身體", "腹部", "尾巴"}) );
       set("verbs", ({ "claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "哈哈，我乃魚群之老大，我很愛玩，誰要跟我玩啊？\n" }) );
       set("long",@LONG      
魚群裡的老大，看起來就很弱，怎麼會是老大(=.=?)。

LONG
); 
        setup();
} 
void die()
{
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
       HIY"\n\t新手頻道：魚老大跟"+ob->name(1)+"玩打架，結果不幸的玩死了！\n"+NOR,users());
        ob->add("popularity",1); //聲望
     message_vision( "$N說：我...我....我不玩了..." ,this_object() );
        ::die();
        return;
}

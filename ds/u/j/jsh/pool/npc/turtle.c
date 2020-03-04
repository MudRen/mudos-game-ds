#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name(CYN"玄武"HIW"神龜"NOR,({"shang-woo god turtle","turtle"}));
       set("gender","野獸");
       set("level",40+random(15));
       set("max_hp",35000); 
       set("age",432+random(32));      
       set("attitude","unfriendly");
       set("devil",20); 
       set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴","龜殼" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "玄武神龜搖了搖尾巴，並注視著某樣東西。\n" }) );
       set("long",@LONG      
迷樣的東西，龍頭龜身，不知從何形容，原本冬眠的它
似忽吞下了喜愛的食物，爬出了水池。
LONG
); 
        setup();
} 
void die()
{
   object ob,obj;
   obj=new(__DIR__"obj/turtle-armor");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIY"\n\t:+:水寒星洞:+:\n"
   CYN"\t\t\t○玄武● "+HIW"神龜 "+HIR "被"+ob->name(1)+"給擊斃了！\n\n"+NOR
        ,users());
        ob->add("popularity",4); //聲望
     message_vision( "$N一頭撞在地上，頭上的玄石也隨之掉落" ,this_object() );
     obj->move(environment(this_object() ) );
    obj=new(__DIR__"obj/turtle-liver");
       obj->move(environment(this_object() ) );
        ::die();
        return;
}


#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"螞蟻王"NOR, ({ "ant king","king" }) );
        set("long",@LONG
本來是一隻小螞蟻, 幾千年前可能是受到某些因素. 身體不知不覺的變大
, 還會說話, 自稱螞蟻王,  但是被古代之勇士所擒, 關在一巨形拱門內, 
不知道有多少年沒出來, 各性也變的兇殘無比。
LONG
);  
        set("gender", "男性");  
        set("race", "beast");
        set("attitude","aggressive");
        set("level",50);
        set("age",6045); 
        set("limbs", ({ "頭部", "腹部","胸部","尾部","腳部" }) );  
        add("addition_armor",600);
        add("addition_damage",600);      
        set("evil",-20);
        set("title",HIG"蟻中之王"NOR); 
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("combat",100);
        set("combat_exp",898745);
        set("max_exp",50000);
        set("max_hp",50000);
     setup(); 
        carry_object(__DIR__"redarmor")->wear(); 
        carry_object(__DIR__"redtooth");
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(4)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIY"$N往$n的方向吐出一口液體....\n"
                    +"咻 ~ ~ 的飛向$n........！！\n"
                    +"$n本想閃躲，但反應太慢, 噴到身上.....\n\n"
                    +HIR"造成$n一處腐蝕\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",300+random(200), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIY"$N往$n的方向吐出一口液體$N....\n"
                    +"咻 ~ ~ 的飛向$n........！！\n"
                    +"$n左三步右三步的跑來跑去，閃過了大沱的, 但..還是被小沱的噴到......\n\n"
                    +HIR"造成一處腐蝕\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(100), this_object());
      return 1;
    }
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
    HIC"\n【快     報】"+HIR "兇殘的「 螞 蟻 王 」被"+ob->name(1)+"這位勇士除掉了。\n\n"+NOR     
       ,users());
        ob->add("popularity",5); 
     message_vision( "$N"+HIC  "死前嘴巴張的大大的，"+HIW"你似乎可以看到一根亮晶晶的東西 . . "NOR ,this_object() ); 
        ::die();
        return;
}


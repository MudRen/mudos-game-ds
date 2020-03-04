#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"天齊二郎丸"NOR,({ "sky-two man","sky","man" }));
        set("long",
                "他是一位個性孤辟冷傲的人,常見他總是閉口不言......\n"
                "從小就有獨特的性格與超人的資質..在28歲時勇闖天狼山\n"
                "將天狼殺死..領悟了新的武技:天狼斬神流左右手與左左小次郎\n"
                "並列成浪人中第二把交椅。\n"
        );
        set("nickname",HIY"暗影迅切流"NOR);
        set("age",46);
        set("level",50);
        set("gender", "男性");
        set("str",120);                  
        set("dex",90);                  
        set("con",100);                
        set("int",70);                  
        set("exp",29600);        
        set("combat_exp",6000);         
        set("evil",-10);  
        set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",100);  
        set_skill("perception",50);
        set_skill("darkfast-blade",100);
        set_skill("combat",100);     
        set("chat_chance",10);
        set("chat_msg", ({
 "天齊二郎丸冷冷看著手上的刀..好像有什麼煩腦",
   (: command("sigh") :),
(: command("exert darkfast-blade") :),
}) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
        (: command("exert darkfast-blade") :),
        (: command("wield blade") :),
}) );

    setup();
        carry_object(__DIR__"wp/wolf_blade")->wield();
        carry_object(__DIR__"eq/wolf_surcoat")->wear();
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
        {        
message("world:world1:vision", HIW"\n 江湖大消息： [ 傳聞扶桑浪人"HIY"天狼斬神流"HIG"天齊二郎丸"NOR HIW"敗給了"HIR + ob->name(1) + " "NOR HIW"。 ] \n\n"NOR, users());
        ob->add("popularity", 3); //聲望
 tell_object(ob,HIW"(因為你殺死了天齊二狼丸，所以你得到了 3 點聲望。)\n"NOR);
}
        ::die();
        return;
}


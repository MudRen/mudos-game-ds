#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"左左小次郎"NOR,({ "left-small man","left","man" }));
        set("long",
                "他是一個十分強的浪人,但在五年前敗在藤田彥空的手上,\n"
                "所以便投靠了藤田彥空受到藤田彥空重用成為藤田彥空的\n"
                " 左右手與天齊二郎丸並列成浪人中第二把交椅。\n"
        );
        set("nickname",HIR"宗本二刀流"NOR);
        set("age",49);
        set("level",50);
        set("gender", "男性");
        set("str",100);                  
        set("dex",80);                  
        set("con",130);                
        set("int",70);                  
        set("combat_exp",6000);         
        set("evil",-10);  
        set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",100);  
        set_skill("perception",50);
        set_skill("combat",100);    
        set_skill("left-blade",100);   
        set_skill("sky-air",100); 
        set("chat_chance",20);
        set("chat_msg", ({
 name()+"愣愣的看著手上的刀發呆。\n",
 name()+"閉目沉思。\n",
 (: command("exert left-blade") :),
}) );
        set("chat_chance_combat",70);
        set("chat_msg_combat", ({
        (: command("exert left-blade") :),
        (: command("wield blade") :),
}) );

    setup();
        carry_object(__DIR__"wp/left_blade")->wield();
        carry_object(__DIR__"eq/left_surcoat")->wear();
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
message("world:world1:vision", HIW"\n 江湖大消息： [ 傳聞扶桑浪人"HIC"宗本式二刀流 "HIY"左左小次郎"NOR HIW"敗給了"HIR + ob->name(1) + " "NOR HIW"。 ] \n\n"NOR, users());
        ob->add("popularity", 3); //聲望
 tell_object(ob,HIW"(因為你殺死了左左小次郎，所以你得到了 3 點聲望。)\n"NOR);
}
        ::die();
        return;
}


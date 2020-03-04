#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIC"ＥＱ發放專員"NOR, ({"eq man","man"}) );
        set("long", "專門為低等級的玩家所設計的工作人員，可以向它索取ＥＱ(want)。\n");
        set("unit","位");
        set("race", "human");
        set("age", 2);
        set("level",1); 
        set("no_kill",1);
        set("dex",1);
        set("str",1);
        set("con",1);
        set("chat_chance",3);
        set("chat_msg",({
                ("ＥＱ發放專員說：發放低等級ＥＱ∼\n"),
        }));

        setup();

}
void init()
{
     add_action("do_want","want");
}
int do_want(string arg)
{
    object ob,me;
    ob=this_object();
    me=this_player();  
    if(me->query_temp("wanted")==1)   
    {
    command("say "+(string)me->query("name")+"你已經要過了喔！\n");    
    return 1;
    }
    if(me->query("level")> 5)    
    {
    command("say "+(string)me->query("name")+"，你的等級已超過 Lv.5，超過了限制，恕不發送。\n");  
    return 1; 
    }
    else{

    command("say "+(string)me->query("name")+"好好加油喔！");  
    command("addoil");
    command("say "+(string)me->query("name")+"，我給你些裝備吧！");   
    switch(random(5))
    {
    case 0:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me);
    new(__DIR__"obj/ds-surcoat.c")->move(me);
    new(__DIR__"obj/ds-wrists.c")->move(me);
    new(__DIR__"obj/ds-pants.c")->move(me);  
    me->set_temp("wanted",1);
    break;
    case 1:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me);
    new(__DIR__"obj/ds-surcoat.c")->move(me);
    new(__DIR__"obj/ds-wrists.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    case 2:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me);
    new(__DIR__"obj/ds-surcoat.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    case 3:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    case 4:
    new(__DIR__"obj/ds-armor.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    }
    }
    return 1; 
}


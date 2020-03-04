inherit NPC;

void create()
{
        set_name("鹽民",({"Salt maker","maker"}) );
        set("long",@LONG
從事製鹽工作的漁民，製鹽是漁民很重要的收入來源，在一年陽
光最充足，雨量最少的時節中，漁民都會投入人力從事製鹽。
LONG);
        set("race","人類");
        set("gender", "男性");  
        set("age",35);
        set("level",19);
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
        "鹽民流著斗大的汗水，辛勤地扒著鹽粒。\n",
        "鹽民停下來稍作休息，用汗巾擦著汗。\n",
        }));
        setup();
        add_money("coin",350);
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
 
        switch( random(99) ) {
        case  0..19: new(__DIR__"eq/leather-gloves")->move(this_object());
        break;}
        ::die();
        return;
 }

// 四金剛羅漢之一

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("不動金剛" ,({"bu dong jingang","bu","dong","jingang"}) );
        set("long",@LONG
不動金剛
LONG
);
        set("age",200);
        set("race","人類");
        set("title","護法尊者");
        set("level",40);
        set("attitude", "aggressive");
        set("gender", "男性" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("staff",100);
          set_skill("jingang-finger",100);
        map_skill("unarmed","jingang-finger");
              set("str",60);
              set("con",60);
        setup();
        set_living_name("buddha-war-jingang");
                  set("combat_exp",500000);
                carry_object(__DIR__"eq/armor")->wear();
                carry_object(__DIR__"eq/cloth")->wear();
                carry_object(__DIR__"eq/helmet")->wear();
                carry_object(__DIR__"eq/boots")->wear();
                carry_object(__DIR__"eq/hands")->wear();
    if(random(10)>8 )
        carry_object(__DIR__"wp/fist3")->wield();
    else if(random(10)>8 )
        carry_object(__DIR__"wp/fist2")->wield();
    else
        carry_object(__DIR__"wp/fist")->wield();


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
        tell_object(ob,HIG"\t你得到一點聲望。\n"NOR);
        ob->add("popularity",1); //聲望

        ::die();
        return;
}

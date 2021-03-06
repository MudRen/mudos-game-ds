#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG "龍虎" NOR,({"dragon tiger","tiger", "dragon"}) );
      set("title",HIM "神真異獸" NOR);
        set("long",@LONG
龍虎是著名的神真異獸，其來源於秦漢四靈中的龍虎崇拜。
道書常把它們描述為傳驛用的腳力。如《太上登真三矯靈應
經》說：「夫龍矯者，氣也。氣者，道也。長視龍矯，煉身
為氣，與道合真，足生雲也。龍矯者，奉道之士欲遊洞天福
地，一切邪魔精怪惡物不敢近，每去山川江河州府，到處自
有神衹來朝現”。“夫龍矯者，風之母，水之子。用之三載
，其虎自乘風，來來往往如風動敗葉飛空。聚則為形，散則
為風，與天地正陽之混合為一一了也。」
LONG    
        );
        set("race", "beast");    
        set("unit","隻");
        set("age", 600);
        set("level", 45);
        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","龍尾","背鱗" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_hp", 5000);
        add("addition_armor", 90);
        add("addition_damage", 80);
        setup();
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
        set_temp("apply/damage",50);
          if(random(10)<8) carry_object(__DIR__"eq/dragon-tiger-armor")->wear();
        else carry_object(__DIR__"eq/dragon-tiger-armor2")->wear();
        carry_object(__DIR__"obj/dragon-tiger-pill");
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
                HIG"\n【道派消息】" + HIM "寒澈道觀神真異獸「龍虎」被"+ob->name(1)+HIM "降伏了。\n"+NOR, users());
        ob->add("popularity", 2); //聲望
        ::die();
        return;
}


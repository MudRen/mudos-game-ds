#include <ansi.h>
inherit NPC;
void create()
{
       set_name("潘英",({"pan-en","pan","en"}));
       set("long",
           "    你看到一位身長體瘦的漢子，細細的眉宇下是一雙無神的眼睛，好像失去了\n"
           "所有的希望，但是他的身子卻又好像守護著什麼東西一樣，堅毅不可動搖。他手\n"
           "上臉上佈滿了傷痕，本來可能還算清秀的臉現在變的微微有些凶狠之氣。不過他\n"
           "好像沒看到你一樣，動也不動的望著你身後的遠方。\n"
        );
       set("nickname",HIB"星河破空"NOR);
       set("gender","男性");
       set("age", 37);
       set("level", 37);
      set("adv_class",2);    
      set("class1","摘星門"); 
     set("class2","奇門");
      create_family( MAG "摘星門" NOR ,21,"武學教頭");

   set("guild_skills",([  
             "dagger":({130,2,100}),   
             "unarmed":({190,2,70}),
             "parry":({150,2,90}),  
        ]) );

   set("guild_gifts",({-2,-2,7,17}));

        set("chat_chance",3);
        set("chat_msg",({
                                   (:command, "close door"
:)}));

       set("attitude", "peaceful");
       set("talk_reply","回去。"); 

        setup();
        add_money("coin", 100);
        carry_object( __DIR__"eq/sky-walk_b")->wear();
        carry_object(  __DIR__"wp/stonedragon_d")->wield();
        carry_object( __DIR__"eq/stars_c")->wear();           
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}
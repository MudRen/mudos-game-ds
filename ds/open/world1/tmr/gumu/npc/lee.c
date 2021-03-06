#include <ansi.h>
inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
        set_name("李莫愁", ({ "lee mochou", "lee", "mochou" }));
        set("long", "她生得極為美貌，但冰冷的目光讓人不寒而慄。\n");
        set("nickname", HIR"赤練仙子"NOR);
        set("gender", "女性");
        set("attitude","heroism");

        set("level", 45);
        set("inquiry", ([
                "name" : "站遠點！",
                "here" : "我不是本地人，不知道。",
                "情" : "你如何能理解其中相思之苦、惆悵之意？",
                "陸展元" : "你問那個薄情的小畜生做什麼？",
                "何沅君" : (: ask_me :),
                "小龍女" : "那是我的師妹。你問她想幹什麼？",
                "林朝英" : "那是我的師祖，不該你問的你別問，小心我宰了你。",
        ]) );
        
        set_skill("whip",100);
        set_skill("block",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("dodge",100);

    create_family("古墓派", 3, "弟子");
 
        set("chat_chance", 10);
        set("chat_msg", ({
                "李莫愁縱聲而歌，音調凄婉，歌道：「問世間，情是何物，直教生死相許\？」\n",
                "李莫愁歌道：「天南地北雙飛客，老翅幾回寒暑？」\n",
                "李莫愁唱道：「歡樂趣，離別苦，就中更有痴兒女。」\n",
                "李莫愁唱道：「君應有語，渺萬里層雲，千山暮雪，只影向誰去？」\n",
                "李莫愁詞意悲切，聲調更是哀怨，唱道：「橫汾路，寂寞當年簫鼓。荒煙依舊平楚。」\n",
                "李莫愁歌道：「招魂些何嗟及，山鬼自啼風雨。」\n",
                "李莫愁唱道：「天也妒，未信與，鶯兒燕子俱黃土。」\n",
                "李莫愁唱道：「千秋萬古，為留待騷人，狂歌痛飲，來訪雁丘處。」\n",
        }) );

      set("combat_exp", 800000);

        setup();
        set_temp("apply/armor", 300);
        set_temp("apply/damage", 200);
        carry_object(__DIR__"obj/fuchen")->wield();
        carry_object(__DIR__"obj/white-robe")->wear();
        carry_object(__DIR__"obj/jade-bracelet")->wear();
        carry_object(__DIR__"obj/silver-ankle")->wear();
        carry_object(__DIR__"obj/ice-silver_needle");
}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","kiss");
}

int ask_me()
{
        object me;
 
        me = this_player();
        message("vision", HIY"李莫愁冷笑一聲：『我這就送你去見她！！』\n李莫愁決心殺死" + me->name() +"\n" NOR, environment(), this_object() );
        kill_ob(this_player());
        return 1;
}

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="lee" || target=="lee mochou" || target=="mochou" ) 
                if ((string)me->query("gender") != "女性")
                {
                        message("vision", HIY "李莫愁大怒，喝道：我最恨你們這些薄情的臭男人！去死吧！\n李莫愁決心殺死" + me->name() +"\n" NOR, environment(), this_object() );
                        kill_ob(this_player());
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
              HIR"\n【活死人墓】"HIY "惡名遠播的「赤練仙子」李莫愁被"+ob->name(1)+HIY"殺死了！！\n\n"+NOR
            ,users());
      ob->add("popularity", 4);   //聲望
    ::die();
    return;
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon;
    if(!me || !target)
        return 0;
    if(random(10)<7) return 0;

    message_vision(HIC"\n$N"HIC"嬌喝一聲，擲出一道慘白色的光芒沒入$n"HIC"手臂裡，竟然是冰魄銀針！！\n" NOR,this_object(), target);
    target->receive_damage("hp", query_damage()/2 + random(query_damage()), this_object());
    target->apply_condition("poison", 10);
    target->add_busy(1);
    return 1;
}


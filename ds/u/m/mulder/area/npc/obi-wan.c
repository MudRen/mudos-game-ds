#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"Obi-Wan"NOR , ({ "obi-wan","wan","obi" }) );
        create_family( HIW "『Jedi Knight』" NOR ,2,"武士");
        set("level",25);
        set("race","人類");
        set("age",25);
         set("adv_class",1);
         set("class1",HIW"『Jedi Knight』"NOR);
        set("gender","男性");
        set("int",100);
	// 設定屬性分配表, 每一項的值在負9至正10之間
	// 而且四項的總和要剛好等於 20			by shengsan
	set("guild_gifts",({2,3,10,5}));
        set("guild_skills",([
               "dodge" : ({160,2,50}),
               "parry" : ({160,2,50}),
             "sword" : ({160,2,50}),
           "godsword" : ({140,2,50}),
           "meditate" : ({160,2,50}),
           "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-benison" :({180,2,50}),
          ]) );
        set_skill("force", 50);
        set_spell("god-benison",50);
        set_skill("sword", 50);
        set_skill("parry", 50);
           set_skill("dodge",50);
          set_skill("godsword",50);
        set("long",@long
他是『Jedi Knight』的武士，提供基本的技巧訓練。你可
以使用 list來看看有什麼技巧可以提供學習(train)。也可以用
advance <level或屬性> 來升級, 升級前建議先使用 level指令
來查閱所需要的經驗值。
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                   (:command("exert mirage-steps"):),
		(:command("cast god-benison"):),
        }) );
        setup();
	carry_object(__DIR__"wp/lightsaber.c")->wield();

}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);	
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
	GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
      this_player()->delete("no_check_class");
       return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")==HIW"『Jedi Knight』"NOR) return notify_fail("你已是『Jedi Knight』的武士了。\n");
	 if(arg!="『Jedi Knight』") return notify_fail("你要拜入那一個門派?\n");
            message_vision("奧比溫說道： 嗯！我現在只能教你一點"HIW"『Jedi Knight』"NOR"的基本技能。\n",me);
            message_vision("奧比溫說道：  怎麼才能找到真正的"HIW"『Jedi Knight』"NOR"力量，就要靠你自己了！\n\n",me);
	call_out("domessage",3,me,2);
	return 1;   
}


int domessage(object me,int b)
{
	me=this_player();
  if(b==2)
        message_vision(HIW"奧比溫將雙手舉起, $N的身旁漸漸泛起一陣白霧........\n\n"NOR,me);	
        else
  if(b==1) 
        message_vision(HIW "只見白霧中的若有若無的幻影漸漸漫入$N的身體, $N感到全身充滿了一種神秘力量。\n\n" NOR,me);
        else 
  if(b==0)
                  {
        me->set("adv_class",1);
        me->set("class1",HIW"『Jedi Knight』"NOR);
        me->create_family(HIW"『Jedi Knight』"NOR,3,"武士");
        message_vision("$N正式成為"HIW"『Jedi Knight』"NOR"的第三代武士！\n",me);
	return 1;
	}
b--;
call_out("domessage",3,me,b);
} 

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
	if(me->query("class1")=="『Jedi Knight』" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是"HIW"『Jedi Knight』"NOR"的弟子。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}

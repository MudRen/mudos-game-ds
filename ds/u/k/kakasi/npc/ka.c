#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"旗木卡卡西"NOR,({"kakasi","chi mu"}) );
        set("long",@LONG
木葉村上忍中的其中之一，帶有寫輪眼•但是一位滿好相處的一個人。
LONG
);
        set("age",26);
        set("race","人類");
        set("title",HIG"木葉"BLK"上忍"NOR);
          set("level",43);
          set("attitude", "peaceful");
          set("gender", "男性" );
        set("chat_chance",30);
        set("chat_msg",({
                command("hmm"),
        }) );
        setup();
    carry_object("/u/k/kakasi/eq/cloth")->wear();
    carry_object("/u/k/kakasi/eq/boots")->wear();
    carry_object("/u/k/kakasi/eq/mask")->wear();
  carry_object("/u/k/kakasi/eq/pants")->wear();
    carry_object("/u/k/kakasi/wp/dagger")->wield();
}
void init()
{
        ::init();
        call_out("do_give",0,this_player(),this_object() );
}

int do_give(object me,object ob)
{
        object obj;
        if(me->query_temp("beg-tree") && !me->is_fighting() )
        {
                command("say 好小子！！你畢業了！");
    command("smile");
                message_vision("卡卡西從他的包包裡拿出一個畢業證明給$N。\n",me);
                me->delete_temp("beg-tree");
                  obj=new("/u/k/kakasi/eq/mask2");
                obj->move(me);
                message_vision(HIC"卡卡西咻的一聲不見了!?\n"NOR,ob);
                destruct (ob);
        }
    else
                command("cong "+me->query("id") );
     return 1;
}

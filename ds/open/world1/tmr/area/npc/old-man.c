inherit NPC;

void create()
{
        set_name("老人",({"old-man","man"}) );
        set("long",@LONG
一位看來一臉慈祥、與世無爭模樣的老人，看其身形甚是削瘦，卻給
人有種超然物外的感覺。
LONG
);
        set("age",120);
        set("race","人類");
      set("exp",3000);
          set("level",30);
            set("attitude", "peaceful");
            set("gender", "男性" );
        set("chat_chance",30);
        set("chat_msg",({
                command("smile"),
        }) );
        setup();
    carry_object(__DIR__"eq/white_cloth")->wear();
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
                command("say 想來也是你我有緣，我這枚柳戒就送你以保平安吧。");
    command("smile");
                message_vision("老人除下了戴在手上的一枚戒指，送給了$N。\n",me);
                me->delete_temp("beg-tree");
                  obj=new(__DIR__"eq/ring");
                obj->move(me);
                message_vision("老人微笑地點了點頭，走出廟門口。\n",ob);
                destruct (ob);
        }
        else
                command("smile "+me->query("id") );
        
        return 1;
}

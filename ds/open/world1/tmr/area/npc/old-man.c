inherit NPC;

void create()
{
        set_name("�ѤH",({"old-man","man"}) );
        set("long",@LONG
�@��ݨӤ@�y�O���B�P�@�L���Ҽ˪��ѤH�A�ݨ䨭�άƬO�d�G�A�o��
�H���ضW�M���~���Pı�C
LONG
);
        set("age",120);
        set("race","�H��");
      set("exp",3000);
          set("level",30);
            set("attitude", "peaceful");
            set("gender", "�k��" );
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
                command("say �Q�Ӥ]�O�A�ڦ��t�A�ڳo�T�h�ٴN�e�A�H�O���w�a�C");
    command("smile");
                message_vision("�ѤH���U�F���b��W���@�T�٫��A�e���F$N�C\n",me);
                me->delete_temp("beg-tree");
                  obj=new(__DIR__"eq/ring");
                obj->move(me);
                message_vision("�ѤH�L���a�I�F�I�Y�A���X�q���f�C\n",ob);
                destruct (ob);
        }
        else
                command("smile "+me->query("id") );
        
        return 1;
}

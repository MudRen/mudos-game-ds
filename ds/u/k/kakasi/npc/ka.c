#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"�X��d�d��"NOR,({"kakasi","chi mu"}) );
        set("long",@LONG
�츭���W�Ԥ����䤤���@�A�a���g�����E���O�@�캡�n�۳B���@�ӤH�C
LONG
);
        set("age",26);
        set("race","�H��");
        set("title",HIG"�츭"BLK"�W��"NOR);
          set("level",43);
          set("attitude", "peaceful");
          set("gender", "�k��" );
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
                command("say �n�p�l�I�I�A���~�F�I");
    command("smile");
                message_vision("�d�d��q�L���]�]�̮��X�@�Ӳ��~�ҩ���$N�C\n",me);
                me->delete_temp("beg-tree");
                  obj=new("/u/k/kakasi/eq/mask2");
                obj->move(me);
                message_vision(HIC"�d�d�諦���@�n�����F!?\n"NOR,ob);
                destruct (ob);
        }
    else
                command("cong "+me->query("id") );
     return 1;
}

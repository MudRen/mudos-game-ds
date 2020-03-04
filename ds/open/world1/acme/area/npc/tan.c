#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���ѿ�", ({ "tan gen","gen" }) );
        set("level", 15);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set_skill("sword", 40);
        set_skill("parry", 30);
        set_skill("dodge", 40);
        set_skill("godsword",40);
        set_skill("mirage-steps",50);
        set_spell("god-fire",40);
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
        }) );
        set("chat_chance", 8);
        set("chat_msg", ({
                  (:command("exert mirage-steps"):),
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
        }) );
        set("long",
            "�L����C���A�A�嶶�ۤ��u�y�ܪ��C�W�A�����ݡA\n"
            "�@�L�⨭�W���˩�b�ߤW�C\n",
            );
        setup();
        carry_object(__DIR__"wp/longsword")->wield();
}
void init()
{
        int i;
        object ob;
        ::init();
        i= this_object()->query("max_hp");
        this_object()->set("hp",i-50);
        call_out("greeting", 3, ob);
        add_action("do_say","say");
        add_action("do_nod","nod");
if(this_player()->query("name")!="����s") this_object()->kill_ob(this_player());
if(this_player()->query_temp("canadd_senwu")==1) call_out("senwuquest",1);
}
void greeting(object ob)
{
  object me;
  me=this_player();
  if(me->query_temp("killbandit") > 0 && me->is_fighting() )
  {
     message_vision("���ѿ����D�G�o��"+ RANK_D->query_respect(me) +"�A��Ӥ��O���H������A�Ю��b�U�����L�]�C\n",me);
     me->remove_all_killer();
  }
  else {
     message_vision("���ѿ����$N�ܹD�G�c��I�ǩR�ӡI\n",me);
  }
}
int do_say(string arg)
{
          object me,paper;
          me=this_player();
           if(arg == "���H" || arg =="���H������" || arg=="���L�P" && me->query_temp("killbandit") >0 )
          {
            message_vision(YEL"$N���G" + arg +"\n"NOR,me );
            message_vision("���ѿ����$N���D�G���H�N�O�~�������Ѹ�A�]�~�J�L���a�L�A�L���v�H�Ӱl���ڡC\n",me);
            message_vision("���ѿ����$N���D�G�o��"+ RANK_D->query_respect(me) +"�i�_���ڤ@�Ӧ��H\n",me);
            me->set_temp("killbandit",2);
            return 1;
          }
          if(arg == "�i" && me->query_temp("killbandit") >1 )
          {
            message_vision(YEL"$N���G" + arg +"\n"NOR,me );
            message_vision("���ѿ����$N���D�G�Ӧn�F�A�A�u�n���ڧ�o�F��浹�u�b���@��v����s�A�N���F�C\n",me);
            message_vision("���ѿ����$N�`�`�����F�@�Ӱ`�C\n",me);
            message_vision("���ѿ����F$N�@��ƪ��C\n",me);
            paper=new(__DIR__"obj/paper2.c");
            paper->move(me);
            return 1;
          }
}
int do_nod(string arg)
{
    object me,paper;
    me=this_player();
    if( arg == "gen" && me->query_temp("killbandit") > 1 )
    {
      message_vision(HIY"$N��ۤ��ѿ��I�F�I�Y�C\n"NOR,me);
      message_vision("���ѿ����$N���D�G�Ӧn�F�A�A�u�n���ڧ�o�F��浹�u�b���@��v����s�A�N���F�C\n",me);
      message_vision("���ѿ����$N�`�`�����F�@�Ӱ`�C\n",me);
      message_vision("���ѿ����F$N�@��ƪ��C\n",me);
      paper=new(__DIR__"obj/paper2.c");
      paper->move(me);
      return 1;
     }
}
void senwuquest()
{
      this_player()->set_temp("canadd_senwu",2);
message_vision("�A�ݨ�����s�O�@�ۤ��ѿ����X�F�o�ӳ��L�C\n",this_player());
      destruct(this_object());
}

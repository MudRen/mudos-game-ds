#include <ansi.h>
inherit NPC;
void create()
{
          set_name("���D��", ({ "yang-yao-wen","yang","wen" }) );
          set("long",@LONG
  �ೣ�����Ӧu�A�O�ೣ�����̤j�����x�A�n�幽�Z�A�O�Ӯѧb�l�A
  ���L���˫o�O�ӪZ�L���H�A�ӥB�٬O�ӷ��t���W���Z�L����A����p��
  �L�����ˤ]�O�Ӧ���W�T�������H���C����o�˪��a�x�A���D��i���O
  �������O�A�]���ڡA�a�̪��H�ӭӳ��Ʊ榳�¤@��A���s��ද�Q�Z�L
  �ڡC�ҥH���D��A�������O�U�A�b18�����~���a�A���H���L�C�L�F�Q�~
  ��A���D���W�F�ೣ�����Ӧu�A�~�}�l���F�����C�L�����ˤ]���F
  �A�G�L�ߪZ�����Y�A�@�a�H�N�H�ۥL�E�~���ೣ�C
LONG
          );
          set("level",35+random(5));
          set("age",35);

          set("combat_exp", 290000);
          set("chat_chance", 10);
          set("chat_msg", ({
    (:command("say �W�o��"):),
    (:command("sigh"):),
  }));
          set("inquiry/��","�դU�Y�Q���D�A�j�i�ۦ�U�h�A�����z�|���x.\n");
          set("inquiry/well","�դU�Y�Q���D�A�j�i�ۦ�U�h�A�����z�|���x.\n");       
          
          set_skill("whip", 100);
          set_skill("parry", 80);
          set_skill("unarmed", 80);
          set_skill("dodge", 80);

          setup();
          carry_object(__DIR__"obj/whip")->wield();
          carry_object(__DIR__"obj/cloth")->wear();
  }
int special_attack(object me,object target,int hitchance)
  {
      int tdex,tcon; 
     if(!me || !target) return 0;
      if(random(5)) return 0;
      tdex=target->query_dex();
      tcon=target->query_con();
      if(random(hitchance/2) > tdex+tcon)
      {
        message_vision("\n"
                       +HIC"$N��M���S�����A�I����{�X���ͧζH�A�i�L�@�R�g�X�͵��A���շQ�n�]��$n..\n"
                      +"$n�o�{�ۤv����Y�@�ˡA�L�k����!!!\n"NOR
                      ,me,target);
        target->start_busy(5);
        return 1; 
      }
      else
      {
        message_vision("\n"
                      +HIC"$N��M���S�����A�I����{�X���ͧζH�A�i�L�@�R�g�X�͵��A���շQ�n�]��$n..\n"
                      +"���O$n�b�d�v�@�v���ک��k��{......\n\n"NOR
                      ,me,target);      
              return 1;
      }
}
int accept_object(object who, object ob)
{
        object tob, a;
        tob = this_object();
        if( ob->query("id")!="letter" || query_temp("letter") ) return 0;

        command("thank "+who->query("id"));
        command("say ���§A�F�A"+RANK_D->query_respect(who)+"�I\n");
        who->add("exp", 10000);
        set_temp("letter",1);
        tell_object(who,HIR"�A�o�� 10000 �I�g��ȡC\n"NOR);
        call_out(
"delay",600,this_object());
       
        set("long",@LONG
  �ೣ�����Ӧu�A�O�ೣ�����̤j�����x�A�n�幽�Z�A�O�Ӯѧb�l�A
  ���L���˫o�O�ӪZ�L���H�A�ӥB�٬O�ӷ��t���W���Z�L����A����p��
  �L�����ˤ]�O�Ӧ���W�T�������H���C����o�˪��a�x�A���D��i���O
  �������O�A�]���ڡA�a�̪��H�ӭӳ��Ʊ榳�¤@��A���s��ද�Q�Z�L
  �ڡC�ҥH���D��A�������O�U�A�b18�����~���a�A���H���L�C�L�F�Q�~
  ��A���D���W�F�ೣ�����Ӧu�A�~�}�l���F�����C�L�����ˤ]���F
  �A�G�L�ߪZ�����Y�A�@�a�H�N�H�ۥL�E�~���ೣ�C
          ���D��@�y�������߮��A�ݨӫܺ������ˤl..
LONG
                  );
          return 1;
}

void reset()
  {
          delete_temp("letter");
          set("long",@LONG
  �ೣ�����Ӧu�A�O�ೣ�����̤j�����x�A�n�幽�Z�A�O�Ӯѧb�l�A
  ���L���˫o�O�ӪZ�L���H�A�ӥB�٬O�ӷ��t���W���Z�L����A����p��
  �L�����ˤ]�O�Ӧ���W�T�������H���C����o�˪��a�x�A���D��i���O
  �������O�A�]���ڡA�a�̪��H�ӭӳ��Ʊ榳�¤@��A���s��ද�Q�Z�L
  �ڡC�ҥH���D��A�������O�U�A�b18�����~���a�A���H���L�C�L�F�Q�~
  ��A���D���W�F�ೣ�����Ӧu�A�~�}�l���F�����C�L�����ˤ]���F
  �A�G�L�ߪZ�����Y�A�@�a�H�N�H�ۥL�E�~���ೣ�C 
LONG 
);
          return;
}



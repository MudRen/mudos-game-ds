#include <ansi.h>
inherit NPC;
void create()
{
      set_name(HIR"�ܬ�"BLK"���]"NOR,({"kfo evil","evil"}));
      set("class","kfo_evil");
      set("title",HIY"����ù�K��"NOR);
      set("nickname",HIW"�ʦL�Ѱ�"NOR);
      set("race","�H��");
      set("gender","�k��");
      set("age",20);
      set("combat_exp",15000);
      set("score",5000);
      set("int",30);
      set("dex",30);
      set("con",30);
      set("luc",30);
      set("spi",30);
      set("attitude","peaceful");

      
      set("max_kee",2000);
      set("max_sen",1200);
      set("max_gin",1300);
      set("atman", 4000);
      set("max_atman", 4000);
      set("mana", 4000);
      set("max_mana", 4000);
      set("mana_factor", 5);

      set("apprentice_available", 3);
      set("chat_chance",10);
      set("chat_msg",({
      "�O�n��!\n",
      "�u��!",
      (: command,"pk":),
      (: command,"pk":),
      }));
      set("env/wimpy",70);
      set("inquiry",([
      "�ŹD���]" : "�L�O�ڪ�������",
      "����" : "�گ����w�o�A���]�u�O�L�h�F�I",
      ]));
      set("chat_chance_combat",200);
      set("chat_msg_combat", ({
      (: command,"exert recover":),
      }));
      setup();
      carry_object("obj/staff2")->wield();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ���I");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �ڤ����F�I�u�I;
        }
}
void do_recruit(object ob)
{
        else {
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
}

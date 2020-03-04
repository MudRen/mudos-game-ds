#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name("����", ({ "barbarian village head","head","barbarian" }) );
        set("long",@long
�@�@�b�A���e���o�Ӥw�W�F�~�������Z�H�A�O�o�Ӯq�W���Z�H����������
�A�b���Z�H�����|�㦳�������a��A�`�`�O�֦����a���ݪ��Ԥh�~��a��
���a��A���L�@�ۧ���

long
);
        set_race("human");
        set("title","���Z�H");
        set("age", 50);
        set_attr("str",30);
        set_skill("blunt",80);                  // �Ϊk
        set_skill("twohanded blunt",60);        // �����Ϊk
        set_skill("parry",50);
       set("chat_change",10);
        set("chat_msg", ({
                "������몺�a���D�G�u���p���A���M���X�������۲��媺�ɭԡA�]�Ӱ����F��....�v\n",
                (: command("snort") :),
        }));
        setup();
        set_level(20);
        carry_object("/d/obj/woodblunt")->wield();
        carry_object(__DIR__"obj/monster_pants")->wear();
}

void exchange(object player,object ob)
{
	object boots=new(__DIR__"obj/barbarian_boots");
        // ���P�ж�.
        if(environment()!=environment(player) ) return;
        destruct(ob);
        command("say �u�O���§A�A�ڳo���u�l�w�g�ܤ[�S��F�A�N�e���A�a�C");
        message_vision("$n�q�Τ��@�����c�l�̨��X�@���u�l�A�e���F$N�C\n",player,this_object() );
        if(!boots->move(player) )
                boots->move(environment());
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_OBJ_ID_BATTLE_AXE_")
                || is_fighting() )
           {
              return 0;
       }
       command("ack");
       command("say ��....�A���ڧ�^�ڪ��Z���F......");
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}

void relay_say(object ob, string arg)
{
        if( strsrch(arg,"�p��")!=-1 )  {
              command("snort");
              command("say �L���d�p�A�j���O�{�q�t�@�ڪ��H�A�e��b�]���]�Ӱ����ڭ̧����ԩ�C");
              return ;
        }
        if( arg=="�ԩ�"  )  {
              command("hmm");
              command("say ���O�ڭ̧����Ǥ��w�[���Q���A�O�i�r���Ԥh�Ҥ��i�ίʪ��C");
              return ;
        }
}


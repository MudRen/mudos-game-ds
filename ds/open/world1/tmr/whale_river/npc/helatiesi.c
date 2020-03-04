// bear.c

#include <npc.h>
#include <ansi.h>
#include <skill.h>

void do_destruct();

void create()
{
        set_name("�����K��", ({ "helatiesi monster","monster","_NPC_ID_HELATIESI_"}) );
        set_race("beast");
                set("title","���");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age",200);
        set("long",@long
�u�����K���v�O�v�W���W����ǡA�����ƤءA���j������ϱo�A�n��
�O����W�j�H���p�ߤl�A�ڥ��L�k�P���ܿšC�����K���`�ů몺�������`
���ۧA�A�j���Ӧ��O�������ڥ��b���N�n�\�A�@�I����A��b���̪��Ҽ�
�A�q�����K���G���y���Q�����L�̦R�X�Ӫ�©��A���ȱo�A�Y������C
long
                );
        set("chat_chance", 8);
         set_skill("unarmed",150);
         set_skill("parry",150);
         set_skill("dodge",150);
        set_attr("strength",50);
        set("chat_msg", ({
                "�����K���u�R�v���@�n�A�o�X�ө_�Ǫ��s�n�C\n",
                "�����K���u�R�v���@�n�A�o�X�ө_�Ǫ��s�n�C\n",
        }) );
        setup();
          advance_stat( "nina" , 300);
        set_level(30);
        carry_object(__DIR__"obj/helatiesi-ocean")->wear();
           set_temp("apply/damage",50);
        call_out("do_destruct",300);    // 300 ���u��J�򩳡v
}

void do_destruct()
{
        object ob=this_object();
        if(!ob) return;
        if(ob->is_fighting() )
        {
                message_vision(CYN"$N�����@�ϡA��Ҧ����ĤH�����F�}�h�C\n"NOR,ob);
                ob->remove_all_killer();
        }
        message_vision(CYN"$N���Ψ��t�a���j�򲾰ʹL�h�A�H�Y�u�P�q�v�@�n�����b�򤤥��F�C\n"NOR,ob);
        destruct(ob);
}

int accept_object(object player, object ob)
{
        if( player->query_learn("chamber nina-fish")
            || player->query_skill("chamber nina-fish") )
        return 0;
        if( !ob->id("_OBJ_ID_OCREAN_HEART_") )  return 0;
        if( player->query("skills_point")+3 >SKILL_MAX_POINT) return 0;
        tell_object(player,HIW "�����K���`�`�a��F�A�@���A�A���G�q�e���������A�⮩��@�ǯ�O�H�I\n" NOR);
        tell_object(player,HIG"(�A���ޯ�ǲ��I�ƪᱼ�T�I�C)\n" NOR);
        player->improve_skill("chamber nina-fish",100);
          player->add("skills_point",3);
        call_out("do_destruct",1);
        return 1;
}


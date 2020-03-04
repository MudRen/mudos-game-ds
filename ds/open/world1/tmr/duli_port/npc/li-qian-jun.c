#include <npc.h>
#include <ansi.h>
inherit F_FIGHTER;
void create()
{
        set_name("�O�d�v", ({ "li qian-jun","jun","li" }) );
        set("title","�@���_��" );
        set_race("strength");
        set_attr("strength",50);
        set("force_ratio",10);
        set_skill("unarmed",120);
        set_skill("parry",120);
        set_skill("dodge",120);
        set("age", 30);
        set("long",@LONG
    �O�d�v���u���@��H�������A���O����u�W�٦׼ɰ_�A���`����A�Q
���O�ѽᲧ�[�A�~��m�N�o�˯��O�a�A�ǻD�L��@�����H���d��A�䮱��
�²r�L�ǡA�~�o�ӡu�@���_���v�o�ӥ~���C
LONG
);
        set("chat_chance", 5);
        set("chat_msg", ({
                "�O�d�v�c���������D�G�u�i�c���ȹΡA�ڤ@�w�n�����A�̩Ҧ��έ��A�n���ڪ��a�H���o�Ӥ�..�v\n",
                "�O�d�v���D�G�u�Q�ڭW�m�o�G�Q�~�A�m�N�o�@�����O�A�ڴN���H�����F�o�Ӥ�..�v\n",
                "�O�d�v�k�@�����@�������F�_�ӡA���ձa�_�����l���o�A���I�I�l�x��...\n",
        }));
        setup();
        set_level(15);
        set_attr("str",35);
        carry_object(__DIR__"obj/champion-belt")->wear();
        set_temp("apply/attack",100);
        set_temp("apply/damage",50);
}

int accept_fight(object ob)
{
        return 0;
}

void exchange(object player,object ob)
{
        object gloves;
        destruct(ob);
        command("snort");
        command("say �o�i���O���ӮȹΪ����F��ܡA�@�ڤ����H���~�ǡI�I�ܡI�I");
        message_vision(HIW "$N�İ_�@���A���N�j��٫������H���F...\n" NOR , this_object());
        player->set_temp("duli_port/wire-nina",1);
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_QUEST_ITEM_WIRE_NINA_")
                || is_fighting() )
           {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:�i�Ѩ�� ��-���O�u�ʤ� */
void relay_say(object ob, string arg)
{
        object note;
        if( arg=="�ۼv�ȹ�"  )  {
              command("angry");
              command("say �u�u�u�I�I�I���n���ڦAť��o�|�Ӧr�A�p�ߧڤ@�������A...");
              return ;
        }
        //////////////////////////////////////////////////////////////
        // �H�U���}�l�� �ܡЩ��O�u�ʤơ@������r
        if( ob->query_temp("duli_port/wire-nina")<1 ) return;
        if( arg=="�٫�" || arg=="�j��٫�"  )  {
                command("say �o�o....�u�O�藍��A��~�@�ɮ𼫡A���p�ߥ��a�A���F��F..");
                command("say �����گ���v�A����ܡH�H");
                ob->set_temp("duli_port/wire-nina",2);
                return ;
        }
        if( ob->query_temp("duli_port/wire-nina")<2 ) return;
        if( arg=="���v"  )  {
              command("say �o...�ڥͥ��S����n�W�A�S�������ߧA�C�A���ǧڤӾ|���F..");
              command("slap li qian-jun");
              command("sorry");
                ob->set_temp("duli_port/wire-nina",3);
              return ;
        }
        if( ob->query_temp("duli_port/wire-nina")<3 ) return;
        if( arg=="�S���Y"  )  {
              command("say �ڡI�I�A�u�O�j�j���n�H�A�n���M�ڱN�e�}�l�ߨ쪺�@�i�ȱ��e�F���A�a..");
              command("say ť���W���O���ۤ@���ܤƨt�M�Ϊ��ޯ�A�A�i�H�յۺw��(blooding)�b�W���A�N��ݨ�䤤�������C");
                tell_object( ob , CYN "(�O�d�v���F�A�@�i�p�ȱ��C)\n" NOR );
                note = new(__DIR__"obj/wire-nina-note");
                note->move(ob);
                ob->delete_temp( "duli_port/wire-nina" );
              return ;
        }
}


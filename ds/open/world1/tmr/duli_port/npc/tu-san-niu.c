#include <npc.h>
inherit F_VILLAGER;
void create()
{
        set_name("�O�T��", ({ "tu san-niu","tu","niu" }) );
        set_race("human");
        set("title","�����ȩ��j�p" );
        set("age", 60);
        set("long",@LONG
�O�T���O�����䦳�W���p�v�A�p�����A���Y�]��@��H�Ӫ��ժZ��
�O�A�A�i�H�ݨ��L�����⺡�O�M�˿S�˪��A�i�Q�Ӫ��O�C�ѳ��I�Ħb�p��
���C
LONG
);
        set("chat_chance", 5);
        set("chat_msg", ({
                "�O�T���L�̳��ۻy�D�G�u�o�خƲz���������A���N�O���Ƴ·ФF�I...�v\n",
                (: command("sigh") :),
                "�O�T�������a��ӿ�h�A�n���b�дo����...\n",
        }));
        setup();
        set_level(10);
        carry_object(__DIR__"obj/butcher-knife.c")->wield();
}

int accept_fight(object ob)
{
        return 0;
}

void exchange(object player,object ob)
{
        object gloves;
        destruct(ob);
        if(player->query_temp("duli_port/bear_paw")==1) 
                command("say �i�O���٤֨�����x�A��_�A�·бz�O�H");
        else if(player->query_temp("duli_port/bear_paw")==2) 
                command("say �i�O���٤֤@�����x�A��_�A�·бz�@���O�H");
        else {
                command("say �u�O�ӷP�¤F�A�ڥi�H�^�h�ȩ������o���·t�Ʋz�F�C");
                command("say �o�঳���ڰ��u�`�Ϊ���M�A���ϰe���A�F�a�C");
                command("say �N���A���F....");
                command("wave");
                player->delete_temp( "duli_port/bear_paw" );
                gloves = new(__DIR__"obj/skin-gloves.c");
                gloves->move( player );
                destruct( this_object() );
        }
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_QUEST_ITEM_BEAR_PAW_")
                || is_fighting() )
           {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
       command("say ���§A�F�C");
       me->add_temp( "duli_port/bear_paw" , 1 );
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:�i�Ѩ� +int 1 gloves */
void relay_say(object ob, string arg)
{
        if( ob->query_temp("duli_port/bear_paw") ) return;
        if( strsrch(arg,"����")!=-1  )  {
              command("say ��...�O�ڡA�E�ا��Ƥw���F�K�ˡA�N�֤@�˺��x�C");
        }
        if( strsrch(arg,"���x")!=-1  )  {
              command("say ť���o�੹�_�L�h���F�a���A�`���Ǻ��X�S�A���O���ɲ��`�A���O�n�S���C");
              command("say ���ڤS�����}���A�����A�O�_�i�H���ڥh���o�H");
              return ;
        }
        if( arg=="�i�H" || arg=="�n"  )  {
              command("say �n�A�u�O���±z�F�A�ڴN�b�o�൥�ۧA�a�C");
              return ;
        }
}


#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("����", ({ "wang feng","feng" }) );
        set_race("human");
        set("age", 40);
        set("long", "�����O�q�p�N��o�̪��y��A�H���y���~���͡A�ޥ��ˤ]�ᬰ�����C\n");
        set("chat_chance", 5);
        set("chat_msg", ({
                "������ۮ������D�G�o�}�l�����ˤ]���R�A�γ\�i�H�ǳƤ@�U�A�A�W���Z�q�W���y�F�C\n",
                (: command("sing") :),
        }));

        setup();
}

int accept_fight(object ob)
{
        
        return 0;
}

/* Quest:���� �q�� ���k */
void relay_say(object ob, string arg)
{
        if( arg=="te-o tsunai dara itemiyo"  )  {
              command("say �@...�o�y�ܪ��N��O�G�y�j����R�Y�n�ת���f�S�_�F�A�����o�q�W�S�S���n�l�C�z");
              return ;
        }
        if( arg=="mo eruyo natsukino kagayaku okani"  )  {
              command("say �o�y�ڴN���M���F�A�n���O���q���a�C");
              command("think");
              return ;
        }
        if( arg=="�y��"  )  {
              command("say �@...�z�n�O��ť���������Z�ܡA���ϥi�H�ӰݰݧڡC");
              command("ssmile");
              return ;
        }
        if( strsrch(arg,"���Z")!=-1 
         || strsrch(arg,"���y")!=-1 ) {
              command("say �@...�ڱq�p�N�`�h���񪺳��Z�q�W���y�A�ˤ]���X�y�L�̪��y���C");
              return ;
        }
}


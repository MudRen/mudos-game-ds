#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
        set_name( "ø�z��", ({ "sawajiri erika", "erika"}));
        set("long", @LONG
ø�z���嫬A���A����160cm�Aø�z���W�r�ѨӬO�᪺�W�r�A���Y��
�쪺�@��(Erica)�C�~�������p�֤k�몺�M�¡A���ʮ�o�O�ʪK�j���A
ø�z�����H�����ۤv���өʫܨk�Ĥl��C

�s�f�Х� <list>
�n�R�F��� <buy �s�� ticket>�B<buy ���~>�B<buy �ƶq ���~>
�n����� <reward>
LONG
        );
        set("level", 1);
        set("title", HIG"������"NOR);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("exp",1000);
                set("attitude", "peaceful");   //�ũM�� NPC�C
                set("sell_list", ([     
             TICKET    : 1, 
                ]) );

  set("no_kill",1);
  set("no_fight",1);
  set("chat_chance", 1 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
        "ø�z�����������ۡG�u�o��j����, �n���n�R�I�m��<buy>�ڡH�ڽ檺�m��<list>�����v�ܰ���I�I�v\n",
        (:command("smile"):),
        }) );

    setup();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_reward","reward");
}

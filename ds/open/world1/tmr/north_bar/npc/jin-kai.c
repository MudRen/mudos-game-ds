#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;

void create()
{
//=========================�򥻳]�w==========================

        set_name( "���}", ({ "jin-kai boss","jin","jai","boss"}));
        
        //tmr, long�A�ۤv���a. �t�Ieq..
        set("long", "�@�Ӭ�����Ȫ��L�D���~�H�A�@�y�Ʈ�A�]�O�o���������D�H�C\n"
        );
        
                set("no_kill",1);       // ����Q��

        set("level", 4);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 30);
        set_skill("blade",40);          // �ޯ�(�۩w)
        set_skill("parry",40);          //
        set_skill("dodge",40);          //
           set("attitude", "peaceful");   //�ũM�� NPC�C
           set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");

          set("chat_chance", 3 );  //�ʧ@���v
          set("chat_msg", ({       //�ʧ@���e
        (: command("walk") :),
        }) );
  

        setup();

        add_money("gold", 1);          
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


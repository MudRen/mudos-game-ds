// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void call_help();
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�����ѪO", ({ "bank boss","boss"}));
        
        set("long", "�@�Ө�����R�A�������~�H, �O�Y�s�������ѪO�C\n\n"
                    +"  �d�߱b��Х� <balance> \n"
                +"  �n�s���Х� <deposit �򥻪��B> \n"
                    +"  �n�����Х� <withdraw �򥻪��B> \n\n"
        );
        
        set("level",17);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 30);
        set("evil",20);                 //���c�� 20 (�������c, �t���})
           set("attitude", "peaceful");   //�ũM�� NPC�C
           set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");
        
          set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
        (: command("stare") :),
        }) );

        setup();

}

void init()
{
  ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}



// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name("�����t", ({ "hoodlum"}));
        set("long",@LONG
���e�O�@���s�~�����~�H�A�L���۷�j����s�{�A�����]���s��L��
����o�x���C���L�A�q�L���������i�H���D�L���O�@��²�檺�H���C

                �l�B�d��        <balance>
                �s��            <deposit ���B>
                ����            <withdraw ���B>
LONG);
        set("level",20);
        set("title","�y�]");
        set("gender", "�k��");
        set("race", "human");
        set("age", 50);
        set("evil",100);                //���c�� 20 (�������c, �t���})
        set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");
        set("no_kill",1);
set("inquiry/name", @LONG
��������D��ڴN��F�A�����A�ѨM�I���h�l�����]�i�H���A�O�ޡC
LONG );

        setup();
}

void init()
{
 ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

#include <ansi.h>

inherit NPC;

void do_attack();

void create()
{
        set_name("�P��",({"zhou ying", "zhou","ying"}) );
        set("long",@long
    �P��O�U������D���W�ͤk�A�����M�q�i�R�A�@���O�U������H
���x�W���]�C�u���o���۫樫�Ө��h�A���G�b������H�@�ˡC
long
);
        set("age",18);
        set("race","�H��");
        set("level",25);
        set("attitude", "peaceful");
        set("title","�U����ĤQ�T�N�̤l");
        set("gender", "�k��" );
        set("chat_chance",6);
        set("chat_msg",({
                "�P�뻡�G�H�Ǹ�^�Ǩ�������o��[���٨S���X�ӡA�u�O�榺�H�F�C\n",
                (: command("sob") :),
        }) );

        setup();
}




#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����",({"god-father","father"}) );
        set("long",
"�@����Y�������A�L���b���D�A�J�Ӥ@�@�A��ӬO���䪺��v�����ͪ��ۼv�C \n"
);
        set("gender","�k��");
        set("age",30);
        set("level",5);
        set("race","�H��");
        set("chat_chance",1);
        set("chat_msg",({
"�������D�G �ڭ̪��Ѥ��A���A���W���㴭�F\n",
"�������D�G�@�A������{;�@�A�����N�^��b�H���A�p�P�b�ѤW�C\n",
"�������D�G�D�A���ѽ൹�ڭ̤�Ϊ���³�F\n",
"�������D�G�D�A�e���ڭ̪��o�L�A�p�P�ڭ̼e���O�H�@�ˡF\n",
"�������D�G���n���ڭ̳��󻤴b�A���ϧڭ̧K�󤿴c�C\n",
"�������D�G�y�ȩs�K�z\n",
        })      );
    set_temp("float",1); 
        setup();
}
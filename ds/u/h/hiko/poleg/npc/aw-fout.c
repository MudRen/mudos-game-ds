#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ƾW",({"aw fout","aw","fout"}) );
           set("long",
            "�A���e�@�G�A���T�Q�o�쨭�ۥզ�A���զp�ɡA���׽������t�x�k�l\n"
            "�ҧl�ަ�A�u���L�@�y�H�C�A���ɦa�i��A���G���M��F�誺�ˤl�C�Ӭ�\n"
            "���n���ݫe�e���C������A�t�����իC���|�u�����C�����^��Q���A��\n"
            "����M�A�@���K�o����Z�N�y�ڤ����C\n"
           );
        set("age",28+random(4));
        set("race","�H��");
        set("level",28+random(5));
        set("title","�i�Ʊ����j�ĥ|�N�Ĥl");
        set("gender", "�k��" );
        set("Merits/wit",2);
        set("chat_chance",5);
        set("chat_msg",({
            "�ƾW���ۻy�a���D�G�o�ӭn���~����L�O?\n",
            (: random_move :),
        }) );
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("sword",70);
        set_skill("awmay-ken",80);
        setup();
        carry_object(__DIR__"wp/faumin-sword")->wield();
}



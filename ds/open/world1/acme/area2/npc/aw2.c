#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ƵL��",({"aw wu hen","aw","hen"}) );
        set("long","�L�O�Ʊ������Ĥl�A�@���b�ո˧�A��n���ݫe�e���C������A�t�����իC���|�u�����C\n");
        set("age",35);
        set("race","�H��");
        set("level",25);
        set("title","�i�Ʊ����j�ĥ|�N�Ĥl");
        set("gender", "�k��" );
        set("Merits/wit",2);
        set("chat_chance",5);
        set("chat_msg",({
            "�ƵL�����ۻy�a���D�G�o�ӬI�������⨸�Ф@�z�H�è���h�F�C\n",
            (: random_move :),
        }) );
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("sword",70);
        setup();
        carry_object(__DIR__"wp/longsword2")->wield();
}

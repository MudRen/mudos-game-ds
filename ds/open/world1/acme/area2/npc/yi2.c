#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�I���w", ({ "yi huan shi","shi" }) );
        set("gender", "�k��" );
        set("long",
            "�o�O�I�����k��A�ֽ��۷���աA���o�T�ܭW�y�A��������дo�C\n"
           );
        set("age",17);
        set("level",10);
        set("chat_chance", 2);
        set("chat_msg", ({
             (:command("sigh"):),
        }));
        set("talk_reply","���I�I�o�X�ѫܦh�H�ӧ�R�R�A�ݨӤ��O����n�ơC\n");
        set("inquiry", ([
            "�дo": "���I�I�o�X�ѫܦh�H�ӧ�R�R�A�ݨӤ��O����n�ơC\n",
            "�H��": "�o�O�R�R�M�O�H�U���ѡA�]�R�R���ƩҥH�s�ڥ��ݵۡA�A�i�O�ðʰڡC\n",
        ]) );

        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                "�I���w�s�D�G�ϩR�ڡI�ϩR�ڡI���H�n�����ڤF�ڡI\n",
               (:command("help!"):),
         }) );
        setup();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{

        if( (arg!= "down") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
      command("inn");
           say("�I���w���D�G"HIB"�R�R�����i�H�i�h�A�����Y���|�Y�H���]���@�C\n"NOR);
        return 1;
}

#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "����", ({ "pickpocket",}));
        set("long", "�@�Ӹ������ê�����A���b�ݪF�ݦ�C\n"
        );
        set("level",10);
        set("title","�~�a�H");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("attitude", "peaceful");   //�ũM�� NPC�C
 set("chat_chance", 4 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"����X$n����N�ɡA�X����$n���f�U���Ӽ��h\n",
(:command("grin"):),
(:command("shrug"):),
}) );

        setup();
        add_money("coin",100);
}





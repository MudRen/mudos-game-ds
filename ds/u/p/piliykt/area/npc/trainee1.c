#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�m�ߥ�",({ "trainee" }) );
        set("long",@LONG
�o�̪��m�ߥ�, ���O�����ۦ�������̪��C�~�n��, �ݥL�̤@�ӭ�
�髬�j��, �V�̽m�Z������, �ϧA�����b���[��.
LONG    
);
        set("race","�H��");
        set("age",25);
        set("level",18);
        set("attitude","friendly");
        set_skill("dodge",30);
        set_skill("unarmed",50);
        set_skill("parry",20);
         setup();
        
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�x�ȩx" , ({ "guard" }) );
        set("level", 10);
        set("con", 15);
        set("age",30);
        set("str", 10);
        set("dex",10);
        set("int",10);
        set_skill("parry", 10);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set("long","�L�O�W�s�x�Ϊ��x�ȩx�A�t�d�޲z�@�ǭx�ΤH�f�հt���D�C\n");
        set("chat_chance", 5 );
        set("chat_msg",({HIC"�x�ȩx���D�G�ڦb���I�O�Z�ڡI\n"NOR,
           (:command("snicker"):),
        }) );
       setup();
}      

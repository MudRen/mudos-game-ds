#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("���H", ({ "traveller","���H" }) );
        set("long","�@�쥿�b�������H�C\n");
        set("level",1);
        set("age",35);

        set("combat_exp", 10); 
        set("chat_chance",10);
        set("chat_msg",({
            "���H��:�n�ְ�!....\n",
        }) );                               
        set_skill("combat", 0);
        set_skill("parry", 0);
        set_skill("unarmed", 0);
        set_skill("dodge", 0);
         
        setup(); 
carry_object("/u/t/tako/gsword")->wield();        }




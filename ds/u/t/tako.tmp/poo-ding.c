#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIY"���B"NOR, ({ "poo ding","ding" }) );
        set("long","�i�R���k��,�O�@��������H�C\n");
        set("level",10);
        set("age",15);

        set("combat_exp", 10); 
        set("chat_chance",10);
        set("chat_msg",({
            "���B��:�Ѥ��X�h�e�f����٨S�^�өO..^^....\n",
        }) );                               
        set_skill("combat", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
         
        setup();
        }


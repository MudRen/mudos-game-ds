#include <ansi.h>
inherit NPC; 
void create()
{
�       set_name(MAG"�Ԫ�"NOR, ({ "ling jia","jia" }) );
        set("long","�F�v�ԳN������C\n");
        set("level",40);
        set("age",45);

        set("combat_exp", 20000); 
        set("chat_chance",10);  
        set("combat_msg", ({
"$N�ΥX�F�v�ԳN���� "HIC"�g�P"NOR" ,$N���M�p��a�U,$n���y�F�X��\n"
"$N�������q�a�����X��,�        set("chat_msg",({
            "���B��:�Ѥ��X�h�e�f����٨S�^�өO..^^....\n",
        }) );                               
        set_skill("combat", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
         
        setup();
        }




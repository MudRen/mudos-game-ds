#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�O�w", ({ "bo officer","bo","officer" }) );
        set("level",30);
        set_skill("dodge",55);
        set_skill("parry",70);
        set_skill("sword",68);
        set("long" ,"N.Y.T.�@�P�ŤW�N�C\n");
        set("age",45);
        set("title",HIY"N.Y.T.�W�N"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
                         "�O�w�j�n�۵�:�����H���ФŨ��X�C\n",
        }) );
        setup();
        carry_object("/u/b/basic/wp/sword1")->wield();
        
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���K��", ({ "mimi guard","guard" }) );
        set("long","���~�u�b�j�ӱK�ǤU�������H�A�ت��b����X�S�����~�C\n");
        set("level",20+random(15));
        set("age",38+random(4)); 
        set("title",HIG"��"NOR);
        set("combat_exp", 30000);
        set("chat_chance",12 );
        set("chat_msg", ({
  "���K�Ȼ��G�֨��֨��A�o�̫ܦM�I�A�H�ɷ|�����~�X�S!!\n", 
})); 
        set_skill("parry", 80);
        set_skill("unarmed", 90);
        set_skill("dodge", 130);
        setup();
        carry_object(__DIR__"obj/mi-neck")->wear(); 
} 
void die() 
{
    object ob; 
    if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);

    if( !ob ) { 
        ::die();
        return;
    } 
    ob->add("popularity",1); 
    message_vision("$N�����@�����F�C\n", this_object() );
    ::die();
    return;
}


#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name(HIW"���Ѥj"NOR,({"fish boss","boss","fish"}));
       set("race","���~");
       set("level",25);
       set("max_hp",2222); 
       set("age",50);      
       set("attitude","friendly");
       set("devil",20); 
       set("limbs", ({ "�Y��", "����", "����", "����"}) );
       set("verbs", ({ "claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�����A�ڤD���s���Ѥj�A�ګܷR���A�֭n��ڪ��ڡH\n" }) );
       set("long",@LONG      
���s�̪��Ѥj�A�ݰ_�ӴN�ܮz�A���|�O�Ѥj(=.=?)�C

LONG
); 
        setup();
} 
void die()
{
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
       HIY"\n\t�s���W�D�G���Ѥj��"+ob->name(1)+"�����[�A���G�����������F�I\n"+NOR,users());
        ob->add("popularity",1); //�n��
     message_vision( "$N���G��...��....�ڤ����F..." ,this_object() );
        ::die();
        return;
}

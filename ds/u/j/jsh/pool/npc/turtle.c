#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name(CYN"�ȪZ"HIW"���t"NOR,({"shang-woo god turtle","turtle"}));
       set("gender","���~");
       set("level",40+random(15));
       set("max_hp",35000); 
       set("age",432+random(32));      
       set("attitude","unfriendly");
       set("devil",20); 
       set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����","�t��" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�ȪZ���t�n�F�n���ڡA�ê`���۬Y�˪F��C\n" }) );
       set("long",@LONG      
�g�˪��F��A�s�Y�t���A�����q��ήe�A�쥻�V�v����
�����]�U�F�߷R�������A���X�F�����C
LONG
); 
        setup();
} 
void die()
{
   object ob,obj;
   obj=new(__DIR__"obj/turtle-armor");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIY"\n\t:+:���H�P�}:+:\n"
   CYN"\t\t\t���ȪZ�� "+HIW"���t "+HIR "�Q"+ob->name(1)+"�����ŤF�I\n\n"+NOR
        ,users());
        ob->add("popularity",4); //�n��
     message_vision( "$N�@�Y���b�a�W�A�Y�W���ȥۤ]�H������" ,this_object() );
     obj->move(environment(this_object() ) );
    obj=new(__DIR__"obj/turtle-liver");
       obj->move(environment(this_object() ) );
        ::die();
        return;
}


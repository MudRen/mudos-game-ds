#include <ansi.h>
inherit NPC;

void create()
{
             set_name(HIR" ��  �s"NOR,({"fire dragon","dragon"}) );        
             set("title",HIW"�t��"NOR);             set("long",@LONG
���s�O�t����̪��u�@�~�A�d�ʦ~�Ӿn�u�b���A���W���۸Ѷ}
�������������䪫�~�C
LONG    
        );
        set("race", "���~");    
        set("unit","��");
        set("age",1000+random(123));
          set("level",40);
        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","����","�s��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_armor",200);
        add("addition_damage",230);
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"obj/liver");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIR"\n�i �t  ��  �� �j  "+ob->name(1)+"  ��   �o   ��   �s   �x   �F�C\n\n"+NOR
        ,users());
        ob->add("popularity",3); //�n��
     message_vision( "$N"+HIR"�o�X�F�L��������A�b�������`�B�榨�F�@���� . . ." NOR ,this_object() );
     obj->move(environment(this_object() ) );
    obj=new(__DIR__"obj/liver");
        ::die();
        return;
}


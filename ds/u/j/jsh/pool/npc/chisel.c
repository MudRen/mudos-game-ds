#include <ansi.h>
inherit NPC; 
void create() 
{ 
       set_name(HIG"�Ѳ�"HIW"����"NOR,({"blue-eyes chisel","chisel"}));
       set("gender","���~");
       set("level",40+random(15));
       set("max_hp",25000); 
       set("age",432+random(32));      
       set("attitude","unfriendly");
       set("devil",20); 
       set("limbs", ({ "�Y��", "����", "���}��", "�k�}��", "���l","�k�l" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�Ѳ����紧�ʵۤj�ͻH�A���_�F�@�}�}�j���C\n" }) );
       set("long",@LONG       
�n�ӥ��j������,���ۺѺ�p����������,���l�i�}�ӳ��i�B�ѻ\�a,
�ӥB��}���O����,��_�Ǫ��O�p���K�몺���L�W�ٴ��ۤ@��{ģ���������C 
LONG
); 
        setup(); 
 carry_object(__DIR__"obj/chisel-claw")->wear();
 carry_object(__DIR__"obj/perple-sword");
} 
void die()
{
   object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",4);
        message("world:world1:vision",
   HIW"\n\t�ѪŤ������N��Ѳ����窺�J�R�P�f���F�A�A���G�i�Hť��"+ob->name(1)+"�������n�C\n\n"+NOR
        ,users());
     message_vision( "$N�������ʵۯͻH�A�Q�A���_�ӡA�i���E�E�i���E�E" ,this_object() );
        ::die();
        return;
}



#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�d�h��", ({ "snow" }) );
        set("level",60);
           set("combat_exp",6000);
         set("exp",1500);
set("long","�o��O�a���̳̮��ƪ�����A����a���]���ФC�P�]�P�A���ɤF�L�ƪ�����
�A���O���Y�ѥP���~����O�P�o�D�ȯ�߸z����q�ۤϡC\n");
;
        set("age",20);
        set("evil",70);
      set("race","human");
     set("title",HIR "��{"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",80);
        set_skill("dodge",80);
                  set_skill("parry",80);
        set_skill("dagger",100);
        setup();
        carry_object(__DIR__"wp/devil-dagger")->wield();
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
HIC"\n  �������H���֪��t�צ^��:"HIW"\n\n\t�԰�ӳ��Ĥ@����u�d�h���v���b"+ob
->name(1)+"���⤤�F�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
        ::die();
        //destruct(this_object());
        return;
}

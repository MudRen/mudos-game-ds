#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�a�ݤѨ�", ({ "di chan tan lu","di","tan","chan","lu" }) );
        set("level",70);
           set("combat_exp",5500);
           set("evil",99);
        set("long",
            "�L�O�Ʀʦ~�e�խߦa�������Ѵݨ��Ъ��v�̡A�L���~�w�ܦ�\n"
            "������������L�줵�ɤ��餴�M��ͦs�A��b�t���@�I���۫H....\n",
        );
        set("age",1000);
        set("gender","�k��");
        set("title",WHT"�i�a���Ѥ��j"NOR);
set("attitude", "friendly");
        set_skill("unarmed",100);
           set_skill("dodge",100);
           set_skill("parry",100);
     set("chat_chance_combat",80);
        set("chat_msg_combat", ({
           (:command("say �A�o�c��A���ڳo�@�ۡA�����a�I�I�I"):),
        }) );
       setup();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}

int do_guard(string arg)
{

           object me;
           object obj;
           me=this_player();
           obj=this_object();
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
        write("�a�ݤѨЬ�M�V�ۧA���F�L�ӡA�Q�Y�F�A��...");
        obj->kill_ob(me);
        return 1;
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
 message("world:world3:vision",CYN"\n  ��M�ѪŤ��X�{�F�@�ǩ_�Ǫ��r�y:\n\n\t�i�a���Ѥ��j�ש�ѵ��F"+ob->name(1)+"�C\n\n"+NOR,users());
        ob->add("popularity",3); //�n��
        ::die();
        //destruct(this_object());
        return;
}

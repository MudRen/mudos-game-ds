//
// �`�N, ���p�n�}�� npc, �Ч� add_action("do_guard", "go");
//
#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�a��", ({ "di chan","di","chan" }) );
        set("level",60);
        set("long",
            "�L�O�Ƥd�~�e�խߦa�������Ѵݨ��Ъ��v�̡A�L���~�w�ܦ�\n"
            "������������L�줵�ɤ��餴�M��ͦs�A��b�t���@�I���۫H....\n",
        );
        set("age",2000);
        set("gender","�k��");
        set("title",WHT"�i�ӥj�H���j"NOR);
        set("attitude", "friendly");

        set_skill("blade",50);
        set_skill("dodge",100);
        set_skill("unarmed",110);
        set_skill("parry",100);

        set("chat_chance_combat",80);
        set("chat_msg_combat", ({ (: command("pk") :), }));
        setup();
        carry_object(__DIR__"wp/tan-chanblade.c")->wield();
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
        write("�a����M�V�ۧA���F�L�ӡA�Q�Y�F�A��...");
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
        message("world:world3:vision",CYN"\n  ��M�ѪŤ��X�{�F�@�ǷϤ�:\n\n\t�a�����F"+ob->name(1)+"�����F.....\n\n"+NOR,users());
        ob->add("popularity",1); //�n��
        ::die();
        //destruct(this_object());
        return;
}


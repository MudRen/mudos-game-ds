#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ѹ�", ({"rat"}) );
        set("long", "�@�������ë����p�ʪ�, �᭱�٩�ۤ@�����������ڡC\n");
        set("unit","��");
        set("race", "���~");
        set("limbs", ({ "�Y��", "����", "����", "��}","�e�}"})); //���𳡦�
        set("verbs", ({ "bite","claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
        set("age", 1);
        set("level",1);
        set("dex",1);
        set("str",1);
        set("con",1);
        setup();

}
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;

        message("system",
                "\n\n�ѹ����㪺�j�q�G�i�c��"+ ob->name(1) +"�A�~�M�ۭt�@���ѹ��I�I\n\n",
                users() );
        destruct(this_object());
}

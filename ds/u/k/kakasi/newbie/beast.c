#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("�׸}�����~", ({ "vaca beast","beast" }) );
        set("race", "���~");
        set("age", 101);
     set("level",1);

        set("long", "���������V�q�A���R�̯����ǩ��~�C\n");
        
        set("str",1);
        set("max_hp",30);
        set("dex",-2);
        set("int",1);
        set("con",1);

        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 50);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "���~�Τ�����X�@�Ӥj�j����ˡC\n",
                "���~�r�ݵۤ�W����ˡA���G�O�Q�Y�F���C\n",
                "���~���M��ۤѪ��S�ۤ@�y�b�ˡC\n" }) );
                

        setup();
}

int accept_object(object who, object ob)
{
        if( ob->id("bone") ) {
                set_leader(who);
                message("vision", name() + "���_���̯��C\n", environment());
                return 1;
        }
}


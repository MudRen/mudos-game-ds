#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR"��z��"NOR, ({ "to fascinate man","man" }) );
        set("level",40);
        set("combat_exp",4000);
set("exp",3000);
        set("evil",80);
        set("long","�L�O�խߦa�����M�Ļ�ϦX�١y�խߤG�O�z���խߦa�����k\n"
                   "�@�k�A�����Ʃ�T�Q�~�e���ѫ��ԧФ��A�Q�y�v���ѡA���y\n"
                   "�v�v�ߤ��p�A���N��B���A�u�D�_�L���⵬�A����ͦ��C��\n"
                   "�Q�Ѵݨ��Щ���ϡA���q���Z�\\�j�h�A�o�N���ޤ]�q���Ϥ�\n"
                   "�X�ӡC\n"
            );
        set("age",100);
        set("attitude","killer");
        set("gender","�k��");
        set("title",HIR"�s�]�ûR"NOR);
        set_skill("unarmed",70);
        set_skill("dodge",70);
        set_skill("parry",70);
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
"��z�ϳܹD�G��I��I�n���O�T�Q�~�e���@���ѫ��ԧФ��A�Q�y�v\n�D�_�⵬�A�n���M�N���A�|�|�u�d�����z�v���F�`�C\n\n",
                       }) );
       setup();
       carry_object(__DIR__"obj/lamp2.c");
}


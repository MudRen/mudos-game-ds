#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��j�p",({"cooker",}));
 set("long","             �A�ݤF�@�ݲ��e���p�v, �u���L�⤤����½��, ���e���j��
                    �A���԰ժ��T��, �A���T�ﲴ�e���o��p�v�P��ܨ�, �]����P��p��
                    �]�O�@�����`���ǰ�."
     );
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","�k��");
 set("level",10);
 set_skill("unarmed",50);
 set("chat_chance",10);
 set("chat_msg", ({"�ѱ��j�p�ۨ��ۻy����: �_�ǤF....��a�|����? \n",
                        "�ѱ��j�p�S���ۻy����: ����"HIY"��"NOR"�쩳�b��?\n" 
}));
 set("chat_chance_combat",60);
                         (:command,"say �z�� ~~~":),
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
int accept_object(object who, object ob)
{
        if( 
ob->id("worm") ) {
                message("vision", name() + "���F�@��, �H�Y���������F�_��!\n", 

environment());
                return 1;       //�Ǧ^1�N��ܥi�����F��
        }
}

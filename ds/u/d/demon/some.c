#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG "�Y�H" NOR,({"somebody","somebody"}) );
        set("long",@LONG
 �ǻ���ۨ��Z�\�m�ܬY�@�Ҭɫ�A�K�i�H�`�p�����O�N��������� �ۥj�H�ӱq�S�H�m�ܹҬɡA���۶Ǿ�(Demon)�H�F���ҬɡA[37m�y[0m�ӵL�v�h�L��[37m�I�z�C[0m
LONG    
        );
        set("race", "���~");    
        set("unit","��");
        set("age",80);
        set("level",80);
        set("chat_chance",10);
        set("chat_msg",({
        "�Y�H�@���ѧ��b�a�W��ۤ@�賥��o�_�b��...\n",
        "�Y�H�j���L�L�a��F�A�@���C\n",
        "�Y�H�f����䪺��D�G�u�A�ݤ���ڡ�A�ݤ���ڡ�v\n",
        }) );

        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","�}","����" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
//����        carry_object(__DIR__"obj/paper");
}


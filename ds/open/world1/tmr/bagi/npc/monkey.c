#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "�դ�j��" NOR,({"white monkey","monkey"}) );
        set("long",@LONG
�@���դ�j��A�W�~�b���s���A�o�Ѧa���F��A���w�~�L�K�Q�A����
���ۦp�A�����ѼˡC�䲴���`�㤤�z�S�ۤ@���F�ʡC
LONG    
        );
        set("race", "���~");    
        set("unit","��");
        set("age",80);
        set("level",30);
        set("chat_chance",10);
        set("chat_msg",({
        "�դ�j��@���ѧ��b�a�W�A��ۤ@�賥��o�_�b��...\n",
        "�դ�j��j���L�L�a��F�A�@���C\n",
        "�դ�j���ۧA�s�F�n�G�u�s��v\n",
        }) );

        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","�}","����" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
         carry_object(__DIR__"obj/paper");
}


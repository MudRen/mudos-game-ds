#include <ansi.h>
inherit ITEM;

void delay();

void create()
{
        set_name(HIC"�t"+HIG+"��"+HIY+"��"NOR,({"christmas tree","tree"}) );
        set("long","
�@�ʱ����F�C�m�O���B�콦�p���㪺�t�Ͼ�A����������ۡA�@�}�}��
�ժ����n�������t���ۡA����өж����R���F�t�ϸ`����^...: )
�n�n�t�Ͼ�(shake �t�Ͼ�)�A�|�ۺq���I�I
(��W���ۤ@�ӵP�l�G�ª����p�M�h�ѥ��������q�Ͳ�)\n"
        );
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
/*      set("chat_chance",15);  // �o�O ITEM ���|�Ψ� chat_chane ��.
        set("chat_msg",({       // �u�� NPC �|��.
        "�u�m�m���A�m�m���A�a�n�h�T�G���v\n",
        "�u�A�ݥL�A���׭����A���e�h��O�����v\n",     
        }));*/
        setup();                
}

void init()
{
       add_action("typeshake","shake");
}

int typeshake(string arg)
{
        object me;
        me=this_player();
        if( arg != "�t�Ͼ�" && arg != "christmas tree" && arg != "tree" ) return 0;
        if( query_temp("ch_used") )
                return notify_fail("�ݰ_�Ӹt�Ͼ��٦b�n�A���G�O���֩|���T�����I\n");
        message_vision(HIC"$N�������n��U�t�Ͼ�A�@�}�M�A���ժ����n�ǤF�X�ӡ��\n\n"NOR,me);
        message_vision(HIY"�u�m�m���A�m�m���A�a�n�h�T�G���v\n\n"NOR,me);
        message_vision(HIG"�u�A�ݥL�A���׭����A���e�h��O�����v\n\n"NOR,me);
        set_temp("ch_used", 1);
        call_out("delay", 30);
        return 1;
}

void delay()
{
        delete_temp("ch_used");
}

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"�t"+HIG+"��"+HIY+"��"NOR,({"christmas tree","tree"}) );
        set("long","
�@�ʱ����F�C�m�O���B�콦�p���㪺�t�Ͼ�A����������ۡA�@�}�}��
�ժ����n�������t���ۡA����өж����R���F�t�ϸ`����^...: )
�n�n�t�Ͼ�(shake �t�Ͼ�)�A�|�ۺq���I�I
p.s.�t�Ͼ�ϥγW�h���Pchannel�Ϊk,�~�ù��̵��P�H��rules...
(��W���ۤ@�ӵP�l�G�ª����p�M�h�ѥ��������q�Ͳ�)\n"
        );
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set("chat_chance",15);
        set("chat_msg",({
        "�u�m�m���A�m�m���A�a�n�h�T�G���v\n",
        "�u�A�ݥL�A���׭����A���e�h��O�����v\n",        
        }) );
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
        if(arg != "�t�Ͼ�") return 0;
        message_vision(HIC"$N�������n��U�t�Ͼ�A�@�}�M�A���ժ����n�ǤF�X�ӡ��\n\n"NOR,me);
        message_vision(HIY"�u�m�m���A�m�m���A�a�n�h�T�G���v\n\n"NOR,me);
        message_vision(HIG"�u�A�ݥL�A���׭����A���e�h��O�����v\n\n"NOR,me);
        return 1;
}



#include <ansi.h>
inherit NPC; 
inherit SELLMAN;
void create()
{
        set_name( "�٢�-��������", ({ "KF1102","kf1102"}));
        set("long", "�o�O�s�s�y�������H,�㦳�۷���AI,�]�N�O�ڭ̩Ҭ���Artificial Intelligence-�H�u���z�C\n�o�i�H���O�̨㦳�n��A�̨�n���A�̨㦳���k�X�j�S�x���@��I�I�I\n");
        set("level",6);
        set("gender", "�k��");
        set("race", "�����H");
        set("age", 15);
        set("combat_exp",400);      
        set("evil",-20);     
        set("attitude", "friendly");  
        set("chat_chance", 1 ); 
        set("chat_msg", ({       
        (:command("smile"):), 
        "�٢Ԣ����������D�R�n�ڥ��ӧ�ܡI�I�I\n",   
        "�٢Ԣ����������D�R�ȤH�R�I�F��a�I�I�I\n",   
        "�٢Ԣ����������D�R�o�~�Y���R�I���㪺�O�����b���|�W�ߨ����C\n",
        }) ); 
        set("sell_list",([      
                 "/u/m/mulder/area/npc/eq/boots"       : 20,     
                 "/u/m/mulder/area/npc/eq/armor"       : 20,     
                     ]) );
        setup();
}
 void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}







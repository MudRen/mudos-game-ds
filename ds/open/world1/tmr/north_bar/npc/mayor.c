#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������",({ "mayor lee","mayor","lee" }) );
        set("long","�o�ӧ��l�������A���ɳ��w�����ơA�ҥH�o��\\�h�H���ؼ��C\n");
        set("race","�H��");
        set("age",60);
        set("level",10);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "�������ĹD�G�o�Ӭ}�ޯu�O�����ȩ_�A�����D���Y����ۤ���ͪ�...\n",
        "�������ܷдo�a���Ө��h...\n",
        }) );
        setup();                
}

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
        "�������ĹD�G��..�������ӦL�O�]�h���F...\n",
        "�������ܷдo�a���Ө��h...\n",
        "�������D�G�u�O�o���@�Ѫ��]�ߡA�X�{�@�ө_�Ǫ��ܼv..���W�L�O�N�����F...\n",
        }) );
     set("inquiry/�L�O","�@�ӷ�ɧڷ�W�����ɮ��쪺�L�O�A�ܭ��n��..\n"NOR);       
     set("inquiry/�ܼv","�ڤ]�ݤ��ӲM���A���Lť�������n�����ܼv�]�i�j�}...\n"NOR);       
        setup();                
}

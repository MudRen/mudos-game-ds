#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����",({ "villager" }) );
        set("long","��b�_�Z���������A���`�߷R�b�ǤW�ó}�C\n");
        set("race","�H��");
        set("age",30);
        set("level",10);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "�����ĹD�G��..����Ѱ��H�ٯu�i��...�i���ڨS�k�l���o�C\n",
        "�������D�G�o�ӧ��l�ٯu���M..�i����������, �����ӪF���..\n",
        (:command("stare"):),
        (: random_move() :),
        }) );
        setup();                
}

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���M" , ({ "bi ching bonze","bonze" }) );
        set("level",4);
        set("race","�H��");
        set("gender","�k��");
        set("age",15);
        set("title","�ⶳ�x�p�M�|");
        set("long","�L�O�ⶳ�x���p�M�|�A���T�ܭW�y�A�����b�W�o����C\n");
        set("chat_chance", 3 );
        set("chat_msg",({
           "���M���D�G���A�ʦx�v���S�s�ڱ��a�F�C\n",
          (: random_move :),
        }) );
        setup();
carry_object(__DIR__"wp/staff2")->wield();
}

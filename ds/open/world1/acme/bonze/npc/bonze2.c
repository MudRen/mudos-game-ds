#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���`" , ({ "bi shung bonze","bonze" }) );
        set("level",4);
        set("race","�H��");
        set("gender","�k��");
        set("age",15);
        set("title","�ⶳ�x�p�M�|");
        set("long","�L�O�ⶳ�x���p�M�|�A���T�ܭW�y�A�����b�W�o����C\n");
        set("chat_chance", 3 );
        set("chat_msg",({
           "���`���D�G���A��...�x..�v��...�S�s�������M...���a�F....�C\n",
           "���`���D�G�o...�o��I�D...�p�p...�p��..�O..�O�^�ˤF...�C\n",
          (: random_move :),
        }) );
        setup();
carry_object(__DIR__"wp/staff2")->wield();
}

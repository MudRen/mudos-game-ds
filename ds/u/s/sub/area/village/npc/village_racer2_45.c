#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�p�֥�",({"Kenny Roberts Jr.","kenny","roberts","jr"}));
    set("long",@LONG
Kenny Roberts Jr.�ݰ_�Ӥ@�I�]�����O500cc grand-prix���M�h�A
�L�O�@�Ӭ۷���S���ꪺ�@�ӤH�C

�͡@��G1973/ 8/ 25
�X�ͦa�GHickman, USA

LONG);
    set("level",45);
    set("title","�t����");
    set("age",27+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;36m�[1m�[1m�[1m~[0m");
        setup();
carry_object(__DIR__"eq/arai_hands_6")->wear();
carry_object(__DIR__"eq/arai_head_14")->wear();
carry_object(__DIR__"eq/arai_legging_10")->wear();
}

#include <ansi.h>
inherit NPC;
void create()
{
    set_name("���~",({"Michael Doohan","michael","doohan"}));
    set("long",@LONG
�m�����n���~�A�@���T�L�L���W�r�A�P�D���Hť��L���W�r�S�����_
�߷q§���C�L�OWGP 500 '94~'98 �@�ɫa�x�C

�ͤ�G1965�~6��4��

LONG);
    set("level",45);
    set("title","�t����");
        set("age",35+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;31m�[1m�[1m�[1m�[0m");
        setup();
carry_object(__DIR__"eq/arai_pants_17")->wear();
carry_object(__DIR__"eq/arai_shield_14")->wear();
carry_object(__DIR__"eq/arai_surcoat_10")->wear();
}

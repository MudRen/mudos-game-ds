#include <ansi.h>
inherit NPC;
void create()
{
    set_name("ù��",({"Valentino Rossi","valentino","rossi"}));
    set("long",@LONG
Valentino�i�H���O���FGP�ҥX�ͪ��A�]���L������Graziano Rossi 
���g�]�O�@���ɨ���C 

�ͤ�G1976�~2��16��
�X�ͦa�G�q�j�Q Urbino
�P�y�G���~�y
�����B�魫�G180cm�B70kg

LONG);
    set("level",45);
    set("title","�t����");
    set("age",24+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;33m�[1mp[1m�[1m�[1m�[1mL[0m");
        setup();
carry_object(__DIR__"eq/arai_armor_25")->wear();
carry_object(__DIR__"eq/arai_boots_12")->wear();
carry_object(__DIR__"eq/arai_cloth_22")->wear();
}

inherit NPC;

void create()
{
        set_name("�q�u", ({ "mine worker","worker" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",12);
        set("age",30);
        set("evil",-10);
        set("long",@LONG
�b�q�|�u�@���u�H�A����j���O�j�p���A�ӭӳ����O�n�ۻP
������C
LONG
);
        setup(); 
carry_object("/open/world1/tmr/wujian/npc/obj/iron-hoe.c")->wield();
}

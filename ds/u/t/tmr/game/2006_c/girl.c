#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�t�Ϥp�k��", ({ "christmas girl", "girl" }) );
        set("gender", "�k��" );
        set("age", 14);
        set("long","�o�O�@����o�D�`�i�R���p�k�ġA�����ۭ��x�l�A�b�u��s��۪F��C\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "�p�G��");
        set("sell_list",([
            "/u/t/tmr/game/2006_c/order": 1, // 2006�t�Ϭ���
            "/u/t/tmr/game/2006_c/cannon1": 1, // 2006�t�Ϭ���
            "/u/t/tmr/game/2006_c/cannon2": 1, // 2006�t�Ϭ���
            "/u/t/tmr/game/2006_c/cannon3": 1, // 2006�t�Ϭ���
                "/u/t/tmr/game/2006_c/cannon0": 3, // 2006�t�Ϭ���
                 "/u/t/tmr/game/2006_c/cannon00": 100, // 2006�t�Ϭ���

       ]) );
        set("no_kill",1);
        setup();
        carry_object(__DIR__"eq/hat")->wear();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/gloves")->wear();
        carry_object(__DIR__"eq/boots")->wear();
        carry_object(__DIR__"eq/beard")->wear();
        carry_object(__DIR__"eq/waist")->wear();
        carry_object(__DIR__"eq/pants")->wear();
}


void init()
{       
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}


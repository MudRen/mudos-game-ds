#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "狂暴野人", ({ "redhair crazy wildman","wildman","man"}) );
        set("long",@long
　　這是一頭紅髮的野人，似乎是這片森林的原居民。瞧他長的孔武有力，
正惡狠狠地瞪著你，似乎對你的存在有著相當大的反感。但是這野人顯得情緒
異常的亢憤，而且眼神兇狠，不停地擦拳磨掌。
long
);
        set_race("human");
        set("title","紅髮");
        set("age", 25);
        set("attitude", "aggressive");
        set_attr("str",30);
        set_skill("blunt",80);                  // 棒法
        set_skill("twohanded blunt",60);        // 雙握棒法
        set_skill("parry",50);
        set_attr("strength",20);
        setup();
        set_level(15);
        advance_stat("hp",300);
        do_heal();
        carry_object("/d/obj/woodblunt")->wield();
		carry_object(__DIR__"obj/monster_pants")->wear();
}


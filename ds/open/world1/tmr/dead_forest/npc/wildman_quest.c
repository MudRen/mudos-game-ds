#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "鬼鬼崇崇的野人", ({ "redhair wildman","wildman","man"}) );
        set("long",@long
　　這是一頭紅髮的野人，似乎是這片森林的原居民。瞧他長的孔武有力，
正惡狠狠地瞪著你，似乎對你的存在有著相當大的反感。你還注意到他竟不經
意地露出微笑，不知在幻想著什麼。
long
);
        set_race("human");
        set("title","紅髮");
        set("age", 25);
        set_attr("str",30);
        set_skill("blunt",80);                  // 棒法
        set_skill("twohanded blunt",60);        // 雙握棒法

        set_skill("parry",50);
        setup();
        set_level(10);
        carry_object("/d/obj/woodblunt")->wield();
        carry_object(__DIR__"obj/monster_pants")->wear();
        // 火紅之眼
        carry_object(__DIR__"obj/fire-eye");
}


#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("唐先生" , ({ "boss" }));
        set("long",@LONG
  眼前是一位相當帥氣的中年人，衣著相當的整齊乾淨。
  一點也不像是一位鐵匠。
        ==========================
        武器清單        list
        購買武器        buy <武器>
        試用武器        try <武器>
        ==========================
LONG);
        set("race","human");
        set("gender","男性");

        set("sell_list",([
  __DIR__"wp/steel_axe_25" : 5,
  __DIR__"wp/steel_ball_14" : 5,
  __DIR__"wp/steel_blade_20" : 5,
  __DIR__"wp/steel_dagger_15" : 5,
  __DIR__"wp/steel_fist_20" : 5,
  __DIR__"wp/steel_fork_22" : 5,
  __DIR__"wp/steel_hammer_24" : 5,
  __DIR__"wp/steel_staff_18" : 5,
  __DIR__"wp/steel_sword_19" : 5,
  __DIR__"wp/steel_whip_16" : 5,
]));
        set("age",25);
        set("level",20);
        set("no_fight",1);
        setup();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_try","try");
}


#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�����" , ({ "boss" }));
        set("long",@LONG
  ���e�O�@��۷�Ӯ𪺤��~�H�A��۬۷�������b�C
  �@�I�]�����O�@���K�K�C
        ==========================
        �Z���M��        list
        �ʶR�Z��        buy <�Z��>
        �եΪZ��        try <�Z��>
        ==========================
LONG);
        set("race","human");
        set("gender","�k��");

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


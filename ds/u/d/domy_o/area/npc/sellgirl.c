inherit NPC;
inherit SELLMAN;

void create()
{
        set_name( "����Ϋ~���p�j", ({ "sellgirl" }) );
        set("gender", "�k��" );
        set("level",40);
        set("age", 22);
        set("long",
                "�@�Ө����������p�j�M���ݵ����x�C\n"
                "�p�G�A�Q�R�@�Ǳ���Ϋ~�M�i�H�� list �ݦ����ǪF��M�A buy �C\n"
        );
        set("combat_exp", 5);
        set("attitude", "friendly");
      set("sell_list",([      
                 __DIR__"ep/candom"        : 1000, 
                 __DIR__"ep/sm_armor"   : 1500, 
                 __DIR__"wp/sm_whip"     : 1800, 
                 __DIR__"item/blue_pill"       : 300,         
                       ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}


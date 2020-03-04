inherit NPC;
inherit SELLMAN;

void create()
{
        set_name( "�K�K�Ǯ{", ({ "trainer" }) );
        set("gender", "�k��" );
        set("level",10);
        set("age", 22);
        set("long",
                "�@�ӥ��b�V�O�ǲߪ��K�K�Ǯ{�C\n"
                "�p�G�A�Q�R�@���K���M�i�H�� list �ݦ����ǪF��M�� buy �ʶR�C\n"
        );
        set("combat_exp", 5000);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                "�K�K�Ǯ{��@���N���K����J�����N�o�C\n",
                "�K�K�Ǯ{�Τ⤤���K��b�K�z�W�ΤO�V���C\n",
                "�K�K�Ǯ{���D�R�p���I�A�O�Q�h�ۤF�C\n",
                "�K�K�Ǯ{���D�R�I���Ʊ�ভ�I�Ǩ�v�Ū�����C\n",
        }));
set("sell_list",([      
                 __DIR__"wp/woodbow"        : 5, 
                 __DIR__"wp/small-hammer"   : 5, 
"/open/world1/tmr/area/npc/wp/shortsword"   : 5, 
"/open/world1/tmr/area/npc/wp/shortaxe"     : 5,         
"/open/world1/tmr/area/npc/wp/fork"         : 5,     
"/open/world1/kkeenn/love/npc/obj/whip1"    : 5,     
                 __DIR__"wp/small-blade"    : 5,        
                ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}





